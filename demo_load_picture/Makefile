##
## Makefile for wolf3d in /home/marel_m/rendu/projet/Infographie/
##
## Made by maud marel
## Login   <marel_m@epitech.net>
##
## Started on  Thu Dec 17 13:59:43 2015 maud marel
## Last update Sun Feb 14 19:02:36 2016 maud marel
##

NAME    =	bmpload

SRC     =	bmploader.c

OBJ    	=	$(SRC:.c=.o)

CC      =	gcc

CFLAGS  =	-W -Wall -Werror -ansi -pedantic

CFLAGS	+=	-I/home/${USER}/.froot/include

LDFLAGS =	-L/home/${USER}/.froot/lib \
		-llapin \
		-lsfml-audio \
		-lsfml-graphics \
		-lsfml-window \
		-lsfml-system \
		-lstdc++ -ldl \
		-lm \
		-L./lib/ \

RM      = 	rm -f

.c.o:
	$(CC) -c $< -o $@ $(CFLAGS)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

all: $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
