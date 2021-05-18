##
## EPITECH PROJECT, 2020
## makeile
## File description:
## makefile
##

SRC	=	minishell.c				\
		src/my_putchar.c 		\
		src/function.c 			\
		src/check.c 			\
		src/manage_env.c 		\
		src/my_strcmp.c 		\
		src/my_strncpy.c 		\
		src/miniprint.c 		\
		src/create_env.c 		\
		src/my_putstr.c 		\
		src/free_tab.c			\
		src/str_convertion.c 	\
		src/exec.c 	            \
		src/multi_cmd.c 	    \
		src/cmd.c 	            \
		src/manage_cmd.c 	    \
		src/my_put_nbr.c 		\
		src/my_strlen.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -g3

clean:
	rm -rf *.o
	rm -rf *.c~
	rm -rf *~
	rm -rf *.a

fclean: clean
	rm $(NAME)

re:	fclean all
