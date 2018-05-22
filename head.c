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

void print_file(int line, int fd)
{
	char *s;

	for (int j = 0; j != line; j++) {
		s = get_next_line(fd);
		if (s == NULL)
		break;
		printf("%s\n", s);
	}
}

all_t check_null(char **file, all_t all)
{
	if (file[0] == NULL) {
		all.fd = 0;
		all.check = 1;
	}
	return (all);
}

int check_file(all_t *all, int i, char *s)
{
	printf("Invalid file name : %s\n", s);
	++i;
	all->check = 0;
	return (i);
}

int print_c1(all_t *all, int i)
{
	print_c(all->fd, all->c_bytes);
	i++;
	all->check = 0;
	return (i);
}

void print_head_files(char **file, int line, all_t all)
{
	int i = 0;

	all = check_null(file, all);
	while (file[i] != NULL || all.check == 1) {
		if (all.check == 0) {
			all.fd = open(file[i], O_RDONLY);
		}
		if (all.fd == -1) {
			i = check_file(&all, i, file[i]);
			continue;
		}
		if ((file[1] != NULL || all.v_handling == 1) && all.q_handling == 0)
			printf("==> %s <==\n", file[i]);
		if (all.c_handling == 1) {
			i = print_c1(&all, i);
			continue;
		}
		if (line < 0) {
			print_other(line, all.fd, file[i]);
			i++;
			all.check = 0;
			continue;
		}
		print_file(line, all.fd);
		if (all.fd != -1)
			close(all.fd);
		if (file[i + 1] != NULL)
			printf("\n");
		i++;
		all.check = 0;
	}
}
