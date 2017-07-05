/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 03:17:18 by upopee            #+#    #+#             */
/*   Updated: 2017/07/05 20:21:27 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "pixel_shader.h"

void				draw_lines(t_scene *w, t_mlximg *img, t_matrix4 f)
{
	int			i;
	int			j;
	t_vertex3f	tmp;
	t_line		line;

	i = w->height;
	while (i--)
	{
		j = w->width;
		tmp = w->map[i][j - 1];
		line.a = ft_ver3f_proj(tmp, f, img->width, img->height);
		while (--j)
		{
			tmp = w->map[i][j - 1];
			line.b = ft_ver3f_proj(tmp, f, img->width, img->height);
			fastline_fdf(img, line);
			line.a = line.b;
		}
	}
}

void				draw_columns(t_scene *w, t_mlximg *img, t_matrix4 f)
{
	int			i;
	int			j;
	t_vertex3f	tmp;
	t_line		line;

	j = w->width;
	while (j--)
	{
		i = w->height;
		tmp = w->map[i - 1][j];
		line.a = ft_ver3f_proj(tmp, f, img->width, img->height);
		line.a.color = tmp.color;
		while (--i)
		{
			tmp = w->map[i - 1][j];
			line.b = ft_ver3f_proj(tmp, f, img->width, img->height);
			line.b.color = tmp.color;
			fastline_fdf(img, line);
			line.a = line.b;
		}
	}
}

void				draw_points(t_scene *w, t_mlximg *img, t_matrix4 f)
{
	int			i;
	int			j;
	t_vertex3f	tmp;
	t_vertex2i	pt;

	j = w->width;
	while (j--)
	{
		i = w->height;
		while (i--)
		{
			tmp = w->map[i][j];
			pt = ft_ver3f_proj(tmp, f, img->width, img->height);
			pixel_to_img(img, pt.x, pt.y, tmp.color);
		}
	}
}
