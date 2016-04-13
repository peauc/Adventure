/*
** default.h for default in /home/peau_c/bin
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Wed Feb 17 00:48:19 2016 Clement Peau
** Last update Wed Apr 13 14:54:34 2016 marel_m
*/

#ifndef _DEFAULT_

# define _DEFAULT_

# include <lapin.h>
# include <stdbool.h>

# define PUTERROR(X)	write(2, X, my_strlen(X))
# define PUTSTR(X)	write(1, X, my_strlen(X))
# define WIDTH 1024
# define HEIGHT 768

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
}			t_data;

int			load_all_scene(t_data *);
char			*my_strdup(char *);

t_bunny_pixelarray	*resize_picture(t_bunny_pixelarray *, int, int);
void			pix_initialize(t_bunny_pixelarray *);
void			boat(t_data *);
void			put_pix_in_pix_txt(t_bunny_pixelarray *,
					   t_bunny_pixelarray *,
					   t_bunny_position);

#endif /* _DEFAULT_ */
