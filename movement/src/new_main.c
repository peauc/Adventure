/*
** SCRIPT
**
** Made by clement peau
** Login   <peau_c@epitech.net>
**
** Started on  Thu Nov 19 10:13:25 2015 clement peau
** Last update Sat Apr 16 17:56:42 2016 Mathieu Sauvau
*/

#include "tekadv.h"

t_points	*get_node_byclick(t_points *node,
			  const t_bunny_position *pos)
{
  while (node)
    {
      if (pos->x >= (node->el.center.x - node->el.zaxe_a)
	  && pos->x <= (node->el.center.x + node->el.zaxe_a)
	  && pos->y >= (node->el.center.y - node->el.zaxe_b)
	  && pos->y <= (node->el.center.y + node->el.zaxe_b))
	  return (node);
      node = node->next;
    }
  return (NULL);
}

t_bunny_position	pos_player(t_player *player, t_points *node)
{
  player->node = node;
  return (player->pos = pos_(node->el.center.x - player->sp->size.x / 2,
			     node->el.center.y - player->sp->size.y));
}

/* void		aff_all2(t_bunny_pixelarray *pix, */
/* 			 t_points *list, */
/* 			 const t_bunny_position *pos) */
/* { */
/*   t_points	*it; */

/*   it = list->next; */
/*   while (it != list) */
/*     { */
/*       if (same_name(image, it->image) == 1) */
/* 	{ */
/* 	  zcircle(pix, &it->el, BLUE); */
/* 	  if (in_a_el(it, pos) == 1) */
/* 	    circle(pix, &it->el, YELLOW); */
/* 	  else */
/* 	    circle(pix, &it->el, RED); */
/* 	  line(pix, it); */
/* 	} */
/*       it = it->next; */
/*     } */
/* } */

bool			cmp_position(t_bunny_position pos1,
				     t_bunny_position pos2)
{
  if (pos1.x == pos2.x && pos1.y == pos2.y)
    return (true);
  return (false);
}

bool			cmp_node(t_points *node1, t_points *node2)
{
  return (cmp_position(node1->el.center, node2->el.center));
}

t_points		*get_node_bycoord(t_points *list, t_bunny_position coord)
{
  while (list)
    {
      if (cmp_position(list->el.center, coord))
	return (list);
      list = list->next;
    }
  return (NULL);
}

void			movement(t_bunny_keysym key, t_data *data)
{
  key = key;
  data = data;
}

/* t_points		*print_node(t_points *list) */
/* { */
/*   t_points		*it; */

/*   if (list) */
/*     { */
/*       it = list->next; */
/*       while (it != list) */
/* 	{ */
/* 	  printf("node %d %d \n", it->el.center.x, it->el.center.y); */
/* 	  it = it->next; */
/* 	} */
/*     } */
/*   return (NULL); */
/* } */

void			move_to(t_data *data,
				t_points *path, t_player *player)
{
  while (path)
    {
      usleep(100000);
      pos_player(player, path);
      bunny_blit(&data->win->buffer, &data->player->pix->clipable, &data->player->pos);
      bunny_display(data->win);
      printf("player pos %d %d\n", path->el.center.x, path->el.center.y);
      path = path->next;
    }
}

bool			node_in_list(t_points *list, t_points *node)
{
  t_points		*it;

  it = list->next;
  while (it != list)
    {
      if (cmp_node(it, node))
	return (true);
      it = it->next;
    }
  return (false);
}

t_points		*construct_path(t_points *list, t_dict *came_from,
					t_points *start, t_points *dest)
{
  t_points		*path;
  t_points		*current;

  current = look_up(came_from, dest->index);
  path = NULL;
  add_cpy_node(&path, dest);
  add_cpy_node(&path, current);
  print_node(path);
  printf("CURRENT %d %d\n", current->el.center.x, current->el.center.y);
  printf("start %d %d\n", start->el.center.x, start->el.center.y);
  printf("path %d %d\n", path->el.center.x, path->el.center.y);
  while (!cmp_node(current, start))
    {
      current = look_up(came_from, current->index);
      printf("CURRENT %d %d\n", current->el.center.x, current->el.center.y);
      add_cpy_node(&path, current);
    }
  return (path);
}

t_dict			*find_way(t_points *list,
				  t_points *start,
				  t_points *dest)
{
  t_dict		*came_from;
  t_points		*neighbor;
  t_points		*current;
  t_points		*frontier;

  if (dest == NULL || cmp_node(start, dest))
    return (NULL);
  came_from = NULL;
  frontier = NULL;
  add_cpy_node(&frontier, start);
  add_dict(&came_from, new_entry(start->index, NULL));
  print_dict(came_from);
  printf("start center %d %d\n", start->el.center.x, start->el.center.y);
  printf("dest center %d %d\n", dest->el.center.x, dest->el.center.y);
  while (frontier)
    {
      current = cpy_node(frontier);
      del_node(&frontier, current);
      printf("current %d %d\n", current->el.center.x, current->el.center.y);
      if (cmp_node(current, dest))
      	{
      	  printf("BREAK\n");
      	  break;
      	}
      if ((neighbor = get_node_bycoord(list, current->path_0[1])) != NULL
  	   && !is_in_dict(came_from, neighbor->index))
  	{
	  printf("ADD TO FRONTIER PATH 0 %d %d\n", neighbor->el.center.x, neighbor->el.center.y);
	  add_cpy_node(&frontier, neighbor);
	  add_dict(&came_from, new_entry(neighbor->index, current));
  	}
      if ((neighbor = get_node_bycoord(list, current->path_1[1])) != NULL
  	  && !is_in_dict(came_from, neighbor->index))
  	{
	  printf("ADD TO FRONTIER PATH 1 %d %d\n", neighbor->el.center.x, neighbor->el.center.y);
  	  add_cpy_node(&frontier, neighbor);
	  add_dict(&came_from, new_entry(neighbor->index, current));
  	}
      if ((neighbor = get_node_bycoord(list, current->path_2[1])) != NULL
  	  && !is_in_dict(came_from, neighbor->index))
  	{
	  printf("ADD TO FRONTIER PATH 2 %d %d\n", neighbor->el.center.x, neighbor->el.center.y);
  	  add_cpy_node(&frontier, neighbor);
	  add_dict(&came_from, new_entry(neighbor->index, current));
  	}
      if ((neighbor = get_node_bycoord(list, current->path_3[1])) != NULL
  	  && !is_in_dict(came_from, neighbor->index))
  	{
	  printf("ADD TO FRONTIER PATH 3 %d %d\n", neighbor->el.center.x, neighbor->el.center.y);
  	  add_cpy_node(&frontier, neighbor);
	  add_dict(&came_from, new_entry(neighbor->index, current));
  	}
    }
  print_dict(came_from);
  return (came_from);
}

t_bunny_response		click(t_bunny_event_state state,
				      t_bunny_mousebutton button,
				      t_data *data)
{
  const t_bunny_position	*pos;
  t_dict			*came_from;
  t_points			*dest;
  t_points			*path;
  bool				clicked;

  pos = bunny_get_mouse_position();
  if (button == BMB_RIGHT && state == GO_DOWN)
    {
      if (!clicked)
	{
	  clicked = true;
	  dest = get_node_byclick(data->node, pos);
	  came_from = find_way(data->node, data->player->node, dest);
	  if (came_from)
	    {
	      path = construct_path(data->node, came_from, data->player->node, dest);
	      print_node(path);
	      move_to(data, path, data->player);
	    }
	}
    }
  clicked = false;
  return (GO_ON);
}

t_bunny_response	escape(t_bunny_event_state state,
			       t_bunny_keysym key,
			       t_data *data)
{
  data = data;
  state = state;
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response       	mainloop(t_data *data)

{
  const t_bunny_position	*pos;

  pos = bunny_get_mouse_position();
  my_fill(data->pix, PINK);
  my_fill(data->player->pix, 0x00000000);
  anim_sprite(data->player->pix, data->player->sp, 1, 12);
  //  aff_all2(data->pix, data->p, pos, "pictures/screen1.jpg");
  bunny_blit(&data->win->buffer, &data->pix->clipable, NULL);
  bunny_blit(&data->win->buffer, &data->player->pix->clipable, &data->player->pos);
  //    bunny_blit(&data->win->buffer, &data->player->sp->pix->clipable, NULL);
  bunny_display(data->win);
  return (GO_ON);
}

t_sprite_sheet		*load_sprite_sheet(char *sprite_sheet,
					   t_bunny_position size,
					   int	anim_speed)
{
  t_sprite_sheet	*sp;

  if ((sp = bunny_malloc(sizeof(t_sprite_sheet *))) == NULL
      || (sp->pix = bunny_load_pixelarray(sprite_sheet)) == NULL)
    return (NULL);
  sp->pos = pos_(-1, 0);
  sp->size = size;
  sp->anim_speed = anim_speed;
  return (sp);
}

int			main(int ac, char **av)
{
  t_data		data;

  ac = ac;
  av = av;
  if ((data.player = bunny_malloc(sizeof(t_player))) == NULL
      || (data.player->sp = load_sprite_sheet("gimp/sprite_monkey_island.png",
					      pos_(125, 290), 40)) == NULL
      || (data.player->pix = bunny_new_pixelarray(data.player->sp->size.x,
						  data.player->sp->size.y)) == NULL
      || (data.win = bunny_start(WIDTH, HEIGHT, false, "test")) == NULL
      || (data.pix = bunny_new_pixelarray(WIDTH, HEIGHT)) == NULL)

    return (0);
  data.p = create_list();
  full_ini(data.p);
  data.node = change_list(data.p);
  print_node(data.node);
  pos_player(data.player, data.node);
  bunny_set_click_response(&click);
  bunny_set_loop_main_function((t_bunny_loop)mainloop);
  bunny_set_key_response((t_bunny_key)&escape);
  bunny_loop(data.win, 60, &data);
  return (1);
}
