##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile for duostumper2
##

CFLAGS	=	-W -Wall -Wextra

SRCS 	=	main.c		\
		head.c		\
		get_next_line.c	\

OBJS	=	$(SRCS:.c=.o)

NAME	=	Head

all: 	$(NAME)

$(NAME): $(OBJS)
	gcc -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
