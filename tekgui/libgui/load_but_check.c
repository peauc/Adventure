/*
** load_but_check.c for libgui in /home/sauvau_m/rendu/gfx_tekgui/demo
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Wed Feb 24 14:34:18 2016 Mathieu Sauvau
** Last update Thu Feb 25 14:26:27 2016 Mathieu Sauvau
*/

#include "tekgui.h"
#include "helper.h"

void			load_checkbox_next(t_checkbox *checkbox, int i,
					  t_bunny_ini *ini, char *scope)
{
  checkbox[i].contour_color = field_to_color(ini, scope, "contour_color", 0);
  checkbox[i].contour_size = field_to_int(ini, scope, "contour_size", 0);
  checkbox[i].state = normal;
  checkbox[i].texture_state = load_texture_state(ini, scope);
  checkbox[i].space_label = field_to_int(ini, scope, "space_label", 0);
}

t_checkbox		*load_checkbox(t_bunny_ini *ini, int nb,
				       t_bunny_pixelarray *font)
{
  t_checkbox		*checkbox;
  char			scope[10];
  char			n[3];
  int			i;

  i = -1;
  if (nb == 0
      || (checkbox = bunny_malloc(sizeof(t_checkbox) * nb)) == NULL)
    return (NULL);
  while (++i < nb)
    {
      my_strcpy(scope, "checkbox_");
      itoa(i, n, 10);
      my_strcat(scope, n);
      checkbox[i].label = my_strdup((char *)BIGF(ini, scope, "label", 0));
      if ((checkbox[i].rect = load_rect(ini, scope)) == NULL
	  || (checkbox[i].label_pix =
	      bunny_new_pixelarray(my_strlen(checkbox[i].label) * 8,
				   7)) == NULL)
	return (NULL);
      load_checkbox_next(checkbox, i, ini, scope);
      my_fill(checkbox[i].label_pix, 0x00000000);
      write_png(checkbox[i].label_pix, font, checkbox[i].label);
    }
  return (checkbox);
}

void			load_buttons_next(t_button *button,
					  t_bunny_ini *ini, char *scope)
{
  char			*f;

  button->contour_color = field_to_color(ini, scope, "contour_color", 0);
  button->contour_size = field_to_int(ini, scope, "contour_size", 0);
  button->state = normal;
  button->texture_state = load_texture_state(ini, scope);
  if ((f = my_strdup((char *)(BIGF(ini, scope, "onclick", 0)))) == NULL)
    return ;
  button->onclick = tekfunction(f);
  bunny_free(f);
}

t_button		*load_buttons(t_bunny_ini *ini, int nb_button,
				      t_bunny_pixelarray *font)
{
  t_button		*button;
  char			scope[10];
  char			n[3];
  int			i;

  i = -1;
  if (nb_button == 0
      || (button = bunny_malloc(sizeof(t_button) * nb_button)) == NULL)
    return (NULL);
  while (++i < nb_button)
    {
      my_strcpy(scope, "button_");
      itoa(i, n, 10);
      my_strcat(scope, n);
      button[i].label = my_strdup((char *)BIGF(ini, scope, "label", 0));
      if ((button[i].rect = load_rect(ini, scope)) == NULL
	  || (button[i].label_pix =
	      bunny_new_pixelarray(my_strlen(button[i].label) * 8,
				   7)) == NULL)
	return (NULL);
      load_buttons_next(&button[i], ini, scope);
      my_fill(button[i].label_pix, 0x00000000);
      write_png(button[i].label_pix, font, button[i].label);
    }
  return (button);
}
