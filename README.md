# The Eudyptula Challenge
#Instructions
Welcome to the Eudyptula Challenge!

This "challenge" is a series of Linux kernel programming exercises
starting out small, and in the end, if all goes well, you'll be the
maintainer of a subsystem, if you so desire.  Well, maybe not a
maintainer, but you will be qualified enough to point out any problems
that your favorite maintainer is causing, and that's actually way more
fun than being in charge.

All of these tasks will be done through email, and will require you to
write, modify, and submit Linux kernel patches and code of all different
types.

First off, some housekeeping rules.

You have been assigned a "unique" id.  This id is required when
submitting your results, as I (a dumb script) need some way to determine
what is going on.  So, please, for every email you write to me from now
on, use your id in the Subject: line like this:

    [YOUR_ID] Task 02 results

And yes, if you haven't guessed it already, "YOUR_ID" is your
unique id.  Please don't lose it.  I can, through some difficulty,
figure it out again, but we really don't want to have to get my human
involved in this process, that only slows things down.

You should be able to just hit "reply" on the task email and all should
be fine, if not, the scripts will notify you.

Always send submissions in from this email address, the one that you
signed up with, emails from any other address will be silently
discarded.  If you need to change email addresses in the future, just
email me and tell me your existing id (YOUR_ID), your original
email address, and your new email address, and it will be changed.

When you submit a task, you will receive an autoresponse saying where
you are in the queue.  If you do not receive this autoresponse, I have
not received your task, something went wrong, and it needs to be resent.

Secondly, no HTML email, or base64-mime attachments.  If you have made
it this far, you have successfully sent a non-HTML email, which is
wonderful (kids these days...), but for all tasks you can't send base64
attachments, as I don't know what to do with them.  Just a "normal"
attachment, in text form, is fine, and preferred.  If you have problems
with this, please consult your email client's documentation on how to do
this.

Thirdly, don't use Gmail or Microsoft Exchange for this set of tasks.
Yes, it can be done, but it's really hard, and you really have to know
what you are doing.  If you get back "I can't understand this response,
please try again" message, you might want to switch to a different email
client / server and try it again, and notify me of your email address
change.  Ah, now you see why you use an id and not an email address, we
didn't just fall off of the turnip truck yesterday.

Fourthly, this challenge is meant to be done over a period of time.
Don't rush things, there's no hurry, I'm not going anywhere, and neither
are you.  So sit back, take your time, and enjoy the process.  Life is
about the journey, not the end result, as that's the same for everyone.

Responses to submissions can sometimes take a few days, or weeks, or
they can be a few minutes, depending on the load of the system.  There
are many thousands of people currently taking this challenge and the
scripts get easily backlogged at times.  If you ever feel that you
missed an email, just ask, and research will be done to see what
happened.  Sometimes new task emails do get delayed, but it should only
be an hour or so, never more than a day to get a new task once you have
completed one.  If you have not received a new task within a day of a
task being marked as completed, please send a reminder email to find out
what went wrong.

Fifth, as stated on the challenge's home page, please do your work on
your own.  A number of participants have, in the past, posted the
answers to the tasks on github and other public code sites.  This
instantly caused their solutions to be copied and submitted as answers
from other people.  I'm sure you don't want to have others copy your
hard work.  Doing these challenges does not mean you cannot research and
try to find out how to do the tasks from existing kernel code and
documentation.  You are expected to do that.  When you do copy code or
scripts, please be sure to properly attribute where you copied it from,
otherwise I am going to just assume you are trying to pass it off as
your own work, which is not a good thing at all.

If you are found to have posted your code publicly, or asked for help in
public locations, or copied code from public locations without properly
attributing it, or tried to cheat or fake challenge results in any way,
you will be removed from the challenge instantly.  In short, do your own
work, and keep it to yourself.

Finally, if you have any questions about a task, or need help with
something, feel free to ask.  I'll alert my human that something is
going on, and they will get back to you in a few days with answers.

Expect a follow-on email from this with your first task.  Responses to
tasks might take a few days, depending on the load on my system, and any
nasty bugs that show up.  Remember the fourth point again, you'll need
to keep that in mind during this.

As the Big Penguin says, "Have fun!"




This is Task 10 of the Eudyptula Challenge
------------------------------------------

Yeah, you conquered the sysfs monster, great job!

Now you know you'll never want to mess with a kobject again, right?
Trust me, there are easier ways to create sysfs files, and we will get
into that for a future task, but for now, let's make it a bit more
simple after all of that coding.

For these tasks, go back to the linux-next tree you used for task 07.
Update it, and then do the following:
  - Create a patch that fixes one coding style problem in any of the
    files in drivers/staging/
  - Make sure the patch is correct by running it through
    scripts/checkpatch.pl
  - Submit the code to the maintainer of the driver/subsystem, finding
    the proper name and mailing lists to send it to by running the tool,
    scripts/get_maintainer.pl on your patch.
  - Get the patch accepted into the subsystem maintainers git tree.
  - Send a web link back to me of your patch in the public mailing list
    archive (don't cc: me on the patch, that will only confuse me and
    everyone in the kernel development community) as well as a pointer
    to the git commit of your patch in the subsystem tree.

Hopefully this patch will be accepted into the kernel tree, and all of a
sudden, you are an "official" kernel developer!

Don't worry, there's plenty more tasks coming, but a little breather
every now and again for something simple is always nice to have.

This is Task 11 of the Eudyptula Challenge
------------------------------------------

You made a successful patch to the kernel source tree, that's a great
step!

But, let's not rest, time to get back to code.

Remember that mess of kobject and sysfs code back in task 09?  Let's
move one level up the tree and start to mess with devices and not raw
kobjects.

For this task:
  - Write a patch against any driver that you are currently using on
    your machine.  So first you have to figure out which drivers you are
    using, and where the source code in the kernel tree is for that
    driver.
  - In that driver, add a sysfs file to show up in the /sys/devices/
    tree for the device that is called "id".  As you might expect, this
    file follows the same rules as task 09 as for what you can read and
    write to it.
  - The file is to show up only for devices that are controlled by a
    single driver, not for all devices of a single type (like all USB
    devices.  But all USB mailbox LEDs would be acceptable, if you
    happen to have the device that that driver controls.)

Submit both the patch, in proper kernel commit form, and "proof" of it
working properly on your machine.

And as always, please use your id in the subject line.  If you happened
to forget it, as it has been a while since I reminded you of it, it is
"YOUR_ID".

This is Task 12 of the Eudyptula Challenge
------------------------------------------

Nice job with the driver patch.  That took some work in finding the
proper place to modify, and demonstrates a great skill in tracking down
issues when you can't get a specific piece of hardware working.

Now let's step back from drivers (they are boring things), and focus on
the kernel core.  To do that, we need to go way back to the basics --
stuff you would learn in your "intro to data structures" class, if you
happened to take one.

Yes, I'm talking about linked lists.

The kernel has a unique way of creating and handling linked lists, that
is quite different than the "textbook" way of doing so.  But, it turns
out to be faster, and simpler, than a "textbook" would describe, so
that's a good thing.

For this task, write a kernel module, based on your cleaned up one from
task 04, that does the following:
  - You have a structure that has 3 fields:
        char  name[20];
        int   id;
        bool  busy;
    name this structure "identity".
  - Your module has a static variable that points to a list of these
    "identity" structures.
  - Write a function that looks like:
        int identity_create(char *name, int id)
    that creates the structure "identity", copies in the 'name' and 'id'
    fields and sets 'busy' to false.  Proper error checking for out of
    memory issues is required.  Return 0 if everything went ok; an error
    value if something went wrong.
  - Write a function that looks like:
        struct identity *identity_find(int id);
    that takes a given id, iterates over the list of all ids, and
    returns the proper 'struct identity' associated with it.  If the
    identity is not found, return NULL.
  - Write a function that looks like:
        void identity_destroy(int id);
    that given an id, finds the proper 'struct identity' and removes it
    from the system.
  - Your module_init() function will look much like the following:

        struct identity *temp;

        identity_create("Alice", 1);
        identity_create("Bob", 2);
        identity_create("Dave", 3);
        identity_create("Gena", 10);

        temp = identity_find(3);
        pr_debug("id 3 = %s\n", temp->name);

        temp = identity_find(42);
        if (temp == NULL)
                pr_debug("id 42 not found\n");

        identity_destroy(2);
        identity_destroy(1);
        identity_destroy(10);
        identity_destroy(42);
        identity_destroy(3);

   Bonus points for properly checking return values of the above
   functions.

As always, please send the full module (following the proper kernel
coding style rules), and "proof" of it working properly.  And remember
to use your id of "YOUR_ID" in the Subject line properly.

This is Task 13 of the Eudyptula Challenge
------------------------------------------

Weren't those lists fun to play with?  You should get used to them, they
are used all over the kernel in lots of different places.

Now that we are allocating a structure that we want to use a lot of, we
might want to start caring about the speed of the allocation, and not
have to worry about the creation of those objects from the "general"
memory pools of the kernel.

This task is to take the code written in task 12, and cause all memory
allocated from the 'struct identity' to come from a private slab cache
just for the fun of it.

Instead of using kmalloc() and kfree() in the module, use
kmem_cache_alloc() and kmem_cache_free() instead.  Of course this means
you will have to initialize your memory cache properly when the module
starts up.  Don't forget to do that.  You are free to name your memory
cache whatever you wish, but it should show up in the /proc/slabinfo
file.

Don't send the full module for this task, only a patch with the diff
from task 12 showing the lines changed.  This means you will have to
keep a copy of your 12 task results somewhere to make sure you don't
overwrite them.

Also show the output of /proc/slabinfo with your module loaded.

This is Task 14 of the Eudyptula Challenge
------------------------------------------

Now that you have the basics of lists, and we glossed over the custom
allocators (the first cut at that task was much harder, you got off
easy), it's time to move on to something a bit more old-school: tasks.

For this task:
  - Add a new field to the core kernel task structure called, wait for
    it, "id".
  - When the task is created, set the id to your id.  Imaginative, I
    know.  You try writing these tasks.
  - Add a new proc file for every task called, "id", located in the
    /proc/${PID}/ directory for that task.
  - When the proc file is read from, have it print out the value of
    your id, and then increment it by one, allowing different tasks to
    have different values for the "id" file over time as they are read
    from.
  - Provide some "proof" it all works properly.

As you are touching files all over the kernel tree, a patch is the
required result to be sent in here.  Please specify which kernel version
you make this patch against, to give my virtual machines a chance to
figure out how to apply it.

Also provide some kind of proof that you tested the patch.

And, in case you happened to forget it, your id is "YOUR_ID".

This is Task 15 of the Eudyptula Challenge
------------------------------------------

That process task turned out to not be all that complex, but digging
through the core kernel was a tough task, nice work with that.

Speaking of "core kernel" tasks, let's do another one.  It's one of the
most common undergraduate tasks there is: create a new syscall!
Yeah, loads of fun, but it's good to know the basics of how to do this,
and, how to call it from userspace.

For this task:
  - Add a new syscall to the kernel called "sys_eudyptula", so this is
    all going to be changes to the kernel tree itself, no stand-alone
    module needed for this task (unless you want to do it that way
    without hacking around the syscall table, if so, bonus points for
    you...)
  - The syscall number needs to be the next syscall number for the
    architecture you test it on (some of you all are doing this on ARM
    systems, showoffs, and syscall numbers are not the same across all
    architectures).  Document the arch you are using and why you picked
    this number in the module.
  - The syscall should take two parameters: int high_id, int low_id.
  - The syscall will take the two values, mush them together into one
    64bit value (low_id being the lower 32bits of the id, high_id being
    the upper 32bits of the id).
  - If the id value matches your id (which of course you know as
    "a24a6bdd6a14", then the syscall returns success.  Otherwise it
    returns a return code signifying an invalid value was passed to it.
  - Write a userspace C program that calls the syscall and properly
    exercises it (valid and invalid calls need to be made).
  - "Proof" of running the code needs to be provided.

So you need to send in a .c userspace program, a kernel patch, and
"proof" that it all works, as a response.


This is Task 16 of the Eudyptula Challenge
------------------------------------------

Good job with the new syscall.  The odds of you ever having to write a
new syscall is pretty rare, but now you know where to look them up, and
what the code involved in creating one looks like, which is useful when
you try to debug things.

Let's take a breather after all of that code, and go back to doing a bit
of reading, and learn some more about some common kernel tools.

Go install the tool 'sparse'.  It was started by Linus as a
static-analysis tool that acts much like a compiler.  The kernel build
system is set up to have it run if you ask it to, and it will report a
bunch of issues in C code that are really specific to the kernel.

When you build the kernel, pass the "C=1" option to the build, to have
sparse run on the .c file before gcc is run.  Depending on the file,
nothing might be printed out, or something might.  Here's an example of
it being run on the ext4 code:

$ make C=1 M=fs/ext4
  CHECK   fs/ext4/balloc.c
  CC      fs/ext4/balloc.o
  CHECK   fs/ext4/bitmap.c
  CC      fs/ext4/bitmap.o
  CHECK   fs/ext4/dir.c
  CC      fs/ext4/dir.o
  CHECK   fs/ext4/file.c
  CC      fs/ext4/file.o
  CHECK   fs/ext4/fsync.c
  CC      fs/ext4/fsync.o
  CHECK   fs/ext4/ialloc.c
  CC      fs/ext4/ialloc.o
  CHECK   fs/ext4/inode.c
  CC      fs/ext4/inode.o
  CHECK   fs/ext4/page-io.c
  CC      fs/ext4/page-io.o
  CHECK   fs/ext4/ioctl.c
  CC      fs/ext4/ioctl.o
  CHECK   fs/ext4/namei.c
  CC      fs/ext4/namei.o
  CHECK   fs/ext4/super.c
  CC      fs/ext4/super.o
  CHECK   fs/ext4/symlink.c
  CC      fs/ext4/symlink.o
  CHECK   fs/ext4/hash.c
  CC      fs/ext4/hash.o
  CHECK   fs/ext4/resize.c
  CC      fs/ext4/resize.o
  CHECK   fs/ext4/extents.c
  CC      fs/ext4/extents.o
  CHECK   fs/ext4/ext4_jbd2.c
  CC      fs/ext4/ext4_jbd2.o
  CHECK   fs/ext4/migrate.c
  CC      fs/ext4/migrate.o
  CHECK   fs/ext4/mballoc.c
fs/ext4/mballoc.c:5018:9: warning: context imbalance in 'ext4_trim_extent' - unexpected unlock
  CC      fs/ext4/mballoc.o
  CHECK   fs/ext4/block_validity.c
  CC      fs/ext4/block_validity.o
  CHECK   fs/ext4/move_extent.c
  CC      fs/ext4/move_extent.o
  CHECK   fs/ext4/mmp.c
  CC      fs/ext4/mmp.o
  CHECK   fs/ext4/indirect.c
  CC      fs/ext4/indirect.o
  CHECK   fs/ext4/extents_status.c
  CC      fs/ext4/extents_status.o
  CHECK   fs/ext4/xattr.c
  CC      fs/ext4/xattr.o
  CHECK   fs/ext4/xattr_user.c
  CC      fs/ext4/xattr_user.o
  CHECK   fs/ext4/xattr_trusted.c
  CC      fs/ext4/xattr_trusted.o
  CHECK   fs/ext4/inline.c
  CC      fs/ext4/inline.o
  CHECK   fs/ext4/acl.c
  CC      fs/ext4/acl.o
  CHECK   fs/ext4/xattr_security.c
  CC      fs/ext4/xattr_security.o
  LD      fs/ext4/ext4.o
  LD      fs/ext4/built-in.o
  Building modules, stage 2.
  MODPOST 0 modules

As you can see, only one warning was found here, and odds are, it is a
false-positive, as I'm sure those ext4 developers know what they are
doing with their locking functions, right?

Anyway the task this time is:
  - Run sparse on the drivers/staging/ directory, yes, that horrible
    code again, sorry.
  - Find one warning that looks interesting.
  - Write a patch that resolves the issue.
  - Make sure the patch is correct by running it through
    scripts/checkpatch.pl
  - Submit the code to the maintainer of the driver/subsystem, finding
    the proper name and mailing lists to send it to by running the tool,
    scripts/get_maintainer.pl on your patch.
  - Work with the maintainer to get the patch accepted into their tree.
  - Send a web link back to me of your patch in the public mailing list
    archive (don't cc: me on the patch, that will only confuse me and
    everyone in the kernel development community) as well as a pointer
    to the patch in the maintainer's public git tree.

That's it, much like task 10 was, but this time you are fixing logical
issues, not just pesky coding style issues.  You are a real developer
now, fixing real bugs!


This is Task 17 of the Eudyptula Challenge
------------------------------------------

Another patch made and sent in.  See, that wasn't so hard.  Keep sending
in kernel patches outside of this challenge, those lazy kernel
developers need all the help they can get in cleaning up their code.

It is time to start putting the different pieces of what we have done in
the past together, into a much larger module, doing more complex things.
Much more like what a "real" kernel module has to do.

Go dig up your code from task 06, the misc char device driver, and make
the following changes:

 - Delete the read function.  You don't need that anymore, so make it a
   write-only misc device and be sure to set the mode of the device to
   be write-only, by anyone.  If you do this right, udev will set up the
   node automatically with the correct permissions.
 - Create a wait queue, name it "wee_wait".
 - In your module init function, create a kernel thread, named of course
   "eudyptula".
 - The thread's main function should not do anything at this point in
   time, except make sure to shutdown if asked to, and wait on the
   "wee_wait" waitqueue.
 - In your module exit function, shut down the kernel thread you started
   up.

Load and unload the module and "prove" that it works properly (that the
thread is created, it can be found in the process list, and that the
device node is created with the correct permission value.)  Send in the
proof and the .c file for the module.

Be sure to keep this code around, as we will be doing more with it next
time.

This is Task 18 of the Eudyptula Challenge
------------------------------------------

Nice job with the kernel thread.  It really doesn't take much code at
all to create a new thread.  So now let us get some data into the module
to give the thread something to do.

Base all of this work on your task 17 codebase.

Go back and dig up task 12's source code, the one with the list
handling.  Copy the structure into this module, and the
identity_create(), identity_find(), and identity_destroy() functions
into this module as well.

Write a new function, identity_get(), that looks like:
  struct identity *identity_get(void);
and returns the next "identity" structure that is on the list, and
removes it from the list.  If nothing is on the list, return NULL.

Then, hook up the misc char device "write" function to do the following:
  - If a write is larger than 19 characters, truncate it at 19.
  - Take the write data and pass it to identity_create() as the string,
    and use an incrementing counter as the "id" value.
  - Wake up the "wee_wait" queue.

In the kernel thread function:
  - If the "wee_wait" queue wakes us up, get the next identity in the
    system with a call to identity_get().
  - Sleep (in an interruptable state, don't go increasing the system
    load in a bad way) for 5 seconds.
  - Write out the identity name, and id to the debug kernel log and then
    free the memory.

When the module exits, clean up the whole list by using the functions
given, no fair mucking around with the list variables directly.

Yes, it's a bit clunky, but it shows the basics of taking work from
userspace, and then quickly returning to the user, and then going off
and doing something else with the data and cleaning everything up.  It's
a common pattern for a kernel, as it's really all that a kernel ends up
doing most of the time (get a disk block, write a disk block, handle a
mouse event, etc.)

Load and unload the module and "prove" that it works properly by writing
and looking at the debug log, and that everything cleans up properly
when the module is unloaded.

Send in the proof and the .c file for the module.

A good test script would be the following:
        echo "Alice" > /dev/eudyptula
        echo "Bob" > /dev/eudyptula
        sleep 15
        echo "Dave" > /dev/eudyptula
        echo "Gena" > /dev/eudyptula
        rmmod task18

Removing the module while there is pending work is always a good stress
test.

This is Task 19 of the Eudyptula Challenge
------------------------------------------

Handling delayed work is easy now, right?  So, time to move on to
something totally different.  How about networking?  We have been
ignoring that part of the kernel, so let us now focus on the network
side of the kernel, as that is a huge reason for why Linux has taken
over the world.

For this task, write a netfilter kernel module that does the following:
  - monitors all IPv4 network traffic that is coming into the machine
  - prints the id to the kernel debug log if the network traffic stream
    contains your id.
  - properly unregisters you from the netfilter core when the module
    unloads.

Test this by sending yourself an email with your id in the subject, much
like the email you need to send back to me.

Send in the proof and the .c file for the module.

This is Task 20 of the Eudyptula Challenge
------------------------------------------

Networking filters turned out to be not all that complex in the end,
great work with that.

So, here's the final task.

There might be other tasks that get created and sent out later on, but
the original challenge had 20 tasks, so after finishing this one, you
can consider yourself done!

Let's try something a bit harder.  Something that might cause some data
loss on a filesystem, always a fun thing to play with, if for no other
reason than to not be afraid of things like that in the future.

This task requires you to work on the fat filesystem code:
  - Add an ioctl to modify the volume label of a mounted fat filesystem.
    Be sure to handle both 16 and 32 bit fat filesystems {hint!}
  - Provide a userspace .c program to test this new ioctl.

That's it!  Seems so simple, right?  I wonder why that option isn't in
the kernel tree already...

Anyway, provide a patch to the kernel, and the .c file used to test the
new ioctl, as well as "proof" of this working.  Make sure you don't run
into 32/64bit kernel issues with the ioctl, if you do things correctly,
you shouldn't have any problems.

I recommend doing this work on either a loop-back fat filesystem on your
"normal" filesystem, or on a USB stick.  Either will work just as well,
and make things easier to debug and test.

Watch out for locking issues, as well as dirty filesystem state
problems.

Best of luck!
