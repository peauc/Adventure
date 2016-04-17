/*
** dictionary.c for  in /home/sauvau_m/rendu/gfx_tekadventure
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Fri Apr 15 17:30:48 2016 Mathieu Sauvau
** Last update Sun Apr 17 17:49:53 2016 Mathieu Sauvau
*/

#include "tekadv.h"

t_points		*look_up(t_dict *dict, int key)
{
  while (dict)
    {
      if (dict->key == key)
	return (dict->val);
      dict = dict->next;
    }
  return (NULL);
}

t_dict			*new_entry(int key, t_points *val)
{
  t_dict		*new;

  if ((new = bunny_malloc(sizeof(t_dict))) == NULL)
    return (NULL);
  new->key = key;
  new->val = cpy_node(val);
  new->next = NULL;
  return (new);
}

void			add_dict(t_dict **dict, t_dict *new)
{
  if (!new)
    return ;
  if (!*dict)
    *dict = new;
  else
    {
      new->next = *dict;
      *dict = new;
    }
}

bool			is_in_dict(t_dict *dict, int key)
{
  while (dict)
    {
      if (dict->key == key)
	return (true);
      dict = dict->next;
    }
  return (false);
}

void			clear_dict(t_dict *dict)
{
  t_dict		*tmp;

  while (dict)
    {
      tmp = dict;
      dict = dict->next;
      bunny_free(tmp);
    }
  bunny_free(dict);
}
