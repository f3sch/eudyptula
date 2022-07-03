/**
 * @file
 * @author Felix Schlepper
 * @brief Hello, world from Linux Kernel.
 */

#include <linux/debugfs.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <linux/string.h>
#include <linux/kobject.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Felix Schlepper");
MODULE_DESCRIPTION("Challenge 09 - Hello, world!");
MODULE_VERSION("1.0");

#define YOUR_ID_LEN 10
static char name_buf[YOUR_ID_LEN] =
	"Eudyptula"; // I don't have an id, just using this
static DEFINE_MUTEX(foo_sem);
static char fmsg[PAGE_SIZE];

static ssize_t id_show(struct kobject *kobj, struct kobj_attribute *attr,
		       char *buf)
{
	strncpy(buf, name_buf, YOUR_ID_LEN);

	return YOUR_ID_LEN;
}

static ssize_t id_store(struct kobject *kobj, struct kobj_attribute *attr,
			const char *buf, size_t count)
{
	if (YOUR_ID_LEN != count)
		return -EINVAL;

	if (strncmp(buf, name_buf, YOUR_ID_LEN) != 0)
		return -EINVAL;

	strncpy(name_buf, buf, YOUR_ID_LEN);

	return count;
}

static struct kobj_attribute id_attr = __ATTR(id, 0664, id_show, id_store);

static ssize_t jiffies_show(struct kobject *kobj, struct kobj_attribute *attr,
			    char *buf)
{
	return sprintf(buf, "%lu\n", jiffies);
}

static struct kobj_attribute jiffies_attr = __ATTR_RO(jiffies);

static ssize_t foo_store(struct kobject *kobj, struct kobj_attribute *attr,
			 const char *buf, size_t count)
{
	if (count > PAGE_SIZE)
		return -EINVAL;

	mutex_lock(&foo_sem);
	strncpy(fmsg, buf, count);
	mutex_unlock(&foo_sem);

	return count;
}

static ssize_t foo_show(struct kobject *kobj, struct kobj_attribute *attr,
			char *buf)
{
	ssize_t len;

	mutex_lock(&foo_sem);
	len = strlen(fmsg);
	strncpy(buf, fmsg, len);
	mutex_unlock(&foo_sem);

	return len;
}

static struct kobj_attribute foo_attr = __ATTR_RW(foo);

static struct attribute *attrs[] = {
	&foo_attr.attr,
	&id_attr.attr,
	&jiffies_attr.attr,
	NULL,
};

static struct attribute_group eudyptula_attr = {
	.attrs = attrs,
};

static struct kobject *eudyptula;

static int __init start(void)
{
	int retval;

	eudyptula = kobject_create_and_add("eudyptula", kernel_kobj);
	if (!eudyptula)
		return -ENOMEM;

	retval = sysfs_create_group(eudyptula, &eudyptula_attr);
	if (retval)
		kobject_put(eudyptula);

	pr_debug("Eudyptula: Hello!");

	return retval;
}

static void __exit end(void)
{
	kobject_put(eudyptula);
	pr_debug("Eudyptula: Bye!");
}

module_init(start);
module_exit(end);
