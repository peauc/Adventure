/*
** default.h for default in /home/peau_c/bin
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Wed Feb 17 00:48:19 2016 Clement Peau
** Last update Sun Apr 17 21:21:28 2016 Poc
*/

#ifndef _TEKADV_H_
# define _TEKADV_H_

# include <lapin.h>
# include <stdbool.h>
# include "lib.h"
# include "item.h"
# include "road.h"

# define PUTERROR(X)    write(2, X, my_strlen(X))
# define PUTSTR(X)      write(1, X, my_strlen(X))
# define WIDTH 1024
# define HEIGHT 768
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

typedef struct          s_button
{
  char                  *name;
  t_bunny_pixelarray    *sprite;
  t_bunny_pixelarray    *active_sprite;
  t_bunny_position      start;
  t_bunny_position      end;
  int                   is_clicked;
}                       t_button;

typedef struct          s_menu
{
  t_button              *buttons;
}                       t_menu;

typedef struct          s_scene
{
  t_bunny_pixelarray    *back;
  t_bunny_pixelarray    *middle;
  t_bunny_pixelarray    *front;
  t_item                *item;
  char                  *name;
}                       t_scene;

typedef struct                  s_mv_scene
{
  int                           mv_bck;
  int                           mv_mid;
  int                           mv_fr;
  int                           s_nb;
  int                           click;
  const t_bunny_position        *pos_click;
  t_bunny_position		mouse;
  int                           old_mouse;
}                               t_mv_scene;

typedef struct                  s_data
{
  t_scene                       tab[14];
  t_mv_scene                    *mv_s;
  t_bunny_window                *win;
  t_bunny_pixelarray            *new;
  t_bunny_pixelarray            *pixel;
  t_menu                        *menu;
  t_player                      *player;
  t_points                      *p;
  t_points                      *node;
}                               t_data;

enum                    scene
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

typedef struct          s_scene_nb
{
  int                   scene_nb;
  int                  (*ft_scene_nb)(t_data *data);
}                       t_scene_nb;

/*
** SPRITE SHEET
*/
void			cpy_color(t_bunny_pixelarray *out, t_bunny_pixelarray *src,
				  t_bunny_position o_pos,
				  t_bunny_position pos);
void			cpy_sprite(t_bunny_pixelarray *out, t_sprite_sheet *sp,
				   int col, int row);
void			anim_sprite(t_bunny_pixelarray *out, t_sprite_sheet *sp,
				    t_flip flip, int limit_col);
t_flip			get_row_anim(t_bunny_position start, t_bunny_position end);
t_bunny_position	pos_player(t_player *player, t_points *node);

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
** MOVEMENT
*/
void                    move_to(t_data *data, t_bunny_position dest);
void                    move(t_data *data,
			     t_points *path, t_player *player);

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
** INIT
*/
int                     load_all_scene(t_data *);
int                     load_buttons(t_menu *);
int                     load_item(t_menu *, t_bunny_ini *);
int                     load_item_basement(t_scene *);
int                     load_music();
int                     load_scene_tab(t_scene[14]);
int                     init_scene(t_scene[14]);
t_menu                  *load_menu();
void                    set_all_to_zero(t_button *);

/*
** DISPLAY
*/
int                     draw_menu(t_bunny_pixelarray *, t_menu *);
int                     draw_scene(t_data *);
int                     draw_inventory(t_bunny_pixelarray *, t_scene[14]);
int                     draw_items(t_item *, t_bunny_pixelarray *);
t_bunny_pixelarray      *resize_picture(t_bunny_pixelarray *, int, int);
void                    pixelarray_copy(t_bunny_pixelarray *,
					t_bunny_pixelarray *,
					t_bunny_position);
void                    put_pix_in_pix(t_bunny_pixelarray *,
				       t_bunny_pixelarray *,
				       t_bunny_position,
				       int);
void                    put_pix_in_pix_mv(t_bunny_pixelarray *,
					  t_bunny_pixelarray *,
					  t_bunny_position,
					  int);
void                    pix_initialize(t_bunny_pixelarray *);
void                    show_player(t_data *data, t_flip flip);

/*
** ACTION
*/
int                     determine_button_clicked(t_menu *);
int                     determine_item(t_scene);
int                     is_clicked(t_bunny_position *,
				   t_bunny_pixelarray *,
				   t_bunny_position);
t_bunny_position        get_pos(int, int);
t_bunny_response        clicky(t_bunny_event_state, t_bunny_mouse_button,
			       t_data *);
void                    mv_camera_mouse(t_data *);

/*
** SCENE
*/
int                     load_manor(t_data *);
int                     load_harbor(t_data *);
int                     load_beach(t_data *);
int                     load_arrow(t_data *);
int                    harbor(t_data *);
int                    boat(t_data *);
int                    shop_place(t_data *);
int                    shop(t_data *);
int                    beach(t_data *);
int                    house_out(t_data *);
int                    house_in(t_data *);
int                    basement(t_data *);
int                    manor(t_data *);
int                    manor_in(t_data *);

/*
** LIB/FREE
*/
char                    *my_strdup(char *);
void                    free_data(t_data *);

#endif /* ! _TEKADV_H_ */
