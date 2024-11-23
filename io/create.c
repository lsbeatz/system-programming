#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <unistd.h>

int main(void){
	char *fname = "example.txt";
	int fd;

	fd = open(fname, O_RDWR | O_CREAT, 0644);
	if (fd < 0){
		fprintf(stderr,"open error for %s\n", fname);
		exit(1);
	} else {
		printf("Success!\nFilename : %s\nFile Descriptor : %d\n", fname, fd);
	}

	close(fd);

	return 0;
}

