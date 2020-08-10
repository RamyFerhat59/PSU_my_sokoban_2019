##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC=	src/my_sokoban.c \
		src/my_strlen.c \
		src/my_putstr.c	\
		src/my_putchar.c \
		src/input.c 

NAME=	my_sokoban

CFLAGS=	$(HEAD) -Wall -Wextra

HEAD=	-Iinclude -lncurses

CC=	gcc -g $(CFLAGS)

RM=	rm -f

OBJ=	$(SRC:.c=.o)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

all: 	$(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: 	fclean all

.PHONY: all clean fclean re
