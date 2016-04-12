/*
** determine_button.c for determine in /home/peau_c/rendu/Lib/gfx_tekadventure/menu
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Mon Apr 11 21:02:11 2016 Poc
** Last update Mon Apr 11 21:25:32 2016 Poc
*/

#include "menu.h"

int				determine_button_clicked(t_menu *menu)
{
  const	t_bunny_position	*pos;
  int				i;

  i = 0;
  pos = bunny_get_mouse_position();
  while (i < 4)
    {
      if (pos->x > menu->buttons[i].start.x &&
	  pos->x < menu->buttons[i].start.x +
	  menu->buttons[i].sprite->clipable.clip_width &&
	  pos->y > menu->buttons[i].start.y &&
	  pos->y < menu->buttons[i].start.y +
	  menu->buttons[i].sprite->clipable.clip_height)
	printf("I've found it\n");
      i++;
    }
  printf("%d %d\n", pos->x, pos->y);
}
