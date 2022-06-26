/**
 * @file
 * @author Felix Schlepper
 * @brief Hello, world from Linux Kernel.
 */

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Felix Schlepper");
MODULE_DESCRIPTION("Challenge 01 - Hello, world!");
MODULE_VERSION("1.0");

#define YOUR_ID_LEN 10
const static char name_buf[YOUR_ID_LEN] =
	"Eudyptula"; // I don't have an id, just using this
static struct dentry *dbgfs; // global parent

static ssize_t eduyptula_write(struct file *file, const char __user *buf,
			       size_t len, loff_t *ppos)
{
	char ebuf[YOUR_ID_LEN];

	if (copy_from_user(ebuf, buf, len)) {
		pr_debug("Eduyptula: Write: Could not copy from user space!\n");
		return -EFAULT;
	}

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
	if (copy_to_user(buf, name_buf, YOUR_ID_LEN)) {
		pr_debug("Eduyptula: Read: Could not copy to user space!\n");
		return -EFAULT;
	}

	return YOUR_ID_LEN;
}

static const struct file_operations fops = {
	.owner = THIS_MODULE,
	.write = eduyptula_write,
	.read = eduyptula_read,
};

static int __init start(void)
{
	pr_debug("Hello, world!\n");
	return 0;
}

static void __exit end(void)
{
	pr_debug("Goodbye, cruel world!\n");
}

module_init(start);
module_exit(end);
