/*
** tekgui.h for tekgui in /home/sauvau_m/rendu/gfx_tekgui/include
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Wed Feb 17 09:31:46 2016 Mathieu Sauvau
** Last update Sun Feb 28 21:32:50 2016 Mathieu Sauvau
*/

#ifndef _TEKGUI_H_

#define _TEKGUI_H_o
# include <lapin.h>
# include "libgui.h"

typedef struct		s_tekgui
{
  t_bunny_position	pos;
  t_bunny_ini		*ini;
  t_bunny_pixelarray	*pix_ar;
  t_bunny_pixelarray	*pix_ar_gui;
  t_bunny_pixelarray	*pix_ar_write;
  t_bunny_pixelarray	*font;
  t_bunny_window	*win;
  int			bg_color;
  int			nb_button;
  int			nb_checkbox;
  int			nb_image;
  int			nb_text;
  t_button		*button;
  t_checkbox		*checkbox;
  t_img			*img;
  t_text		*text;
}			t_tekgui;

/*
** MANDATORY FUNCTIONS
*/
t_tekgui		*tekguiload(const char *);
void			tekgui_display(t_bunny_pixelarray *,
				       t_tekgui *);
void			*tekfunction(const char *funcname);

/*
** OTHER
*/
void			load_config_ram();
t_button		*load_buttons(t_bunny_ini *ini, int nb_button,
				      t_bunny_pixelarray *font);
t_checkbox		*load_checkbox(t_bunny_ini *ini, int nb,
				       t_bunny_pixelarray *font);
t_img			*load_img(t_bunny_ini *ini, int nb,
				  t_bunny_pixelarray *font);
t_text			*load_text(t_bunny_ini *ini, int nb,
				   t_bunny_pixelarray *font);
t_texture_state		*load_texture_state(t_bunny_ini *ini, char *scope);
t_gui_texture		*load_gui_texture(t_bunny_ini *ini, char *scope,
					  char *field);
void			free_all(t_tekgui *gui);
void			free_next(t_tekgui *gui);
void			free_gui_texture(t_gui_texture *texture);
void			free_texture_state(t_texture_state *texture_state);
t_border		*load_border(t_bunny_ini *ini, char *scope);
t_rect			*load_rect(t_bunny_ini *ini, char *scope);
unsigned int		field_to_color(t_bunny_ini *ini, char *scope,
				       char *field, int i);
unsigned int		hex2int(char *hex, int len);
int			field_to_int(t_bunny_ini *ini, char *scope,
				     char *field, int i);
void		        checkbox_click(t_tekgui *gui, t_checkbox *checkbox,
				       t_bunny_mouse_button mouse_button,
				       t_bunny_event_state state);
#endif /* ! _TEKGUI_H_ */
