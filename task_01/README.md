# This is Task 01 of the Eudyptula Challenge
--------------------------------------------

Write a Linux kernel module, and stand-alone Makefile, that when loaded
prints to the kernel debug log level, "Hello World!"  Be sure to make
the module able to be unloaded as well.

The Makefile should be able to build the kernel module against the
source of the currently-running kernel as well as being able to accept
an arbitrary kernel sources directory from an environment variable.

Please show proof of this module building, and running, in your
kernel.  What this proof is up to you.  I'm sure you can come up with
something.  Also be sure to send the kernel module you wrote, along with
the Makefile you created to build the module.

Remember to use your ID assigned in the Subject: line when responding to
this task, so that I can figure out who to attribute it to.  You can
just respond to the task with the answers and all should be fine.

If you forgot, your id is "YOUR_ID".  But of course you have not
forgotten that yet, you are better than that.

# Solution
----------
<details>
<summary>Notes:</summary>
<br>

There are some basic information the kernel requires before loading the module:
```c
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Name");
MODULE_DESCRIPTION("Description");
MODULE_VERSION("1.0");
```

Next are the entry and exit macros, which point to specific functions:
```c
module_init(...);
module_exit(...);
```

Notes use these to insert the module into the kernel. (This taints the kernel.)
```
sudo insmod hello.ko
sudo rmmod hello
```


</details>
