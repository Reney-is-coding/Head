/*
** EPITECH PROJECT, 2018
** Head
** File description:
** main
*/

#include "include/my.h"

int	main(int ac, char **av)
{
	char *file[3] = {"Makefile", "head.c", "my.h"};
	print_head_files(file, 7);
	return (0);
}
