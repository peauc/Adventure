/*
** my_strdup.c for lol in /home/peau_c/rendu/Lib/gfx_tekadventure/menu
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Apr 12 15:45:45 2016 Poc
** Last update Sun Apr 17 11:51:18 2016 marel_m
*/

#include <stdlib.h>
#include <lapin.h>

char	*my_strdup(char *str)
{
  char	*duped;

  if ((duped = bunny_malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  my_strcpy(duped, str);
  return (duped);
}
