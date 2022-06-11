#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/slab.h>
#include <linux/init.h>

int do_work(int *my_int, int retval)
{
	int x;
	int y = *my_int;
	int z;

	for (x = 0; x < *my_int; ++x) {
		udelay(10);
	}

	if (y < 10)
		// That was a long sleep, tell userspace about it
		printk("We slept a long time!");

	z = x * y;

	return z;
}

int my_init(void)
{
	int x = 10;

	x = do_work(&x, x);

	return x;
}

void my_exit(void)
{
	return;
}

module_init(my_init);
module_exit(my_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Eudyptula");
MODULE_DESCRIPTION("Challenge 04 - Coding Style");
MODULE_VERSION("1.0");
