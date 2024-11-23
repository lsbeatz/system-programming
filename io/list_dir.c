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

	while ((entry = readdir(dir)) != NULL) {
		struct stat entry_stat;

		if (stat(entry->d_name, &entry_stat) == -1) {
			perror("stat\n");
			continue;
		}

		if (S_ISDIR(entry_stat.st_mode)) {
			printf("[DIR]  %s\n", entry->d_name);
		} else {
			printf("[FILE] %s\n", entry->d_name);
		}
	}

	closedir(dir);

	return 0;
}
