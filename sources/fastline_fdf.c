/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fastline_fdf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:57:17 by upopee            #+#    #+#             */
/*   Updated: 2018/05/14 02:14:05 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		case_one(t_mlximg *img, t_line line, int i, float step)
{
	int		index;

	index = 0x8000 + (line.a.x << 16);
	if (line.long_len > 0)
	{
		line.long_len += line.a.y;
		while (line.a.y <= line.long_len)
		{
			pixel_to_img(img, (index >> 16), line.a.y,
					ft_icolor_lerp(line.a.color, line.b.color, i++ * step));
			index += line.increment;
			(line.a.y)++;
		}
	}
	else
	{
		line.long_len += line.a.y;
		while (line.a.y >= line.long_len)
		{
			pixel_to_img(img, (index >> 16), line.a.y,
					ft_icolor_lerp(line.a.color, line.b.color, i++ * step));
			index -= line.increment;
			(line.a.y)--;
		}
	}
}

static void		case_two(t_mlximg *img, t_line line, int i, float step)
{
	int		index;

	index = 0x8000 + (line.a.y << 16);
	if (line.long_len > 0)
	{
		line.long_len += line.a.x;
		while (line.a.x <= line.long_len)
		{
			pixel_to_img(img, line.a.x, (index >> 16),
					ft_icolor_lerp(line.a.color, line.b.color, i++ * step));
			index += line.increment;
			(line.a.x)++;
		}
	}
	else
	{
		line.long_len += line.a.x;
		while (line.a.x >= line.long_len)
		{
			pixel_to_img(img, line.a.x, (index >> 16),
					ft_icolor_lerp(line.a.color, line.b.color, i++ * step));
			index -= line.increment;
			(line.a.x)--;
		}
	}
}

void			fastline_fdf(t_mlximg *img, t_line line)
{
	int		y_longer;
	int		short_len;
	int		swap;
	float	step;

	y_longer = 0;
	short_len = line.b.y - line.a.y;
	line.long_len = line.b.x - line.a.x;
	if (ft_abs(short_len) > ft_abs(line.long_len))
	{
		swap = short_len;
		short_len = line.long_len;
		line.long_len = swap;
		y_longer = 1;
	}
	step = 1.0 / ft_abs(line.long_len);
	line.increment = line.long_len == 0 ? 0 : (short_len << 16) / line.long_len;
	if (y_longer)
		case_one(img, line, 0, step);
	else
		case_two(img, line, 0, step);
}
