#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

extern int errno;

#define BUF_LEN 10

int main(void)
{
	int res;
	char buf[BUF_LEN];

	int fd = open("/dev/eudyptula", O_RDWR);
	if (!fd) {
		perror("Open");
		return 1;
	}

	// read test
	res = read(fd, buf, BUF_LEN);
	if (res != BUF_LEN) {
		perror("Test");
		return 1;
	}
	printf("Received %s\n", buf);

	// fail read
	res = read(fd, buf, BUF_LEN-1);

	// write test
	strcpy(buf, "Eudyptula");
	buf[9] = '\0';
	res = write(fd, buf, BUF_LEN);
	if (res != BUF_LEN) {
		perror("Test");
		return 1;
	}
	printf("Wrote %s\n", buf);

	// fail write
	strcpy(buf, "eudyptula");
	res = write(fd, buf, BUF_LEN);
	res = write(fd, buf, BUF_LEN-1);

	return 0;
}
