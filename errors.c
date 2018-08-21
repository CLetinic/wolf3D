/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cletinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 15:40:03 by cletinic          #+#    #+#             */
/*   Updated: 2018/07/23 15:40:08 by cletinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		check_int(t_env *env, int i)
{
	if ((i == (-2147483647)) || (i == (2147483646)))
	{
		return_error(env, 5);
		return (0);
	}
	return (0);
}

void	return_error(t_env *env, int returnvalue)
{
	if (returnvalue == 6)
		ft_putendl("Error: Input Invalid");
	if (returnvalue == 1)
		ft_putendl("Error: File Failed");
	if (returnvalue == 2)
		ft_putendl("Error: Reading File Failed");
	if (returnvalue == 3)
		ft_putendl("Error: Map input is Invalid");
	if (returnvalue == 4)
		ft_putendl("Error: Failed to Allocate Memory");
	if (returnvalue == 5)
	{
		ft_putendl("Error: Out of Bounds");
		mlx_destroy_window(env->mlx, env->win);
	}
	if (returnvalue == 7)
		ft_putendl("Error: Map not yet Supported");
	exit(0);
}
