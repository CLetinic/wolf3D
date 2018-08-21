/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surroundings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cletinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 12:11:51 by cletinic          #+#    #+#             */
/*   Updated: 2018/08/20 12:12:01 by cletinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void				draw_ceiling(t_env *env)
{
	env->pointy0 = 0;
	env->pointy1 = env->draw_start;
	env->colour = 0x424242;
	draw_line(env);
}

void				draw_walls(t_env *env)
{
	env->pointy0 = env->draw_start;
	env->pointy1 = env->draw_end;
	if (env->side == 1)
	{
		if ((env->step_x == -1 && env->step_y == -1) ||
			(env->step_x == 1 && env->step_y == -1))
			env->colour = 0xC322DE;
		if ((env->step_x == -1 && env->step_y == 1) ||
			(env->step_x == 1 && env->step_y == 1))
			env->colour = 0x656AFA;
	}
	else if ((env->step_x == -1 && env->step_y == -1) ||
	(env->step_x == -1 && env->step_y == 1))
		env->colour = 0x21C4E6;
	else
		env->colour = 0x3EF7A3;
	draw_line(env);
}

void				draw_floor(t_env *env)
{
	env->pointy0 = env->draw_end;
	env->pointy1 = WIN_HEIGHT;
	env->colour = 0x262626;
	draw_line(env);
}

void				draw_surroundings(t_env *env)
{
	draw_ceiling(env);
	draw_walls(env);
	draw_floor(env);
}
