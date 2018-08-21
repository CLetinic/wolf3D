/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cletinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 11:55:46 by cletinic          #+#    #+#             */
/*   Updated: 2018/08/20 11:55:50 by cletinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			forward(t_env *env)
{
	if (env->map[((int)(env->pos_x + env->dir_x * env->move_speed)) +
		((int)(env->pos_y * env->rows))].z == 0)
		env->pos_x += env->dir_x * env->move_speed;
	if (env->map[((int)env->pos_x) + ((int)((env->pos_y + env->dir_y *
		env->move_speed) * env->rows))].z == 0)
		env->pos_y += env->dir_y * env->move_speed;
}

void			backward(t_env *env)
{
	if (env->map[((int)(env->pos_x - env->dir_x * env->move_speed)) +
		((int)(env->pos_y * env->rows))].z == 0)
		env->pos_x -= env->dir_x * env->move_speed;
	if (env->map[((int)env->pos_x) + ((int)((env->pos_y - env->dir_y *
		env->move_speed) * env->rows))].z == 0)
		env->pos_y -= env->dir_y * env->move_speed;
}

void			rotate_left(t_env *env)
{
	env->prev_dir_x = env->dir_x;
	env->dir_x = env->dir_x * cos(env->rot_speed) -
				env->dir_y * sin(env->rot_speed);
	env->dir_y = env->prev_dir_x * sin(env->rot_speed) +
				env->dir_y * cos(env->rot_speed);
	env->prev_plane_x = env->plane_x;
	env->plane_x = env->plane_x * cos(env->rot_speed) -
					env->plane_y * sin(env->rot_speed);
	env->plane_y = env->prev_plane_x * sin(env->rot_speed) +
					env->plane_y * cos(env->rot_speed);
}

void			rotate_right(t_env *env)
{
	env->prev_dir_x = env->dir_x;
	env->dir_x = env->dir_x * cos(-env->rot_speed) -
				env->dir_y * sin(-env->rot_speed);
	env->dir_y = env->prev_dir_x * sin(-env->rot_speed) +
				env->dir_y * cos(-env->rot_speed);
	env->prev_plane_x = env->plane_x;
	env->plane_x = env->plane_x * cos(-env->rot_speed) -
					env->plane_y * sin(-env->rot_speed);
	env->plane_y = env->prev_plane_x * sin(-env->rot_speed) +
					env->plane_y * cos(-env->rot_speed);
}
