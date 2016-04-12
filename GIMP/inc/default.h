/*
** default.h for default in /home/peau_c/bin
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Wed Feb 17 00:48:19 2016 Clement Peau
** Last update Tue Apr 12 16:02:46 2016 marel_m
*/

#ifndef _DEFAULT_

# define _DEFAULT_

# include <lapin.h>
# include <stdbool.h>

# define PUTERROR(X)	write(2, X, my_strlen(X))
# define PUTSTR(X)	write(1, X, my_strlen(X))
# define WIDTH 1280
# define HEIGHT 720

typedef struct		s_scene
{
  t_bunny_pixelarray	*back;
  t_bunny_pixelarray	*middle;
  t_bunny_pixelarray	*front;
  char			*name;
}			t_scene;

typedef struct		s_data
{
  t_scene		tab[11];
  t_bunny_window	*win;
  t_bunny_pixelarray	*new;
  t_bunny_pixelarray	*pixel;
  t_bunny_pixelarray	*harbor;
  t_bunny_pixelarray	*harbor_fr;
}			t_data;

#endif /* _DEFAULT_ */
