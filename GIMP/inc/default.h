/*
** default.h for default in /home/peau_c/bin
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Wed Feb 17 00:48:19 2016 Clement Peau
** Last update Fri Apr 15 13:58:55 2016 Poc
*/

#ifndef _DEFAULT_

# define _DEFAULT_

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
  t_item		item;
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
}				t_mv_scene;

typedef struct			s_data
{
  t_scene			tab[11];
  t_mv_scene			mv_s;
  t_bunny_window		*win;
  t_bunny_pixelarray		*new;
  t_bunny_pixelarray		*pixel;
  t_menu			*menu;
}				t_data;

int			load_all_scene(t_data *);
int			load_item(t_menu *, t_bunny_ini *);
char			*my_strdup(char *);
t_menu			*load_menu();
void			pixelarray_copy(t_bunny_pixelarray *,
					 t_bunny_pixelarray *,
					 t_bunny_position);
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
#endif /* _DEFAULT_ */
