/*
** comp_string.c for comp_string in /home/wery_p/rendu/gfx_tekadventure/create_road/srcs
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Tue Apr 12 02:49:19 2016 Paul Wery
** Last update Tue Apr 12 02:57:02 2016 Paul Wery
*/

int	same_name(char *one, char *two)
{
  int	n;

  n = 0;
  while (one[n] == two[n] && one[n] != '\0' && two[n] != '\0')
    n += 1;
  if (one[n] == '\0' && two[n] == '\0')
    return (1);
  return (0);
}

int	comp_string(char *one, char *two)
{
  int	n;

  n = 0;
  while (one[n] == two[n] && one[n] != '\0' && two[n] != '\0')
    n += 1;
  if (one[n] == '\0' && two[n] != '\0')
    return (1);
  return (0);
}
