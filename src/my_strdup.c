/*
** my_strdup.c for my_strdup in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris/lib/my
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Tue Mar  8 09:15:03 2016 maud marel
** Last update Sun Apr 17 11:45:26 2016 marel_m
*/

#include <stdlib.h>
#include <lapin.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str && str[i] != '\0')
    i++;
  return (i);
}

char	*my_strdup(char *str)
{
  char	*new;
  int	i;

  i = 0;
  if (str == NULL
      || (new = bunny_malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str && str[i])
    {
      new[i] = str[i];
      i++;
    }
  new[i] = '\0';
  return (new);
}
