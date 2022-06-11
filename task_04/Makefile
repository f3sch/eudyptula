obj-m += hello.o coding_style.o
CFLAGS_hello.o := -DDEBUG

all:
	${MAKE} -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	${MAKE} -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
