# This is Task 02 of the Eudyptula Challenge
--------------------------------------------

Now that you have written your first kernel module, it's time to take
off the training wheels and move on to building a custom kernel.  No
more distro kernels for you.  For this task you must run your own
kernel.  And use git!  Exciting, isn't it?  No?  Oh, ok...

The tasks for this round are:
  - Download Linus's latest git tree from git.kernel.org (you have to
    figure out which one is his.  It's not that hard, just remember what
    his last name is and you should be fine.)
  - Build it, install it, and boot it.  You can use whatever kernel
    configuration options you wish to use, but you must enable
    CONFIG_LOCALVERSION_AUTO=y.
  - Show proof of booting this kernel.  Bonus points if you do it on a
    "real" machine, and not a virtual machine (virtual machines are
    acceptable, but come on, real kernel developers don't mess around
    with virtual machines, they are too slow.  Oh yeah, we aren't real
    kernel developers just yet.  Well, I'm not anyway, I'm just a
    script...)  Again, proof of running this kernel is up to you, I'm
    sure you can do well.

Hint, you should look into the 'make localmodconfig' option, and base
your kernel configuration on a working distro kernel configuration.
Don't sit there and answer all 1625 different kernel configuration
options by hand, even I, a foolish script, know better than to do that!

After doing this, don't throw away that kernel, git tree, and
configuration file.  You'll be using it for later tasks.  A working
kernel configuration file is a precious thing, all kernel developers
have one they have grown and tended to over the years.  This is the
start of a long journey with yours.  Don't discard it like was a broken
umbrella, it deserves better than that.

Remember to use your ID assigned in the subject line when responding to
this task, so that I can figure out who to attribute it to.

If you forgot, your id is "YOUR_ID".  But why do I repeat myself?
Of course you know your id, you made it through the first task just fine
with it.


# Solution
----------
<details>
<summary>Notes:</summary>
<br>

Compiled on ubuntu 20.04
```bash
sudo apt-get install fakeroot build-essential crash kexec-tools makedumpfile kernel-wedge libssl-dev
sudo apt-get install git libncurses5 libncurses5-dev libelf-dev asciidoc binutils-dev flex bison
sudo apt-get build-dep linux
git clone https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/
cd linux
make localmodconfig
scripts/config --disable DEBUG_INFO
scripts/config --disable DEBUG_INFO_BTF
scripts/config --disable SYSTEM_TRUSTED_KEYS
scripts/config --set-str SYSTEM_TRUSTED_KEYS ""
scripts/config --disable LOCALVERSION_AUTO          # <- Challenge requirement!!!
make $(nproc)
make install
update-initramfs -c -k KERNEL_VERSION
update-grub
reboot
```


</details>
