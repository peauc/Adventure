/*
** default.h for default in /home/peau_c/bin
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Wed Feb 17 00:48:19 2016 Clement Peau
** Last update Sat Apr 16 17:29:08 2016 Mathieu Sauvau
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

/*
** HELPER
*/
void                    my_fill(t_bunny_pixelarray *pix_ar, unsigned int color);
t_bunny_position	pos_(int x, int y);


/*
** NODE
*/
t_points		*check_all_pathcoord(t_points *list, t_points *it, t_points *dest);
t_points		*get_node_byclick(t_points *node,
					  const t_bunny_position *pos);
t_points		*get_point_bycoord(t_points *list, t_bunny_position coord);
bool			cmp_node(t_points *node1, t_points *node2);

/*
** NODE LIST
*/
void		add_node(t_points **list, t_points *node);
t_points	*change_list(t_points *list);
void		print_node(t_points *list);
void		free_node(t_points *list);
void		del_node(t_points **list, t_points *node);
t_points	*cpy_node(t_points *point);
void		add_cpy_node(t_points **list, t_points *node);
void		push_back(t_points **head, t_points *node);

/*
** DICTIONARY
*/
t_dict			*new_entry(int key, t_points *val);
void			add_dict(t_dict **dict, t_dict *new);
void			print_dict(t_dict *dict);
bool			is_in_dict(t_dict *dict, int key);
t_points		*look_up(t_dict *dict, int key);

#endif /* ! _TEKADV_H_ */
