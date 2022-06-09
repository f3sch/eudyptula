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

static int __init start(void)
{
	printk(KERN_INFO "Hello, world!\n");
	return 0;
}

static void __exit end(void)
{
	printk(KERN_INFO "Goodbye, cruel world!\n");
}

module_init(start);
module_exit(end);
