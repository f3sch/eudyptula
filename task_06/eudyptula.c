#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>

#define YOUR_ID_LEN 10
const static char name_buf[YOUR_ID_LEN] =
	"Eudyptula"; // I don't have an id, just using this

static int eduyptula_open(struct inode *inode, struct file *file)
{
	return 0;
}

static int eduyptula_close(struct inode *inode, struct file *file)
{
	return 0;
}

static ssize_t eduyptula_write(struct file *file, const char __user *buf,
			       size_t len, loff_t *ppos)
{
	char ebuf[YOUR_ID_LEN];

	if (YOUR_ID_LEN != len) {
		pr_debug("Eduyptula: Write: len not right!\n");
		return -EINVAL;
	}

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

	if (YOUR_ID_LEN != len) {
		pr_debug("Eduyptula: Read: len not right!\n");
		return -EINVAL;
	}

	if (copy_to_user(buf, name_buf, YOUR_ID_LEN)) {
		pr_debug("Eduyptula: Read: Could not copy to user space!\n");
		return -EFAULT;
	}

	return YOUR_ID_LEN;
}

static struct file_operations fops = {
	.owner = THIS_MODULE,
	.write = eduyptula_write,
	.read = eduyptula_read,
	.release = eduyptula_close,
	.open = eduyptula_open,
	.llseek = no_llseek,
};

static struct miscdevice eudyptula = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "eudyptula",
	.fops = &fops,
};

static int __init start(void)
{
	int err;

	err = misc_register(&eudyptula);
	if (err) {
		pr_err("Eudyptula: Failed to register misc device driver!\n");
		return err;
	}
	pr_info("Eudyptula: Register misc device driver!\n");
	return 0;
}

static void __exit end(void)
{
	misc_deregister(&eudyptula);
	pr_info("Eudyptula: Deregister misc device driver!\n");
}

module_init(start);
module_exit(end);

MODULE_LICENSE("Dual MIT/GPL");
MODULE_AUTHOR("Felix Schlepper");
MODULE_DESCRIPTION("Challenge 06 - Misc Device!");
MODULE_VERSION("1.0");
