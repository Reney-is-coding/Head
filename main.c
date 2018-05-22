/*
** EPITECH PROJECT, 2018
** Head
** File description:
** main
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"

all_t fill_strutct(void)
{
	all_t all;

	all.c_handling = 0;
	all.c_bytes = 0;
	all.n_handling = 0;
	all.lines = 10;
	all.q_handling = 0;
	all.v_handling = 0;
	all.error = 0;
	return (all);
}

all_t fill_seconds(char *arg, all_t all)
{
	if (strcmp(arg, "-v") == 0 || strcmp(arg, "--verbose") == 0)
	 	all.v_handling = 1;
	if (strcmp(arg, "-q") == 0 || strcmp(arg, "--quiet") == 0 ||
	strcmp(arg, "--silent") == 0)
		all.q_handling = 1;
	return (all);
}

all_t fill_things(char *arg, char  *follow, all_t all)
{
	if (strcmp(arg, "-c") == 0 || strcmp(arg, "--bytes") == 0) {
		if (!follow || atoi(follow) == 0) {
			all.error = 84;
			return (all);
		}
		all.c_bytes = atoi(follow);
		all.c_handling = 1;
		all.n_handling = 0;
	}
	if (strcmp(arg, "-n") == 0 || strcmp(arg, "--lines") == 0) {
		if (!follow || atoi(follow) == 0) {
			all.error = 84;
			return (all);
		}
		all.lines = atoi(follow);
		all.n_handling = 1;
		all.c_handling = 0;
	}
	all = fill_seconds(arg, all);
	return (all);
}

char **fill_file(int ac, char **av)
{
	char **file = malloc(sizeof(char *) * (ac + 1));
	int j = 0;

	for (int i = 0; i != ac + 1; i++)
		file[i] = NULL;
	for (int i = 1; i != ac; ++i) {
		if (av[i][0] == '-') {
			continue;
		} else if (av[i][0] >= '0' && av[i][0]<='9' && av[i-1][0] == '-') {
			continue;
		} else {
			for (j = 0; file[j] != NULL; ++j);
			file[j] = av[i];
		}
	}
	return (file);
}

int	main(int ac, char **av)
{
	all_t all = fill_strutct();
	char **file = fill_file(ac, av);
	for (int i = 0; av[i]; i++) {
		all = fill_things(av[i], av[i+1], all);
	}
	if (all.error != 84)
		print_head_files(file, all.lines, all);
	for (int i = 0; file[i] != NULL; i++) {
		free(file[i]);
	}
	free(file);
	return (all.error);
}
