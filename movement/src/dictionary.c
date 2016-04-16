/*
** dictionary.c for  in /home/sauvau_m/rendu/gfx_tekadventure
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Fri Apr 15 17:30:48 2016 Mathieu Sauvau
** Last update Sat Apr 16 17:11:19 2016 Mathieu Sauvau
*/

#include "tekadv.h"

t_points		*look_up(t_dict *dict, int key)
{
  while (dict)
    {
      printf("dict key %d ", dict->key);
      printf("compare %d \n", key);
      if (dict->key == key)
	return (printf("add %d %d\n", dict->val->el.center.x,
		       dict->val->el.center.y), dict->val);
      dict = dict->next;
    }
  return (NULL);
}

t_dict			*new_entry(int key, t_points *val)
{
  t_dict		*new;

  if ((new = malloc(sizeof(t_dict))) == NULL)
    return (NULL);
  new->key = key;
  new->val = cpy_node(val);
  new->next = NULL;
  return (new);
}

void			add_dict(t_dict **dict, t_dict *new)
{
  if (!*dict)
    *dict = new;
  else
    {
      new->next = *dict;
      *dict = new;
      printf("add dict val %d %d\n", new->val->el.center.x, new->val->el.center.y);
    }
}

void			print_dict(t_dict *dict)
{
  while (dict)
    {
      printf("key %d", dict->key);
      if (dict->val)
	printf(" val %d %d\n",
	       dict->val->el.center.x, dict->val->el.center.y);
      else
	printf("\n");
      dict = dict->next;
    }
}

bool			is_in_dict(t_dict *dict, int key)
{
  while (dict)
    {
      if (dict->key == key)
	{
	  printf("IN dic key %d\n", key);
	  return (true);
	}
      dict = dict->next;
    }
  return (false);
}
