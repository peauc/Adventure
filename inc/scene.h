/*
** scene.h for scene in /home/peau_c/bin
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Wed Feb 17 00:48:19 2016 Clement Peau
** Last update Sun Apr 17 15:05:16 2016 marel_m
*/

#ifndef _SCENE_

# define _SCENE_

# include <lapin.h>
# include <stdbool.h>
# include "lib.h"
# include "item.h"

# define PUTERROR(X)	write(2, X, my_strlen(X))
# define PUTSTR(X)	write(1, X, my_strlen(X))
# define WIDTH 1024
# define HEIGHT 768

typedef struct		s_button
{
  char                  *name;
  t_bunny_pixelarray    *sprite;
  t_bunny_pixelarray    *active_sprite;
  t_bunny_position      start;
  t_bunny_position      end;
  int                   is_clicked;
}			t_button;

typedef struct		s_menu
{
  t_button              *buttons;
}			t_menu;

typedef struct		s_scene
{
  t_bunny_pixelarray	*back;
  t_bunny_pixelarray	*middle;
  t_bunny_pixelarray	*front;
  t_item		*item;
  char			*name;
}			t_scene;

typedef struct			s_mv_scene
{
  int				mv_bck;
  int				mv_mid;
  int				mv_fr;
  int				s_nb;
  int				click;
  const t_bunny_position	*pos_click;
  const t_bunny_position	*mouse;
  int				old_mouse;
}				t_mv_scene;

typedef struct			s_data
{
  t_scene			tab[14];
  t_mv_scene			*mv_s;
  t_bunny_window		*win;
  t_bunny_pixelarray		*new;
  t_bunny_pixelarray		*pixel;
  t_menu			*menu;
}				t_data;

enum			scene
  {
    HARBOR,
    BOAT,
    SHOP_PLACE,
    SHOP,
    BEACH,
    HOUSE_OUT,
    HOUSE_IN,
    BASEMENT,
    MANOR,
    MANOR_IN,
    MAX_SCENE
  };

typedef struct		s_scene_nb
{
  int			scene_nb;
  void			(*ft_scene_nb)(t_data *data);
}			t_scene_nb;

int			determine_button_clicked(t_menu *);
int			draw_scene(t_data *);
int			load_scene_tab(t_scene[14]);
int			draw_menu(t_bunny_pixelarray *, t_menu *);
int			draw_inventory(t_bunny_pixelarray *, t_scene[14]);
int			determine_item(t_scene);
int			init_scene(t_scene[14]);
int			load_buttons(t_menu *);
int			draw_items(t_item *, t_bunny_pixelarray *);
int			is_clicked(t_bunny_position *,
				   t_bunny_pixelarray *,
				   t_bunny_position);
int			load_all_scene(t_data *);
int			load_item(t_menu *, t_bunny_ini *);
int			load_item_basement(t_scene *);
char			*my_strdup(char *);
t_menu			*load_menu();
void			pixelarray_copy(t_bunny_pixelarray *,
					 t_bunny_pixelarray *,
					 t_bunny_position);
t_bunny_position	get_pos(int, int);
t_bunny_pixelarray	*resize_picture(t_bunny_pixelarray *, int, int);
void			set_all_to_zero(t_button *);
void			pix_initialize(t_bunny_pixelarray *);
void			boat(t_data *);
void			put_pix_in_pix_txt(t_bunny_pixelarray *,
					   t_bunny_pixelarray *,
					   t_bunny_position,
					   int);
t_bunny_response	clicky(t_bunny_event_state, t_bunny_mouse_button,
			       t_data *);
void			free_data(t_data *);
void			mv_camera_mouse(t_data *);

/*
** SCENE
*/

void			harbor(t_data *);
void			boat(t_data *);
void			shop_place(t_data *);
void			shop(t_data *);
void			beach(t_data *);
void			house_out(t_data *);
void			house_in(t_data *);
void			basement(t_data *);
void			manor(t_data *);
void			manor_in(t_data *);
int			load_manor(t_data *);
int			load_harbor(t_data *);
int			load_beach(t_data *);
int			load_arrow(t_data *);

#endif /* _SCENE_ */
