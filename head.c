/*
** EPITECH PROJECT, 2018
** Head
** File description:
** main
*/

#include "include/my.h"

void print_head_files(char **file, int line)
{
	int i = 0;
	int fd = 0;
	char *s = NULL;

	while (file[i] != NULL) {
		fd = open(file[i], O_RDONLY);
		if (fd == -1) {
			printf("Invalid file name : %s\n", file[i]);
			++i;
			continue;
		}
		for (int j = 0; j != line; j++) {
			s = get_next_line(fd);
			if (s == NULL)
				break;
			printf("%s\n", s);
		}
		close(fd);
	}
}
