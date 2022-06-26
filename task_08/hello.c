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
	pr_debug("Hello, world!\n");
	return 0;
}

static void __exit end(void)
{
	pr_debug("Goodbye, cruel world!\n");
}

module_init(start);
module_exit(end);
