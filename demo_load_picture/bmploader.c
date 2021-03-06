/*
** bmploader.c for loader
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Tue Jan 19 21:01:47 2016 maud marel
** Last update Fri Feb 26 16:19:31 2016 maud marel
*/

#include "bmploader.h"

t_bunny_response	my_escape(t_bunny_event_state state,
				  t_bunny_keysym keysym,
				  UNUSED void *data)
{
  if (state == GO_DOWN && keysym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response	my_loop(void *data)
{
  t_loop		*loop;

  loop = data;
  bunny_blit(&loop->win->buffer, &loop->pix->clipable, NULL);
  bunny_display(loop->win);
  return (GO_ON);
}

char			read_pixels(t_loop *loop, int fd, int h, int w)
{
  int			x;
  int			y;
  t_col			*col;
  t_color		*pixels;

  if ((col = malloc(32)) == NULL)
    return (1);
  if ((loop->pix = bunny_new_pixelarray(w, h)) == NULL)
    return (1);
  pixels = (t_color *)loop->pix->pixels;
  y = h;
  while (--y >= 0)
    {
      x = -1;
      while (++x < w)
	{
	  if ((read(fd, col, 4)) < 0)
	    return (1);
	  pixels[x + y * w].argb[0] = col->alpha;
	  pixels[x + y * w].argb[1] = col->b;
	  pixels[x + y * w].argb[2] = col->r;
	  pixels[x + y * w].argb[3] = col->a;
	}
    }
  return (0);
}

int		main(int ac, char **av, char **ev)
{
  t_head		head;
  t_bmp			bmp;
  int			ret;
  int			fd;
  t_loop		loop;

  if (ac > 1 && (ev))
    {
      if ((fd = open(av[1], O_RDONLY)) < 0 ||
	  (ret = read(fd, &head, sizeof(t_head))) < 0 ||
	  (ret = read(fd, &bmp, sizeof(t_bmp))) < 0 ||
	  lseek(fd, head.offset, SEEK_SET) < 0 ||
	  read_pixels(&loop, fd, bmp.height, bmp.width) ||
	  (loop.win = bunny_start(bmp.width, bmp.height, 0, av[1])) == NULL)
	return (-1);
      bunny_set_key_response(my_escape);
      bunny_set_loop_main_function(my_loop);
      bunny_loop(loop.win, 24, &loop);
      bunny_delete_clipable(&loop.pix->clipable);
      bunny_stop(loop.win);
    }
  return (0);
}
