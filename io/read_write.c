#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void){
	char *fname = "example.txt";
	char *wbuf = "Hello, World!";
	char rbuf[256];
	ssize_t wbytes, rbytes;
	int fd;

	fd = open(fname, O_RDWR | O_CREAT, 0644);
	if (fd < 0){
		fprintf(stderr, "open error for %s\n", fname);
		exit(1);
	}

	wbytes = write(fd, wbuf, strlen(wbuf));
	if (wbytes != strlen(wbuf)) {
		fprintf(stderr, "write error for fd: %d\n", fd);
		close(fd);
		exit(1);
	}

    if (lseek(fd, 3, SEEK_SET) < 0) {
        fprintf(stderr, "lseek error for fd: %d\n", fd);
        close(fd);
        exit(1);
    }

	rbytes = read(fd, rbuf, wbytes);
	printf("wbytes: %ld, rbytes: %ld, buf: %s\n", wbytes, rbytes, rbuf);

	close(fd);

	return 0;
}

