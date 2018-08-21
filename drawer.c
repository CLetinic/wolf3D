/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cletinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 13:58:42 by cletinic          #+#    #+#             */
/*   Updated: 2018/07/13 13:58:48 by cletinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
**	DDA Function for line generation
**	https://bit.ly/2zzaSzY
*/

void				draw_line(t_env *env)
{
	int				steps;
	float			x_increment;
	float			y_increment;

	env->delta_x = env->pointx1 - env->pointx0;
	env->delta_y = env->pointy1 - env->pointy0;
	env->x = env->pointx0;
	env->y = env->pointy0;
	if (ft_abs(env->delta_x) > ft_abs(env->delta_y))
		steps = ft_abs(env->delta_x);
	else
		steps = ft_abs(env->delta_y);
	x_increment = env->delta_x / (float)steps;
	y_increment = env->delta_y / (float)steps;
	while (steps)
	{
		mlx_pixel_put(env->mlx, env->win, env->x, env->y, env->colour);
		env->x += x_increment;
		env->y += y_increment;
		steps--;
	}
}
