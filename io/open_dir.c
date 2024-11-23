#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int main(void)
{
	const char *path = ".";
	struct dirent *entry;
	DIR *dir;

	dir = opendir(path);
	if (dir == NULL) {
		perror("opendir\n");
		exit(1);
	}

	printf("Directry %s opened\n", path);

	while ((entry = readdir(dir)) != NULL) {
		printf("Entry: %s\n", entry->d_name);
	}

	closedir(dir);

	return 0;
}
