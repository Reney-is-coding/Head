#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "include/prototypes.h"

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
