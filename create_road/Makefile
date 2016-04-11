##
## Makefile for makefile in /home/wery_p/rendu/gfx_tekadventure/create_road
##
## Made by Paul Wery
## Login   <wery_p@epitech.net>
##
## Started on  Wed Apr  6 22:15:40 2016 Paul Wery
## Last update Tue Apr 12 00:20:10 2016 Paul Wery
##

NAME	=	road

RM	=	rm -f

CC	=	gcc -g

CFLAGS	=	-W -Wall -Werror -ansi -pedantic -Iinclude -I/home/${USER}/.froot/include

OBJS	=	$(SRCS:.c=.o)

SRCS	=	srcs/main.c \
		srcs/events.c \
		srcs/resize.c \
		srcs/my_list.c \
		srcs/delete_links.c \
		srcs/pix_initialize.c \
		srcs/tekpixel.c \
		srcs/create_tmp.c \
		srcs/tekcircle.c \
		srcs/events_next.c \
		srcs/events_w.c \
		srcs/line/tekline.c \
		srcs/line/ini_line.c \
		srcs/line/line.c \
		srcs/line/my_color.c

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
