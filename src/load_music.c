/*
** load_music.c for loadmusic in /home/peau_c/rendu/Lib/gfx_tekadventure
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Sun Apr 17 17:24:24 2016 Poc
** Last update Sun Apr 17 17:32:14 2016 Poc
*/

#include "scene.h"

int		load_music()
{
  t_bunny_music	*music;

  if ((music = bunny_load_music("music/theme.ogg")) == NULL)
    return (PUTERROR("Please stop removing files and go die. TY\n"), 1);
  bunny_sound_play((t_bunny_sound *)music);
  return (0);
}
