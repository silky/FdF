/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upopee <upopee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 17:34:53 by upopee            #+#    #+#             */
/*   Updated: 2017/07/07 07:38:36 by upopee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_UTILS_H
# define HOOK_UTILS_H

void		zoom(t_mod *mod, float zoom_value);
void		next_proj(t_mod *mod);
void		next_color(t_scene *w, t_colors *c, int *keys);
void		apply_mods(t_env *e, t_scene *wld, t_mod *mod);

#endif
