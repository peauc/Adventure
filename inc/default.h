/*
** default.h for default in /home/peau_c/bin
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Wed Feb 17 00:48:19 2016 Clement Peau
** Last update Mon Apr 11 20:22:33 2016 Mathieu Sauvau
*/

#ifndef _DEFAULT_

# define _DEFAULT_

# include <lapin.h>
# include <stdbool.h>

# define PUTERROR(X)	write(2, X, my_strlen(X))
# define PUTSTR(X)	write(1, X, my_strlen(X))

typedef struct		s_sprite_sheet
{
  int			row;
  int			col;
  t_bunny_position	pos;
  t_bunny_position	size;
  t_bunny_pixelarray	*pix;
}			t_sprite_sheet;

typedef struct		s_player
{
  t_bunny_position	pos;
  t_sprite_sheet	*sp;
  t_bunny_pixelarray	*pix;
}			t_player;

typedef struct		s_data
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pixel;
  t_player		*player;
}			t_data;

#endif /* _DEFAULT_ */
