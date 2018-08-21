/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cletinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 11:53:22 by cletinic          #+#    #+#             */
/*   Updated: 2018/08/20 11:53:42 by cletinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				exit_program(t_env *env)
{
	free(env->map);
	mlx_destroy_window(env->mlx, env->win);
	exit(0);
}

int				key_released(int keycode, t_env *env)
{
	if (keycode == 53)
		exit_program(env);
	return (0);
}

int				key_pressed(int keycode, t_env *env)
{
	env->move_speed = 2;
	env->rot_speed = 10 * M_PI / 180;
	mlx_clear_window(env->mlx, env->win);
	if (keycode == 53)
		exit_program(env);
	if (keycode == 126 || keycode == 13)
		forward(env);
	if (keycode == 125 || keycode == 1)
		backward(env);
	if (keycode == 124 || keycode == 2)
		rotate_left(env);
	if (keycode == 123 || keycode == 0)
		rotate_right(env);
	ray_caster(env);
	return (0);
}
