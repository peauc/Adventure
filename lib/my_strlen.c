/*
** my_strlen.c for streln in /home/peau_c/rendu/Lib/gfx_tekadventure/menu
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Apr 12 15:53:13 2016 Poc
** Last update Tue Apr 12 15:53:33 2016 Poc
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
