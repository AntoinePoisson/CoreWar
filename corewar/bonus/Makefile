##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME		=	corewar

CC		=	gcc

MAIN		=	src/main.c

SRC		=	src/corewar.c				\
			src/parser/file.c			\
			src/find_instruct/analyze_instruction.c	\
			src/find_instruct/find_instruction_two.c\
			src/init_arena.c			\
			src/find_instruct/find_instruction.c	\
			src/find_instruct/live.c		\
			src/find_instruct/zjmp.c		\
			src/find_instruct/ldi.c			\
			src/find_instruct/sti.c			\
			src/find_instruct/fork.c		\
			src/find_instruct/lldi.c		\
			src/find_instruct/lfork.c		\
			src/parser/parser.c			\
			src/display.c				\
			src/game_loop.c				\
			src/instructions/or.c			\
			src/instructions/xor.c			\
			src/instructions/and.c			\
			src/instructions/sub.c			\
			src/instructions/add.c			\
			src/instructions/ld.c			\
			src/instructions/ldi.c			\
			src/instructions/lfork.c		\
			src/instructions/live.c			\
			src/instructions/lld.c			\
			src/instructions/lldi.c			\
			src/instructions/my_fork.c		\
			src/instructions/st.c			\
			src/instructions/sti.c			\
			src/instructions/zjump.c		\
			src/instructions/aff.c			\
			src/instructions/tools.c		\
			src/misc.c				\
			src/parser/error.c			\
			src/free_array.c			\
			src/fill_int_value.c			\
			src/apply_instruction.c			\

OBJ		=	$(SRC:.c=.o)

CFLAGS		+=	-I./include -I./lib/my/include

LFLAGS		=	-L./lib/my -lmy	-lncurses

LDFLAGS 	=	-Wall -Wextra -W

all:			$(NAME)

%.o:			%.c
			@$(CC) $(CFLAGS) $(LDFLAGS) $(LFLAGS) -g3 -c -o $@ $<
			@if [ -a $@ ]; then echo -e "\033[0;32m[OK]    \033[1;32m" $< "\033[0m"; else echo -e "\033[0;31m[KO]    \033[1;31m" $< "\033[0m"; fi;

$(NAME):		compile_lib $(OBJ)
			@echo -e "\033[0;34m[OK]     \033[1;34mObj's files successfully compiled!\033[0m"
			@gcc -o $(NAME) $(MAIN) $(OBJ) $(CFLAGS) $(LDFLAGS) $(LFLAGS) $(LFLAGS)
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
			@rm -f $(shell find . -name "*.o")
			@rm -f $(NAME)
			@echo -e "\033[0;33m[OK]     \033[1;33msuccessfully cleaned!\033[0m"

re:			fclean all

.PHONY:			all clean fclean re
