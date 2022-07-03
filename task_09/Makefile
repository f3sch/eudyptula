obj-m += hello_sysfs.o
CFLAGS_hello_sysfs.o := -DDEBUG

all:
	${MAKE} -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	${MAKE} -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
