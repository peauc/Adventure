/*
** load_music.c for loadmusic in /home/peau_c/rendu/Lib/gfx_tekadventure
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Sun Apr 17 17:24:24 2016 Poc
** Last update Sun Apr 17 18:00:24 2016 Poc
*/

#include <unistd.h>
#include "scene.h"

int		load_music()
{
  static t_bunny_music	*music = NULL;

  if (music == NULL)
    {
      if ((music = bunny_load_music("music/theme.ogg")) == NULL)
	return (PUTERROR("Please stop removing files and go die. TY\n"), 1);
      bunny_sound_play((t_bunny_sound *)music);
      bunny_sound_loop((t_bunny_sound *)music, 1);
    }
  else
    {
      bunny_sound_stop((t_bunny_sound *)music);
      bunny_delete_sound((t_bunny_sound *)music);
    }
  return (0);
}
