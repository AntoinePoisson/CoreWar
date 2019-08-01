##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME		=	asm

CC		=	gcc

MAIN		=	src/main.c

SRC		=	src/assembly.c					\
			src/management_tab.c				\
			src/write_parameter.c				\
			src/create.c					\
			src/write_data.c				\
			src/check_error_header.c			\
			src/calcul_coding_byte.c			\
			src/help_flag.c					\
			src/management_header.c				\
			src/tools.c					\
			src/endian.c					\
			src/is_wrong_champ.c				\
			src/is_wrong_label.c				\
			src/check_parameters.c				\
			src/is_wrong_parameters.c			\
			src/stack_instruct.c				\
			src/instruct/add.c				\
			src/instruct/aff.c				\
			src/instruct/and.c				\
			src/instruct/fork.c				\
			src/instruct/ld.c				\
			src/instruct/ldi.c				\
			src/instruct/lfork.c				\
			src/instruct/live.c				\
			src/instruct/lld.c				\
			src/instruct/lldi.c				\
			src/instruct/or.c				\
			src/instruct/st.c				\
			src/instruct/sti.c				\
			src/instruct/sub.c				\
			src/instruct/xor.c				\
			src/instruct/zjmp.c				\
			src/stack_labels.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		+=	-I./include -I./lib/my/include

LFLAGS		=	-L./lib/my -lmy

LDFLAGS 	=	-Wall -Wextra -W

all:			$(NAME)

%.o:			%.c
			@$(CC) $(CFLAGS) $(LDFLAGS) $(LFLAGS) -g3 -c -o $@ $<
			@if [ -a $@ ]; then echo -e "\033[0;32m[OK]    \033[1;32m" $< "\033[0m"; else echo -e "\033[0;31m[KO]    \033[1;31m" $< "\033[0m"; fi;

$(NAME):		compile_lib $(OBJ)
			@echo -e "\033[0;34m[OK]     \033[1;34mObj's files successfully compiled!\033[0m"
			@gcc -o $(NAME) $(MAIN) $(OBJ) $(CFLAGS) $(LDFLAGS) $(LFLAGS) $(LFLAGS) -g3
			@if [ -a $(NAME) ]; then echo -e "\033[0;34m[OK]    \033[1;34m" $(NAME) "successfully created!\033[0m"; else echo -e "\033[0;31m[KO]    \033[1;31m" $(NAME) "not compiled\033[0m"; fi;

compile_lib:
			@make -sC lib/my

clean:
			@make -sC lib/my clean
			@rm -f $(OBJ)

fclean:			clean
			@make -sC lib/my fclean
			@rm -f $(shell find . -name "*~")
			@rm -f $(shell find . -name "vgcore.*")
			@rm -f $(shell find . -name "*.gcda")
			@rm -f $(shell find . -name "*.gcno")
			@rm -f *.cor
			@rm -f $(NAME)
			@echo -e "\033[0;33m[OK]     \033[1;33msuccessfully cleaned!\033[0m"

re:			fclean all

.PHONY:			all clean fclean re
