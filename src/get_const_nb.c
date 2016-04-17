/*
** get_const_nb.c for get_const_nb in /home/wery_p/rendu/gfx_tekadventure/src
**
** Made by Paul Wery
** Login   <wery_p@epitech.net>
**
** Started on  Sun Apr 17 22:05:24 2016 Paul Wery
** Last update Sun Apr 17 22:05:37 2016 Paul Wery
*/

int	get_nb(const char *str, int val, int n, int neg)
{
  if (str[n] == '-')
    {
      n += 1;
      neg = 1;
    }
  while (str[n] != '\0')
    {
      val = (val * 10) + (str[n] - 48);
      n += 1;
    }
  if (neg == 1)
    val = val * -1;
  return (val);
}
