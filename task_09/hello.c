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

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Felix Schlepper");
MODULE_DESCRIPTION("Challenge 09 - Hello, world!");
MODULE_VERSION("1.0");

#define YOUR_ID_LEN 10
static char name_buf[YOUR_ID_LEN] =
	"Eudyptula"; // I don't have an id, just using this
static struct dentry *dbgfs; // global parent
static char jbuf[sizeof(jiffies)];
static DEFINE_MUTEX(foo_sem);
static char fmsg[PAGE_SIZE];

static ssize_t eduyptula_write(struct file *file, const char __user *buf,
			       size_t len, loff_t *ppos)
{
	char ebuf[YOUR_ID_LEN];

	simple_write_to_buffer(ebuf, len, ppos, buf, len);

	// cmp strings
	for (int i = 0; i < YOUR_ID_LEN; ++i) {
		if (name_buf[i] != ebuf[i]) {
			pr_debug("Eduyptula: Write: %s did not match %s!\n",
				 ebuf, name_buf);
			return -EINVAL;
		}
	}

	return len;
}

static ssize_t eduyptula_read(struct file *file, char __user *buf, size_t len,
			      loff_t *ppos)
{
	return simple_read_from_buffer(buf, len, ppos, name_buf, YOUR_ID_LEN);
}

static const struct file_operations efops = {
	.owner = THIS_MODULE,
	.write = eduyptula_write,
	.read = eduyptula_read,
};

static ssize_t jiffies_write(struct file *file, const char __user *buf,
			     size_t len, loff_t *ppos)
{
	return 0;
}

static ssize_t jiffies_read(struct file *file, char __user *buf, size_t len,
			    loff_t *ppos)
{
	sprintf(jbuf, "%lu", jiffies);
	return simple_read_from_buffer(buf, len, ppos, jbuf, sizeof(jiffies));
}

static const struct file_operations jfops = {
	.owner = THIS_MODULE,
	.write = jiffies_write,
	.read = jiffies_read,
};

static ssize_t foo_write(struct file *file, const char __user *buf, size_t count,
			 loff_t *ppos)
{
	ssize_t len;

	mutex_lock(&foo_sem);

	len = simple_write_to_buffer(fmsg, PAGE_SIZE, ppos, buf, count);

	mutex_unlock(&foo_sem);

	return len;
}

static ssize_t foo_read(struct file *file, char __user *buf, size_t len,
			loff_t *ppos)
{
	int ret = -EINVAL;

	mutex_lock(&foo_sem);

	ret = simple_read_from_buffer(buf, len, ppos, fmsg, strlen(fmsg));

	mutex_unlock(&foo_sem);

	return ret;
}

static const struct file_operations ffops = {
	.owner = THIS_MODULE,
	.write = foo_write,
	.read = foo_read,
};

static int __init start(void)
{
	struct dentry *id, *jif, *foo;
	dbgfs = debugfs_create_dir("eudyptula", NULL);
	if (!dbgfs) {
		pr_err("Could not create debugfs dir!\n");
		return -ENODEV;
	}

	id = debugfs_create_file("id", S_IRWXU, dbgfs, (void *)name_buf,
				 &efops);
	if (!id) {
		pr_err("Could not create id file!\n");
		goto err_id;
	}

	jif = debugfs_create_file("jiffies", S_IRUSR | S_IROTH, dbgfs,
				  (void *)jbuf, &jfops);
	if (!jif) {
		pr_err("Could not create id file!\n");
		goto err_id;
	}

	foo = debugfs_create_file("foo", S_IRUSR | S_IROTH, dbgfs, NULL, &ffops);
	if (!jif) {
		pr_err("Could not create id file!\n");
		goto err_id;
	}

	return 0;

err_id:
	debugfs_remove_recursive(dbgfs);
	return -ENODEV;
}

static void __exit end(void)
{
	debugfs_remove_recursive(dbgfs);
}

module_init(start);
module_exit(end);
