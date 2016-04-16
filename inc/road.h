/*
** road.h for road in /home/wery_p/rendu/gfx_tekadventure/create_road
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Wed Apr  6 22:23:37 2016 Paul Wery
** Last update Sat Apr 16 13:40:45 2016 Mathieu Sauvau
*/

#ifndef ROAD
#define ROAD

#define WINL (1920)
#define WINH (1080)

#define UNUSED __attribute__((unused))

#include <lapin.h>

typedef struct	s_line
{
  t_color	mew;
  unsigned int	nwc;
  float		i;
  int		j;
  float		y;
  int		z;
  int		check;
  double	red;
  double	gre;
  double	blue;
}		t_line;

typedef struct		s_cir
{
  int			i;
  double		angle;
  t_bunny_position	posi;
}			t_cir;

typedef struct	s_my_scale
{
  double	scale_x;
  double	scale_y;
}		t_my_scale;

typedef struct	s_resize
{
  double	x_one;
  double	y_one;
  double	x_two;
  double	y_two;
  t_color	*color;
  t_color	*pixel;
  int		i;
}		t_resize;

typedef struct		s_el
{
  t_bunny_position	center;
  int			axe_a;
  int			axe_b;
  int			zaxe_a;
  int			zaxe_b;
}			t_el;

typedef struct		s_points
{
  struct s_el		el;
  t_bunny_position	path_0[2];
  t_bunny_position	path_1[2];
  t_bunny_position	path_2[2];
  t_bunny_position	path_3[2];
  int			path;
  int			index;
  char			*image;
  struct s_points	*next;
  struct s_points	*prev;
}			t_points;

typedef struct		s_road
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*back;
  struct s_points	points;
  struct s_points	*list;
  int			state;
  char			*image;
}			t_road;

t_bunny_response	my_click(t_bunny_event_state state,
				 t_bunny_mousebutton button,
				 void *your_data);
void			click_next(t_bunny_event_state state,
				   t_bunny_mousebutton button,
				   const t_bunny_position *pos,
				   t_road *r);
t_bunny_response	key(t_bunny_event_state state,
			    t_bunny_keysym keysym,
			    void *data);
t_bunny_response	loop(void *data);
t_bunny_response	wheel_mouse(int wheelid, int delta,
				    void *data);


t_points		*create_list(void);
int			add_elem_next(t_points *elem, t_points *src);
void			delete_elem(t_points *list, t_points *elem);
void			delete_list(t_points **root);
void			delete_links(t_points *list, t_points *elem);


void			pix_initialize(t_bunny_pixelarray *pix);
void			pix_initialize_alpha(t_bunny_pixelarray *pix);
t_bunny_pixelarray	*resize_picture(t_bunny_pixelarray *pix,
					int width, int height);
void			pix_initialize(t_bunny_pixelarray *pix);
void			pix_initialize_alpha(t_bunny_pixelarray *pix);
void			cop_pix(t_bunny_pixelarray *dest,
				t_bunny_pixelarray *src);
void			tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 unsigned int color);
void			ini_struct(t_road *r);
void			aff_tmp(t_road *r);
void			aff_all(t_road *r, const t_bunny_position *pos);
void			aff_all2(t_bunny_pixelarray *pix,
			t_points *list,
			const t_bunny_position *pos,
			char *image);
int			in_a_el(t_points *it, const t_bunny_position *pos);
t_bunny_position	*in_el(t_road *r,
			      const t_bunny_position *pos);
t_points		*get_elem(t_road *r,
				  const t_bunny_position *pos);
void			circle(t_bunny_pixelarray *pix,
			       t_el *el, unsigned int color);
void			zcircle(t_bunny_pixelarray *pix,
				t_el *el, unsigned int color);

void			tekline(t_bunny_pixelarray *pix,
				t_bunny_position *pos,
				t_color *color);
void			ini_col(unsigned int *col,
				t_color *color, t_line *l);
void			ini_line(t_line *l, t_bunny_position *posi,
				 t_bunny_position *pos);
unsigned int		my_color(const t_bunny_position *pos,
				 unsigned int *color, t_line *l);
void			line(t_bunny_pixelarray *pix, t_points *it);
void			ini_el(t_road *r, const t_bunny_position *pos);
int			cop_path(t_bunny_position *start, t_points *it);
int			full_ini(t_points *list);
int			comp_string(char *one, char *two);
int			same_name(char *one, char *two);

#endif /* !ROAD */
