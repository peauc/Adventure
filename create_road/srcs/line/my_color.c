/*
** my_color.c for my_color in /home/wery_p/rendu/gfx_tekadventure/create_road/srcs/line
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Mon Apr 11 18:25:47 2016 Paul Wery
** Last update Mon Apr 11 18:25:48 2016 Paul Wery
*/

#include "road.h"

unsigned int	change_color0(t_line *l, unsigned int *color)
{
  unsigned int	result;
  long		red0;
  long		green0;
  long		blue0;
  int		sred;
  int		sgreen;
  int		sblue;

  sred = l->red * -1;
  sgreen = l->gre * -1;
  sblue = l->blue * -1;
  red0 = (0x000000FF & color[0]);
  green0 = (0x0000FF00 & color[0]) >> 8;
  blue0 = (0x00FF0000 & color[0]) >> 16;
  if ((red0 + sred) >= 0 || (red0 + sred) <= 255)
    red0 = red0 + sred;
  if ((green0 + sgreen) >= 0 || (green0 + sgreen) <= 255)
    green0 = green0 + sgreen;
  if ((blue0 + sblue) >= 0 || (blue0 + sblue) <= 255)
    blue0 = blue0 + sblue;
  red0 = (0x000000FF & red0);
  green0 = (0x000000FF & green0) << 8;
  blue0 = (0x000000FF & blue0) << 16;
  result = blue0 + green0 + red0;
  return (result);
}

void		cal_color(int ch, unsigned int *color, t_line *l)
{
  unsigned int	red;
  unsigned int	green;
  unsigned int	blue;
  unsigned int	red2;
  unsigned int	green2;
  unsigned int	blue2;

  red = (0x000000FF & color[0]);
  red2 = (0x000000FF & color[1]);
  green = (0x0000FF00 & color[0]) >> 8;
  green2 = (0x0000FF00 & color[1]) >> 8;
  blue = (0x00FF0000 & color[0]) >> 16;
  blue2 = (0x00FF0000 & color[1]) >> 16;
  l->red += ((double)red - (double)red2) / (double)ch;
  l->gre += ((double)green - (double)green2) / (double)ch;
  l->blue += ((double)blue - (double)blue2) / (double)ch;
}

void	initialize_save_color(t_line *l)
{
  l->red = 0;
  l->gre = 0;
  l->blue = 0;
}

unsigned int	my_color(const t_bunny_position *pos,
			 unsigned int *color, t_line *l)
{
  int		ch;
  int		val1;
  int		val2;
  unsigned int	alpha;

  val1 = pos[0].x - pos[1].x;
  val2 = pos[0].y - pos[1].y;
  if (val1 < 0)
    val1 = val1 * -1;
  if (val2 < 0)
    val2 = val2 * -1;
  ch = (val1 > val2 ? val1 : val2);
  if (l->check == 0)
    initialize_save_color(l);
  cal_color(ch, color, l);
  alpha = (0xFF000000 & color[0]);
  l->nwc = alpha + change_color0(l, color);
  return (l->nwc);
}
