##
## Makefile for make in /home/peau_c/rendu/PSU/minishell/PSU_2015_minishell1
##
## Made by Clement Peau
## Login   <peau_c@epitech.net>
##
## Started on  Thu Jan  7 16:17:02 2016 Clement Peau
## Last update Sun Apr 17 22:06:04 2016 Paul Wery
## Last update Sun Apr 17 14:44:44 2016 marel_m
##

DEBUG=	yes

SRC=	main.c					\
	anim_sprite.c				\
	helper.c				\
	dictionary.c				\
	node_list.c				\
	node_helper.c				\
	pathfinding.c				\
	do_some_shit.c				\
	movement.c				\
	player.c				\
	change_road.c				\
	full_ini.c				\
	../create_road/srcs/my_list.c		\
	../create_road/srcs/delete_links.c	\
	../create_road/srcs/comp_string.c	\
	../create_road/srcs/tekcircle.c		\
	../create_road/srcs/tekpixel.c		\
	../create_road/srcs/create_tmp.c	\
	../create_road/srcs/line/ini_line.c	\
	../create_road/srcs/line/line.c		\
	../create_road/srcs/line/tekline.c	\
	../create_road/srcs/line/my_color.c	\
	draw_inventory.c			\
	resize.c				\
	load_music.c				\
	load_scene_beach_harbor_manor_arrow.c	\
	load_scene_house_shop.c			\
	print_image.c				\
	mv_camera.c				\
	scene/house_outside.c			\
	scene/house_inside.c			\
	scene/harbor.c				\
	scene/manor.c				\
	scene/basement.c			\
	scene/boat.c				\
	scene/beach.c				\
	scene/shop.c				\
	scene/shop_place.c			\
	draw_items.c				\
	my_strdup.c				\
	determine_button.c			\
	determine_item.c			\
	draw_scene.c				\
	draw_menu.c				\
	get_pos.c				\
	load_buttons.c				\
	load_item_basement.c			\
	menu.c					\
	menu_load.c				\
	init_tab.c				\
	free_scene.c				\
	pixelarraycpy.c				\
	get_const_nb.c

OBJ=	$(addprefix src/, $(SRC:.c=.o))

RM=	rm -f

CMD=	 -llapin -lsfml-audio -lsfml-graphics -lsfml-window
CMD+=	 -lsfml-system -lstdc++ -ldl -L ~/.froot/lib -lm

LIB=	-I inc/

ifeq ($(DEBUG), yes)
	CFLAGS=		$(HEAD) -W -Wall -Wextra -ansi -pedantic -g -D DEBUG
	CC=		clang
else
	CFLAGS=		$(HEAD) -W -Wall -Wextra -ansi -pedantic
	CC=		gcc
endif

NAME=	adv

HEAD=	-I inc/

$(NAME):                $(OBJ)
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
	@ $(CC) $(OBJ) -o $(NAME) $(CMD)
	@ echo -e "\033[1;31m \t \t \n \t ♩♪♫ $(NAME) Compiled\033[0;31m®\033[1;31m Created Sucesfully \033[0m"

all:		$(NAME)

clean:
		@ $(RM) $(OBJ)
		@ echo "[ OK ] clean sucessfull"
fclean: clean
		@ $(RM) $(NAME)
		@ echo "[ OK ] fclean succesfull"

re:	fclean all
%.o:                    %.c
			@ echo "[ OK ] Compiling" $<
			@ $(CC) -o $@ -c $< $(CFLAGS)
