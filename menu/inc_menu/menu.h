/*
** default.h for default in /home/peau_c/bin
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Wed Feb 17 00:48:19 2016 Clement Peau
** Last update Tue Apr 12 15:38:15 2016 Poc
*/

#ifndef _MENU_

# define _MENU_

# include <lapin.h>
# include <stdio.h>

# define HEIGHT 720
# define WIDTH	1280
# define PUTERROR(X)	write(2, X, my_strlen(X))
# define PUTSTR(X)	write(1, X, my_strlen(X))

typedef	struct	s_button
{
  char			*name;
  t_bunny_pixelarray	*sprite;
  t_bunny_position	start;
  t_bunny_position	end;
  int			is_clicked;
}		t_button;

typedef struct	s_menu
{
  t_button		*buttons;
}		t_menu;

typedef struct s_data
{
  t_bunny_window	*window;
  t_bunny_pixelarray	*pixel;
  t_menu		*menu;
}		t_data;


#endif /* !_MENU_ */
