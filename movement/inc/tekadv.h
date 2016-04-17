/*
** default.h for default in /home/peau_c/bin
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Wed Feb 17 00:48:19 2016 Clement Peau
<<<<<<< HEAD
** Last update Sun Apr 17 15:48:59 2016 Mathieu Sauvau
=======
** Last update Sat Apr 16 17:29:08 2016 Mathieu Sauvau
>>>>>>> 42d64d8101a8f5c2fc0d7893be20260f02b5ecd7
*/

#ifndef _TEKADV_H_

# define _TEKADV_H_

# include <lapin.h>
# include <stdbool.h>
# include "road.h"

# define PUTERROR(X)	write(2, X, my_strlen(X))
# define PUTSTR(X)	write(1, X, my_strlen(X))
# define WIDTH 1000
# define HEIGHT 1000
# define BIGF bunny_ini_get_field

typedef struct		s_sprite_sheet
{
  int			col;
  int			row;
  int			speed_cursor;
  int			anim_speed;
  t_bunny_position	pos;
  t_bunny_position	size;
  t_bunny_pixelarray	*pix;
}			t_sprite_sheet;

typedef struct		s_player
{
  t_bunny_position	pos;
  t_points		*node;
  t_sprite_sheet	*sp;
  t_bunny_pixelarray	*pix;
}			t_player;

typedef struct		s_data
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_player		*player;
  t_points		*p;
  t_points		*node;
}			t_data;

typedef struct		s_dict
{
  int			key;
  t_points		*val;
  struct s_dict		*next;
}			t_dict;

typedef struct		t_flip
{
  int			row;
  int			flip;
}			t_flip;

/*
** SPRITE SHEET
*/
void			cpy_color(t_bunny_pixelarray *out, t_bunny_pixelarray *src,
				  t_bunny_position o_pos,
				  t_bunny_position pos);
void			cpy_sprite(t_bunny_pixelarray *out, t_sprite_sheet *sp,
				   int col, int row);
void			anim_sprite(t_bunny_pixelarray *out, t_sprite_sheet *sp,
				    int start_row, int limit_col);
t_flip			get_row_anim(t_bunny_position start, t_bunny_position end);

/*
** PATHFINDING
*/
t_points		*construct_path(t_dict *came_from,
					t_points *start, t_points *dest);
t_dict			*find_way(t_points *list,  t_points *start, t_points *dest);

/*
** HELPER
*/
void				my_fill(t_bunny_pixelarray *pix_ar, unsigned int color);
t_bunny_position		pos_(int x, int y);
t_bunny_accurate_position	posac_(double x, double y);
bool				cmp_position(t_bunny_position pos1,
					     t_bunny_position pos2);

/*
** NODE
*/
t_points		*check_all_pathcoord(t_points *list, t_points *it, t_points *dest);
t_points		*get_node_byclick(t_points *node,
					  const t_bunny_position *pos);
t_points		*get_point_bycoord(t_points *list, t_bunny_position coord);
bool			cmp_node(t_points *node1, t_points *node2);
t_points		*get_node_byclick(t_points *node,
				  const t_bunny_position *pos);
t_points		*get_node_bycoord(t_points *list, t_bunny_position coord);
bool			node_in_list(t_points *list, t_points *node);

/*
** NODE LIST
*/
t_points	*change_list(t_points *list);
void		print_node(t_points *list);
void		free_node(t_points *list);
void		del_node(t_points **list, t_points *node);
t_points	*cpy_node(t_points *point);
void		add_cpy_node(t_points **list, t_points *node);
void		clear_node(t_points *list);

/*
** DICTIONARY
*/
t_dict			*new_entry(int key, t_points *val);
void			add_dict(t_dict **dict, t_dict *new);
void			print_dict(t_dict *dict);
bool			is_in_dict(t_dict *dict, int key);
t_points		*look_up(t_dict *dict, int key);
void			clear_dict(t_dict *dict);

/*
** MOVEMENT
*/
void			move_to(t_data *data, t_bunny_position dest);
void			move(t_data *data,
			     t_points *path, t_player *player);

#endif /* ! _TEKADV_H_ */
