/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cletinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 13:28:49 by cletinic          #+#    #+#             */
/*   Updated: 2018/08/06 13:28:51 by cletinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			wolf3d_initialise(t_env *env)
{
	env->rows = 0;
	env->columns = 0;
	env->rowindex = -1;
	env->pos_x = 3;
	env->pos_y = 3;
	env->dir_x = 1;
	env->dir_y = 0;
	env->plane_x = 0;
	env->plane_y = 0.66;
}

int				main(int argc, char **argv)
{
	t_env	env;

	if (argc == 2)
	{
		env.fileinput = &argv[1];
		wolf3d_initialise(&env);
		read_initialise(&env);
		env.mlx = mlx_init();
		env.win = mlx_new_window(env.mlx, WIN_WIDTH, WIN_HEIGHT, "Wolf3D");
		ray_caster(&env);
		mlx_hook(env.win, 17, 0L, exit_program, (void *)&env);
		mlx_hook(env.win, 2, 1L << 0, key_pressed, (void *)&env);
		mlx_loop(env.mlx);
	}
	else
		return_error(&env, 6);
	return (0);
}
