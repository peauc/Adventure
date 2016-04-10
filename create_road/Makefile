##
## Makefile for makefile in /home/wery_p/rendu/gfx_tekadventure/create_road
##
## Made by Paul Wery
## Login   <wery_p@epitech.net>
##
## Started on  Wed Apr  6 22:15:40 2016 Paul Wery
## Last update Sun Apr 10 15:13:01 2016 Paul Wery
##

NAME	=	road

RM	=	rm -f

CC	=	gcc

CFLAGS	=	-W -Wall -Werror -ansi -pedantic -Iinclude -I/home/${USER}/.froot/include

OBJS	=	$(SRCS:.c=.o)

SRCS	=	main.c \
		events.c \
		resize.c \
		my_list.c \
		pix_initialize.c \
		tekpixel.c \
		line.c

LIB	=	-L/home/${USER}/.froot/lib\
		-llapin -lsfml-audio -lsfml-graphics\
		-lsfml-window -lsfml-system -lstdc++ -ldl -lm

$(NAME)	:	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LIB)

all	:	$(NAME)

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY:		all clean fclean re
