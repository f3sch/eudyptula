# This is Task 05 of the Eudyptula Challenge
--------------------------------------------

Yeah, you survived the coding style mess!  Now, on to some "real"
things, as I know you are getting bored by these so far.

So, two simple tasks this time around:
  - Take the kernel module you wrote for task 01, and modify it so that
    when any USB keyboard is plugged in, the module will be
    automatically loaded by the correct userspace hotplug tools (which
    are implemented by depmod / kmod / udev / mdev / systemd, depending
    on what distro you are using.)
  - Again, provide "proof" this all works.

Yes, so simple, and yet, it's a bit tricky.  As a hint, go read chapter
14 of the book, "Linux Device Drivers, 3rd edition."  Don't worry, it's
free, and online, no need to go buy anything.

As always, please remember to use your ID, yadda yadda yadda...
It's "YOUR_ID" of course.

# Solution
----------
<details>
<summary>Notes:</summary>
<br>

I was surprised how well this worked!
Note: You have to find out the Vendorid and Productid of the usb stick, you are using (used dmesg).
``` bash
[73839.243778] Hello, world!
[73839.243812] usbcore: registered new interface driver HelloUSB
[73844.375507] usb 1-1: new high-speed USB device number 9 using xhci_hcd
[73844.527923] usb 1-1: New USB device found, idVendor=0781, idProduct=557d, bcdDevice= 1.27
[73844.527938] usb 1-1: New USB device strings: Mfr=1, Product=2, SerialNumber=3
[73844.527946] usb 1-1: Product: Cruzer Force
[73844.527951] usb 1-1: Manufacturer: SanDisk
[73844.527956] usb 1-1: SerialNumber: 4C530013100123107405
[73844.530664] USB Stick connected!
[73846.021018] usb 1-1: USB disconnect, device number 9
[73846.021150] USB Stick disconnected!
[73852.244185] Goodbye, cruel world!
[73852.244188] usbcore: deregistering interface driver HelloUSB
```

</details>
