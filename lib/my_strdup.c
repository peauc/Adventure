/*
** my_strdup.c for lol in /home/peau_c/rendu/Lib/gfx_tekadventure/menu
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Apr 12 15:45:45 2016 Poc
** Last update Tue Apr 12 16:05:53 2016 Poc
*/

#include <stdlib.h>

char	*my_strdup(char *str)
{
  char	*duped;

  if ((duped = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  my_strcpy(duped, str);
  return (duped);
}
