##
## Makefile for make in /home/peau_c/rendu/PSU/minishell/PSU_2015_minishell1
##
## Made by Clement Peau
## Login   <peau_c@epitech.net>
##
## Started on  Thu Jan  7 16:17:02 2016 Clement Peau
## Last update Wed Apr 13 13:26:49 2016 Poc
##

DEBUG=	yes

SRC=	main.c 			\
	fill.c			\
	menu.c			\
	menu_load.c		\
	tekpixel.c		\
	load_buttons.c		\
	determine_button.c	\

SRC_LIB= 	my_strcpy.c			\
		my_strlen.c			\
		my_strdup.c			\

OBJ_LIB=	$(addprefix ../lib/, $(SRC_LIB:.c=.o))

OBJ=		$(addprefix src_menu/, $(SRC:.c=.o))

RM=		rm -f

CMD=		 -llapin -lsfml-audio -lsfml-graphics -lsfml-window
CMD+=		 -lsfml-system -lstdc++ -ldl -L ~/.froot/lib -lm

LIB=    	-I inc_menu/

ifeq ($(DEBUG), yes)
CFLAGS=		$(HEAD) -W -Wall -Wextra -ansi -pedantic -g -D DEBUG
CC=		clang
else
CFLAGS=		$(HEAD) -W -Wall -Wextra -ansi -pedantic
CC=		gcc
endif

NAME=		adv

HEAD=		-I inc/

$(NAME):	$(OBJ) $(OBJ_LIB)
ifeq ($(DEBUG), yes)
		@tput setaf 1; tput bold
		@echo " ____________________ ________________________   ____ ___._________________";
		@echo "/   _____/\_   _____|/  _____/\_   _____/  _  \ |    |   \    | \__    ___/";
		@echo "\_____  \  |    ___|/   \  ___ |    __)/  / \  \|    |   /    |   |    |";
		@echo "/        \ |        \    \_\  \|     \/    |    \    |  /|    |___|    |";
		@echo "/________//_________/\________/\_____/\____|____/______/ |________|____|";
		@tput sgr0
		rm -rf TAGS
		find . -type f -iname "*.[chS]" | xargs etags -a
endif
		@ echo "CC = $(CC)"
		@ echo "CFLAGS = $(CFLAGS)"
		@ $(CC) $(OBJ) $(OBJ_LIB) -o $(NAME) $(CMD)
		@ echo -e "\033[1;31m \t \t \n \t ♩♪♫ $(NAME) Compiled\033[0;31m®\033[1;31m Created Sucesfully \033[0m"

all:		$(NAME)

clean:
		@ $(RM) $(OBJ) $(OBJ_LIB)
		@ echo "[ OK ] clean sucessfull"
fclean: clean
		@ $(RM) $(NAME)
		@ echo "[ OK ] fclean succesfull"

re:	fclean all
%.o:		%.c
		@ echo "[ OK ] Compiling" $<
		@ $(CC) -o $@ -c $< $(CFLAGS) $(LIB)
