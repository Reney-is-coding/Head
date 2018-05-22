/*
** EPITECH PROJECT, 2018
** Head
** File description:
** main
*/

#include <string.h>
#include "include/my.h"

/*all_t fill_strutct(void)
{
	all_t all;

	all.c_handling = 0;
	all.c_bytes = 0;
	all.n_handling = 0
	all.lines = 10;
	all.q_handling = 0;
	all.v_handling = 0;
	all.error = 0;
	return (all);
}

all_t fill_things(char *arg, char  *follow, all_t all)
{
	if (strcmp(arg, "-c") == 0 || strcmp(arg, "--bytes") == 0) {
		if (!follow) {
			all.error = 84;
			return (all);
		}

	}
	if (strcmp(arg, "-c") == 0 || strcmp(arg, "--bytes") == 0)

}
*/

int	main(int ac, char **av)
{
	char *file[2] = {"Makefile", NULL};
/*	all_t all = fill_strutct;
	for (int i = 0; av[i]; i++) {
		fill_things(av[i], av[i+1]);
	}
*/	print_head_files(file, 4);

	return (0);
}
