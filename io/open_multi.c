#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <unistd.h>

int main(void){
	char *fname[3] = {
		"example1.txt",
		"example2.txt",
		"example3.txt",
	};
	int fd[3];

	for (int i = 0; i < 3; i++) {
		fd[i] = open(fname[i], O_RDWR | O_CREAT, 0644);
		if (fd[i] < 0){
			fprintf(stderr,"open error for %s\n", fname[i]);
			break;
		} else {
			printf("Success!\nFilename : %s\nFile Descriptor : %d\n", fname[i], fd[i]);
		}
	}
	
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);

	return 0;
}

