/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cletinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 13:28:15 by cletinic          #+#    #+#             */
/*   Updated: 2018/08/06 13:28:17 by cletinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void				ray_variables(t_env *env, int *x)
{
	env->camera_x = 4 * *x / ((double)WIN_WIDTH) - 1;
	env->raydir_x = env->dir_x + env->plane_x * env->camera_x;
	env->raydir_y = env->dir_y + env->plane_y * env->camera_x;
	env->map_x = (int)env->pos_x;
	env->map_y = (int)env->pos_y;
	env->delta_dist_x = fabs(1 / env->raydir_x);
	env->delta_dist_y = fabs(1 / env->raydir_y);
	env->hit = 0;
}

void				step_and_distance(t_env *env)
{
	if (env->raydir_x < 0)
	{
		env->step_x = -1;
		env->side_dist_x = (env->pos_x - env->map_x) * env->delta_dist_x;
	}
	else
	{
		env->step_x = 1;
		env->side_dist_x = (env->map_x + 1.0 - env->pos_x) * env->delta_dist_x;
	}
	if (env->raydir_y < 0)
	{
		env->step_y = -1;
		env->side_dist_y = (env->pos_y - env->map_y) * env->delta_dist_y;
	}
	else
	{
		env->step_y = 1;
		env->side_dist_y = (env->map_y + 1.0 - env->pos_y) * env->delta_dist_y;
	}
}

void				cast_ray(t_env *env)
{
	while (env->hit == 0)
	{
		if (env->side_dist_x < env->side_dist_y)
		{
			env->side_dist_x += env->delta_dist_x;
			env->map_x += env->step_x;
			env->side = 0;
		}
		else
		{
			env->side_dist_y += env->delta_dist_y;
			env->map_y += env->step_y;
			env->side = 1;
		}
		if (env->map[(env->map_y * env->rows) + env->map_x].z > 0)
			env->hit = 1;
	}
}

void				ray_caster(t_env *env)
{
	int x;

	x = -1;
	while (x++ < WIN_WIDTH)
	{
		ray_variables(env, &x);
		step_and_distance(env);
		cast_ray(env);
		if (env->side == 0)
			env->perp_wall_dist = (env->map_x - env->pos_x +
			(1 - env->step_x) / 2) / env->raydir_x;
		else
			env->perp_wall_dist = (env->map_y - env->pos_y +
			(1 - env->step_y) / 2) / env->raydir_y;
		env->line_height = (int)(WIN_HEIGHT / env->perp_wall_dist);
		env->draw_start = -env->line_height / 2 + WIN_HEIGHT / 2;
		if (env->draw_start < 0)
			env->draw_start = 0;
		env->draw_end = env->line_height / 2 + WIN_HEIGHT / 2;
		if (env->draw_end >= WIN_HEIGHT)
			env->draw_end = WIN_HEIGHT - 1;
		env->pointx0 = x;
		env->pointx1 = x;
		draw_surroundings(env);
	}
}
