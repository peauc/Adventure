/*
** my_strdup.c for strdup in /home/sauvau_m/rendu/Piscine_C_J08/ex_01
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Wed Oct  7 09:52:07 2015 Mathieu Sauvau
** Last update Tue Feb 23 11:44:39 2016 Mathieu Sauvau
*/

#include <stdlib.h>
#include <lapin.h>
#include "helper.h"

char	*my_strdup(char *src)
{
  char *str;

  if (src == NULL
      ||(str = bunny_malloc(my_strlen(src) + 1)) == NULL)
    return (NULL);
  my_strcpy(str, src);
  return (str);
}
