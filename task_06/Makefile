obj-m += eudyptula.o
CFLAGS_eudyptula.o := -DDEBUG

all:
	${MAKE} -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

test:
	$(CC) test.c -o test

clean:
	${MAKE} -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	rm -f test
