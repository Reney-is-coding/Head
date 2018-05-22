/*
** EPITECH PROJECT, 2018
** Head
** File description:
** main
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

char *my_strcat(char *str1, char *str2)
{
	char *end = malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 1));
	int a = 0;

	for (int i = 0; str1[i] != '\0'; i++) {
		end[a] = str1[i];
		a++;
	}
	for (int i = 0; str2[i] != '\0'; i++) {
		end[a] = str2[i];
		a++;
	}
	end[(strlen(str1) + strlen(str2))] = '\0';
	free(str2);
	return (end);
}

char *get_next_line(int fd)
{
	char *end = malloc(sizeof(char) * 2);
	char *buffer = malloc(sizeof(char) * 2);
	end[0] = '\0';
	end[1] = '\0';
	buffer[0] = '\0';
	int d = read(fd, buffer, 1);
	buffer[1] = '\0';

	while (1) {
		if (d == -1 || buffer[0] == '\0')
			return(NULL);
		if (buffer[0] == '\n')
			return (end);
		end = my_strcat(end, buffer);
		d = read(fd, buffer, 1);
		buffer[1] = '\0';
	}
	return (end);
}
