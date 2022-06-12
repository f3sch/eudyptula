/**
 * @file
 * @author Felix Schlepper
 * @brief Hello, world from Linux Kernel.
 */

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/usb.h>

#define VENDOR_ID 0x0781 // specific to my case
#define PRODUCT_ID 0x557d

static int __init start(void);
static void __exit end(void);
static int probe(struct usb_interface *iface, const struct usb_device_id *id);
static void disconnect(struct usb_interface *iface);

// Device id table
static const struct usb_device_id id_table[] = {
	{ USB_DEVICE(VENDOR_ID, PRODUCT_ID) },
	{}, /* end with an all-zeroes entry */
};

// Information about the 'driver' we are providing
static struct usb_driver usb_hello = {
	.name = "HelloUSB",
	.id_table = id_table,
	.probe = probe,
	.disconnect = disconnect,
};
// Register this new driver as an usb one
MODULE_DEVICE_TABLE(usb, id_table);
// Register entry and exit functions
module_init(start);
module_exit(end);
// Licensing and authorship
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Felix Schlepper");
MODULE_DESCRIPTION("Challenge 01 - Hello, world!");
MODULE_VERSION("1.0");

static int __init start(void)
{
	pr_debug("Hello, world!\n");
	return usb_register(&usb_hello);
}

static void __exit end(void)
{
	pr_debug("Goodbye, cruel world!\n");
	usb_deregister(&usb_hello);
}

static int probe(struct usb_interface *iface, const struct usb_device_id *id)
{
	pr_debug("USB Stick connected!\n");
	return 0;
}

static void disconnect(struct usb_interface *iface)
{
	pr_debug("USB Stick disconnected!\n");
}
