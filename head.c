/*
** EPITECH PROJECT, 2018
** Head
** File description:
** main
*/

#include <stdlib.h>
#include "include/my.h"

void print_c (int fd, int bytes)
{
	char *s;
	if (bytes < 0) {
		s = malloc(sizeof(char)* 20000);
	} else {
		s = malloc(sizeof(char)* bytes);
	}

	if (bytes > 0) {
		read(fd, s, bytes);
		write(1, s, strlen(s));
	}
	if (bytes < 0) {
		read(fd, s, 20000);
		write(1, s, (strlen(s) + bytes));
	}
	close (fd);
}


void print_other(int line, int fd, char *path)
{
	char *s = "aaa";
	int size = 0;
	while (s) {
		s = get_next_line(fd);
		size++;
	}
	size = size + line;
	close (fd);
	fd = open(path, O_RDONLY);
	for (int i = 0; i < size ; i++) {
		s = get_next_line(fd);
		printf("%s\n", s);
	}
	close(fd);
}

void print_head_files(char **file, int line, all_t all)
{
	int i = 0;
	int fd = -1231;
	char *s = NULL;
	int check = 0;

	if (file[0] == NULL) {
		fd = 0;
		check = 1;
	}

	while (file[i] != NULL || check == 1) {
		if (check == 0) {
			fd = open(file[i], O_RDONLY);
		}
		if (fd == -1) {
			printf("Invalid file name : %s\n", file[i]);
			++i;
			check = 0;
			continue;
		}
		if ((file[1] != NULL || all.v_handling == 1) && all.q_handling == 0)
			printf("==> %s <==\n", file[i]);
		if (all.c_handling == 1) {
			print_c(fd, all.c_bytes);
			i++;
			check = 0;
			continue;
		}
		if (line < 0) {
			print_other(line, fd, file[i]);
			i++;
			check = 0;
			continue;
		}
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
		check = 0;
	}
}
