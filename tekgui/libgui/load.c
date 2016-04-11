/*
** load.c for libgui in /home/sauvau_m/rendu/gfx_tekgui/demo
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Wed Feb 24 14:14:25 2016 Mathieu Sauvau
** Last update Sun Feb 28 16:11:51 2016 Mathieu Sauvau
*/

#include "tekgui.h"

t_gui_texture		*load_gui_texture(t_bunny_ini *ini,
					  char *scope, char *field)
{
  t_gui_texture		*texture;
  char			*file;

  if ((texture = bunny_malloc(sizeof(t_gui_texture))) == NULL
      || (texture->border = load_border(ini, scope)) == NULL
      || (file = (char *)BIGF(ini, scope, field, 0)) == NULL
      || (texture->texture = bunny_load_pixelarray(file)) == NULL)
    return (NULL);
  return (texture);
}

t_texture_state		*load_texture_state(t_bunny_ini *ini, char *scope)
{
  t_texture_state	*texture_state;

  if ((texture_state = bunny_malloc(sizeof(t_texture_state))) == NULL)
    return (NULL);
  texture_state->normal = LGT(ini, scope, "texture_normal");
  texture_state->on = LGT(ini, scope, "texture_on");
  texture_state->over = LGT(ini, scope, "texture_over");
  texture_state->over_on = LGT(ini, scope, "texture_over_on");
  return (texture_state);
}

void			button_click(t_tekgui *gui, t_button *button)
{
  if (clicked_left(button))
    {
      if (button->onclick)
	button->onclick(gui);
    }
}

t_bunny_response	click(t_bunny_event_state state,
			      t_bunny_mouse_button mouse_button,
			      void *data)
{
  t_tekgui		*gui;
  int			i;

  gui = data;
  i = -1;
  while (++i < gui->nb_button)
    button_click(gui, &gui->button[i]);
  i = -1;
  while (++i < gui->nb_checkbox)
    clicked_checkbox(&gui->checkbox[i], mouse_button, state);
  return (GO_ON);
}

t_tekgui		*tekguiload(const char *file)
{
  t_tekgui		*gui;

  load_config_ram();
  if ((gui = bunny_malloc(sizeof(t_tekgui))) == NULL
      || (gui->pix_ar_gui = bunny_new_pixelarray(800, 600)) == NULL
      || (gui->pix_ar_write = bunny_new_pixelarray(800, 600)) == NULL
      || (gui->font = bunny_load_pixelarray("font.png")) == NULL
      || (gui->ini = bunny_load_ini(file)) == NULL)
    return (NULL);
  gui->bg_color = WHITE;
  gui->nb_button = field_to_int(gui->ini, "gui_nb", "nb_button", 0);
  gui->nb_checkbox = field_to_int(gui->ini, "gui_nb", "nb_checkbox", 0);
  gui->nb_image = field_to_int(gui->ini, "gui_nb", "nb_img", 0);
  gui->nb_text = field_to_int(gui->ini, "gui_nb", "nb_txt", 0);
  gui->button = load_buttons(gui->ini, gui->nb_button, gui->font);
  gui->checkbox = load_checkbox(gui->ini, gui->nb_checkbox, gui->font);
  gui->img = load_img(gui->ini, gui->nb_image, gui->font);
  gui->text = load_text(gui->ini, gui->nb_text, gui->font);
  my_fill(gui->pix_ar_gui, 0x00000000);
  my_fill(gui->pix_ar_write, 0x00000000);
  bunny_delete_ini(gui->ini);
  bunny_set_click_response(click);
  return (gui);
}
