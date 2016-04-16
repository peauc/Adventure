/*
** my_strcpy.c for lol in /home/peau_c/rendu/Lib/gfx_tekadventure/menu
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue Apr 12 16:03:49 2016 Poc
** Last update Tue Apr 12 16:11:31 2016 Poc
*/

void	my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = 0;
}
