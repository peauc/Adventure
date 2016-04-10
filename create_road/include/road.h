/*
** road.h for road in /home/wery_p/rendu/gfx_tekadventure/create_road
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Wed Apr  6 22:23:37 2016 Paul Wery
** Last update Sun Apr 10 15:31:01 2016 Paul Wery
*/

#ifndef ROAD
#define ROAD

#define WINL (1920)
#define WINH (1080)

#define UNUSED __attribute__((unused))

#include <lapin.h>
#include "struct_line.h"

typedef struct		s_el
{
  t_bunny_position	center;
  int			axe_a;
  int			axe_b;
}			t_el;

typedef struct		s_points
{
  struct s_el		el;
  struct s_line		line;
  struct s_points	*next;
  struct s_points	*prev;
}			t_points;

typedef struct		s_road
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*back;
  struct s_points	*points;
}			t_road;

t_bunny_response	my_click(t_bunny_event_state state,
				 t_bunny_mousebutton button,
				 void *your_data);
t_bunny_response	key(t_bunny_event_state state,
			    t_bunny_keysym keysym,
			    void *data);
t_bunny_response	loop(void *data);


t_points	*create_list(void);
int		add_elem_next(t_points *elem, t_points *src);
void		delete_list(t_points **root);


void			pix_initialize(t_bunny_pixelarray *pix);
void			pix_initialize_alpha(t_bunny_pixelarray *pix);
t_bunny_pixelarray	*resize_picture(t_bunny_pixelarray *pix,
					int width, int height);
void			pix_initialize(t_bunny_pixelarray *pix);
void			pix_initialize_alpha(t_bunny_pixelarray *pix);
void			cop_pix(t_bunny_pixelarray *dest,
				t_bunny_pixelarray *src);
void			line(t_bunny_pixelarray *pix,
			     t_line *point);
void			tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 unsigned int color);

#endif /* !ROAD */
