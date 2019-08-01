##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile of libmy
##

NAME	=	libmy.a

CC	=	gcc

SRC	=	src/my_printf/my_printf.c		\
		src/my_printf/my_printf_one.c		\
		src/get_next_line/get_next_line.c	\
		src/my_compute_power_rec.c		\
		src/my_revstr.c				\
		src/my_atoi.c				\
		src/my_itoa.c				\
		src/my_putchar.c			\
		src/my_puterror.c			\
		src/my_str_to_selec_array.c		\
		src/my_strchr.c				\
		src/my_put_nbr.c			\
		src/my_putstr.c				\
		src/misnum.c				\
		src/my_revstr.c				\
		src/my_strcat.c				\
		src/my_strcmp.c				\
		src/my_strcpy.c				\
		src/my_getnbr.c				\
		src/my_strdup.c				\
		src/my_strlen.c				\
		src/my_isnum.c				\
		src/my_str_to_word_array.c		\
		src/my_malloc.c				\
		src/my_free.c				\
		src/my_exit.c

CFLAGS	+=	-Wall -Wextra -I./include -I../../include

OBJ	=	$(SRC:.c=.o)


all:	$(NAME)

%.o:	%.c
	@$(CC) $(CFLAGS) -c -o $@ $< -g3
	@if [ -a $@ ]; then echo -e "\033[0;32m[OK]    \033[1;32m" $< "\033[0m"; else echo -e "\033[0;31m[KO]    \033[1;31m" $< "\033[0m"; fi;

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@if [ -a $(NAME) ]; then echo -en "\033[0;34m[OK]    \033[1;34m" $(NAME) "successfully compiled!\n\033[0m"; else echo -e "\033[0;31m[KO]    \033[1;31m" $(NAME) "not compiled!\n\033[0m"; fi;

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
