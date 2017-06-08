/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 22:38:54 by upopee            #+#    #+#             */
/*   Updated: 2017/06/05 04:42:17 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_UTILS_H
# define DRAW_UTILS_H

void	draw_lines(t_scene *w, t_mlximg *img, t_matrix4 f);
void	draw_columns(t_scene *w, t_mlximg *img, t_matrix4 f);
void	draw_points(t_scene *w, t_mlximg *img, t_matrix4 f);

#endif
