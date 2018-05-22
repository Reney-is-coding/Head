/*
** EPITECH PROJECT, 2018
** Head
** File description:
** main
*/

#include "include/my.h"

void print_head_files(char **file, int line, all_t all)
{
	int i = 0;
	int fd = 0;
	char *s = NULL;

	if (file[0] == NULL)
		return;

	while (file[i] != NULL) {
		fd = open(file[i], O_RDONLY);
		if (fd == -1) {
			printf("Invalid file name : %s\n", file[i]);
			++i;
			continue;
		}
		if ((file[1] != NULL || all.v_handling == 1) && all.q_handling == 0)
			printf("==> %s <==\n", file[i]);
		for (int j = 0; j != line; j++) {
			s = get_next_line(fd);
			if (s == NULL)
				break;
			printf("%s\n", s);
		}
		if (fd != -1)
			close(fd);
		if (file[i + 1] != NULL)
			printf("\n");
		i++;
	}
}
