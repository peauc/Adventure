##
## Makefile for PiscineJ10 in /home/sauvau_m/rendu/Piscine_C_J10/lib/my
##
## Made by Mathieu Sauvau
## Login   <sauvau_m@epitech.net>
##
## Started on  Fri Oct  9 09:40:40 2015 Mathieu Sauvau
## Last update Mon Apr 11 19:16:16 2016 Mathieu Sauvau
##

CFLAGS += -W -Wall -Wextra
CFLAGS += -I ./include
CFLAGS += -I /home/${USER}/.froot/include

LIBGUI = ./libgui/

SRC	= $(LIBGUI)button_gui.c \
	  $(LIBGUI)checkbox_gui.c \
	  $(LIBGUI)write_img.c \
	  $(LIBGUI)draw_button.c \
	  $(LIBGUI)rect.c \
	  $(LIBGUI)my_blit.c \
	  $(LIBGUI)event_gui.c \
	  $(LIBGUI)helper.c \
	  $(LIBGUI)text_gui.c \
	  $(LIBGUI)write_txt.c \
	  $(LIBGUI)texture_gui.c \
	  $(LIBGUI)itoa.c \
	  $(LIBGUI)my_strcpy.c \
	  $(LIBGUI)my_strcat.c \
	  $(LIBGUI)my_strcmp.c \
	  $(LIBGUI)pixel.c \
	  $(LIBGUI)img_gui.c \
	  $(LIBGUI)my_strdup.c \
	  $(LIBGUI)display.c \
	  $(LIBGUI)load.c \
	  $(LIBGUI)load2.c \
	  $(LIBGUI)load_but_check.c \
	  $(LIBGUI)load_text_img.c \
	  $(LIBGUI)draw_texture_gui.c \
	  $(LIBGUI)free_all.c \
	  $(LIBGUI)free_all2.c \
	  $(LIBGUI)config_ram.c \

NAME	= libtekgui.a

OBJ	= $(SRC:.c=.o)

$(NAME): $(OBJ)
	 ar rc $(NAME) $(OBJ)
	 ranlib $(NAME)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

re:	fclean all
