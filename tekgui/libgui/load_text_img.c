/*
** load_text_img.c for libgui in /home/sauvau_m/rendu/gfx_tekgui/demo
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Wed Feb 24 14:42:04 2016 Mathieu Sauvau
** Last update Wed Feb 24 14:48:21 2016 Mathieu Sauvau
*/

#include "tekgui.h"
#include "helper.h"

t_text			*load_text(t_bunny_ini *ini, int nb,
				   t_bunny_pixelarray *font)
{
  t_text		*text;
  char			scope[10];
  char			n[3];
  int			i;

  i = -1;
  if (nb == 0
      || (text = bunny_malloc(sizeof(t_text) * nb)) == NULL)
    return (NULL);
  while (++i < nb)
    {
      my_strcpy(scope, "text_");
      itoa(i, n, 10);
      my_strcat(scope, n);
      text[i].txt = my_strdup((char *)BIGF(ini, scope, "text", 0));
      if ((text[i].rect = load_rect(ini, scope)) == NULL
	  || (text[i].txt_pix =
	      bunny_new_pixelarray(text[i].rect->size.x,
				   text[i].rect->size.y)) == NULL)
	return (NULL);
      my_fill(text[i].txt_pix, 0x00000000);
      write_txt(text[i].txt_pix, font, text[i].txt);
    }
  return (text);
}

void			load_img_next(t_img *img, t_bunny_pixelarray *font,
				      t_bunny_ini *ini, char *scope)
{
  my_fill(img->label_pix, 0x00000000);
  write_png(img->label_pix, font, img->label);
  img->mode = (render_type)field_to_int(ini, scope, "mode", 0);
}

t_img			*load_img(t_bunny_ini *ini, int nb,
				  t_bunny_pixelarray *font)
{
  t_img			*img;
  char			scope[10];
  char			n[3];
  int			i;
  char			*file;

  i = -1;
  if (nb == 0
      || (img = bunny_malloc(sizeof(t_img) * nb)) == NULL)
    return (NULL);
  while (++i < nb)
    {
      my_strcpy(scope, "img_");
      itoa(i, n, 10);
      my_strcat(scope, n);
      img[i].label = my_strdup((char *)BIGF(ini, scope, "label", 0));
      if ((img[i].rect = load_rect(ini, scope)) == NULL
	  || (img[i].label_pix =
	      bunny_new_pixelarray(my_strlen(img[i].label) * 8, 7)) == NULL
	  || (file = (char *)BIGF(ini, scope, "img", 0)) == NULL
	  || (img[i].img = bunny_load_picture(file)) == NULL)
	return (NULL);
      load_img_next(&img[i], font, ini, scope);
    }
  return (img);
}
