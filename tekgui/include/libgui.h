/*
** tekgui.h for tekgui in /home/sauvau_m/rendu/gfx_tekgui/include
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Wed Feb  3 15:36:34 2016 Mathieu Sauvau
** Last update Sun Feb 28 16:28:13 2016 Mathieu Sauvau
*/

#ifndef _TEKGUI_H_

#define _LIBGUI_H_
# include <lapin.h>
# define BIGF bunny_ini_get_field
# define ALPHA_ argb[ALPHA_CMP]
# define RED_ argb[RED_CMP]
# define GREEN_ argb[GREEN_CMP]
# define BLUE_ argb[BLUE_CMP]
# define LGT load_gui_texture

typedef enum{no_type, scale, crop} render_type;
typedef enum{normal, over, on, over_on} state;

typedef struct		s_rect
{
  t_bunny_position	pos;
  t_bunny_position	size;
  int			color;
  bool			mouse_over;
  bool			active;
}			t_rect;

typedef struct		s_border
{
  int			top;
  int			left;
  int			right;
  int			bottom;
}			t_border;

typedef struct		s_gui_texture
{
  t_border		*border;
  t_bunny_pixelarray	*texture;
}			t_gui_texture;

typedef struct		s_texture_state
{
  t_gui_texture		*normal;
  t_gui_texture		*on;
  t_gui_texture		*over;
  t_gui_texture		*over_on;
}			t_texture_state;

typedef struct		s_checkbox
{
  t_rect		*rect;
  char			*label;
  bool			checked;
  bool			focus;
  t_bunny_pixelarray	*label_pix;
  t_texture_state	*texture_state;
  state			state;
  int			contour_size;
  int			contour_color;
  int			cross_color;
  int			space_label;
}			t_checkbox;

typedef struct		s_button
{
  t_rect		*rect;
  char			*label;
  t_bunny_pixelarray	*label_pix;
  t_texture_state	*texture_state;
  state			state;
  void			(*onclick)();
  bool			focus;
  int			contour_color;
  int			contour_size;
}			t_button;

typedef struct		s_text
{
  t_rect		*rect;
  char			*txt;
  t_bunny_pixelarray	*txt_pix;
  int			size;
  int			color;
}			t_text;

typedef struct		s_img
{
  t_rect		*rect;
  char			*label;
  t_bunny_pixelarray	*label_pix;
  t_bunny_picture	*img;
  render_type		mode;
}			t_img;

/*
** HELPER FUNCTIONS
*/
void                    my_fill(t_bunny_pixelarray *pix_ar,
				unsigned int color);
t_bunny_position	pos_(int, int);
t_bunny_position        get_center(t_rect *rect, t_bunny_position offset);
t_bunny_position	offset_center_txt(char *str);
t_rect			*new_rect(t_bunny_position ,
				  t_bunny_position ,
				  int);
t_border		*new_border(int top, int left, int right, int bottom);
t_gui_texture		*new_gui_texture(t_border *border,
					 char *file_texture);
t_texture_state		*define_textures(t_gui_texture *normal,
					 t_gui_texture *over,
					 t_gui_texture *on,
					 t_gui_texture *over_on);
t_bunny_pixelarray	*load_font(const char *file);
t_bunny_pixelarray	*get_letter(t_bunny_pixelarray *f, int index);
bool			clicked_left(t_button *);
bool			clicked_right(t_rect *, t_bunny_mouse_button);
bool			clicked_middle(t_rect *, t_bunny_mouse_button);
bool			clicked_checkbox(t_checkbox *, t_bunny_mouse_button,
					 t_bunny_event_state state);
bool			onmouse_over(t_rect *rect,
				     void(*my_behaviour)(void *data),
				     void *data);
bool			onmouse_out(t_rect *rect,
				    void (*my_behaviour)(void *data),
				    void *data);
void			checkbox_over_on(void *data);
void		        checkbox_over_out(void *data);
void			my_blit(t_bunny_pixelarray *bg,
				t_bunny_pixelarray *fg,
				t_bunny_position offset);

/*
** GUI FUNCTIONS
*/
t_button	*new_button(t_rect *, char *, t_bunny_pixelarray *font,
			    void(*onclick)());
t_checkbox	*new_checkbox(t_rect *, char *, t_bunny_pixelarray *font);
t_img		*new_img(t_rect *rect, char *label, char *texture);
t_button        *gui_button(t_bunny_pixelarray *pix_ar,
			    t_button *button,
			    t_texture_state *textures);
t_checkbox	*gui_checkbox(t_bunny_pixelarray *pix_ar,
			      t_checkbox *checkbox,
			      t_texture_state *textures);
t_text		*gui_text(t_bunny_pixelarray *pix_ar,
			  t_text *text);
t_text		*new_text(t_rect *rect, t_bunny_pixelarray *font, char *txt);
void		draw_(t_bunny_pixelarray *,
		      t_rect *);
void		draw_checkbox(t_bunny_pixelarray *pix_ar,
			      t_checkbox *checkbox,
			      int color_cross);
void		draw_cross(t_bunny_pixelarray *,
			   t_checkbox *, int);
void		tekline(t_bunny_pixelarray *, t_bunny_position *,
			t_color *);
void		tekpixel(t_bunny_pixelarray *, t_bunny_position *,
			 t_color *);
void		pixel(t_bunny_pixelarray *pix_ar,
		      t_bunny_position pos,
		      int color);
void		draw_contour(t_bunny_pixelarray *pix_ar,
			     t_rect *rect, int contour_size, int color);
void		draw_img(t_bunny_pixelarray *pix_ar,
			 t_img *img, render_type type,
			 t_bunny_position clip_pos);
void		draw_img_content(t_bunny_pixelarray *pix_ar, t_rect *rect,
				 t_gui_texture *texture);
void		write_png(t_bunny_pixelarray *pix_ar,
			  t_bunny_pixelarray *font,
			  char *str);
void		write_txt(t_bunny_pixelarray *pix_ar,
			  t_bunny_pixelarray *font,
			  char *str);

#endif /* ! _LIBGUI_H_ */
