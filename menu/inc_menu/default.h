/*
** default.h for default in /home/peau_c/bin
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Wed Feb 17 00:48:19 2016 Clement Peau
** Last update Mon Apr 11 20:29:21 2016 Poc
*/

#ifndef _DEFAULT_

# define _DEFAULT_

# include <lapin.h>

# define HEIGHT 720
# define WIDTH	1280
# define PUTERROR(X)	write(2, X, my_strlen(X))
# define PUTSTR(X)	write(1, X, my_strlen(X))

typedef struct s_data
{
  t_bunny_window	*window;
  t_bunny_pixelarray	*pixel;
}		t_data;

typedef	struct	s_button
{
  t_bunny_pixelarray	*sprite;
  t_bunny_position	start;
  t_bunny_position	end;
  int			is_clicked;
}		t_button;

typedef struct	s_menu
{
  t_button		*buttons;
}		t_menu;

#endif /* _DEFAULT_ */
