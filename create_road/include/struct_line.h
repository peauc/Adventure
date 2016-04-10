/*
** struct_line.h for struct_line in /home/wery_p/rendu/gfx_tekadventure/create_road/include
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sun Apr 10 15:29:34 2016 Paul Wery
** Last update Sun Apr 10 15:35:23 2016 Paul Wery
*/

#ifndef LINE
#define LINE

typedef struct		s_line
{
  t_bunny_position      one;
  t_bunny_position      two;
  int			width;
}			t_line;

void	line(t_bunny_pixelarray *pix,
             t_line *point);

#endif /* LINE */
