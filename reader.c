/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cletinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 13:57:49 by cletinic          #+#    #+#             */
/*   Updated: 2018/07/23 11:16:47 by cletinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		read_columns(t_env *env)
{
	env->ret = ft_strdup(env->line);
	ft_strdel(&(env->line));
	env->temp = ft_strsplit(env->ret, ' ');
	while (env->temp[env->columns])
	{
		if (!(check_int(env, env->columns)))
		{
			free(env->temp[env->columns]);
			env->columns++;
		}
	}
	free(env->temp);
}

int			read_rows(t_env *env)
{
	env->retint = 0;
	if (get_next_line(env->fd, &env->line) < 0 || ft_strlen(env->line) == 0)
		return (2);
	read_columns(env);
	env->rows++;
	while ((env->retint = get_next_line(env->fd, &(env->line))) == 1)
	{
		env->temp1 = ft_strjoin(env->ret, " ");
		ft_strdel(&(env->ret));
		env->ret = env->temp1;
		env->temp1 = ft_strjoin(env->ret, env->line);
		ft_strdel((&env->ret));
		ft_strdel(&env->line);
		env->ret = env->temp1;
		if (!(check_int(env, env->rows)))
			env->rows++;
	}
	if (env->retint < 0)
	{
		free(env->ret);
		free(env->line);
		return (2);
	}
	return (0);
}

void		split_into_array(t_env *env)
{
	env->temp = ft_strsplit(env->ret, ' ');
	free(env->ret);
	free(env->line);
	env->index = 0;
	while (env->temp[env->index])
	{
		if (!(check_int(env, env->index)))
			env->index++;
	}
}

int			read_initialise(t_env *env)
{
	env->fd = open(*env->fileinput, O_RDONLY);
	if (env->fd < 0)
		return_error(env, 1);
	if ((read_rows(env)) != 0)
		return_error(env, 2);
	if (close(env->fd) < 0)
		return_error(env, 1);
	split_into_array(env);
	if (((env->columns * env->rows)) == (env->index))
	{
		if (!(env->map = (t_vector *)ft_memalloc((sizeof(t_vector))
			* (env->rows * env->columns))))
		{
			free_2d_char_array(env->temp);
			return_error(env, 4);
		}
		fill_map_array(env);
	}
	else
	{
		free_2d_char_array(env->temp);
		return_error(env, 3);
	}
	return (0);
}

int			fill_map_array(t_env *env)
{
	env->index = 0;
	while (env->temp[env->index])
	{
		while (++env->rowindex < env->rows)
		{
			env->columnsindex = -1;
			while (++env->columnsindex < env->columns)
			{
				env->map[env->index].x = env->columnsindex;
				env->map[env->index].y = env->rowindex;
				if (!(check_int(env, ft_atoi(env->temp[env->index]))))
					env->map[env->index].z = ft_atoi(env->temp[env->index]);
				free(env->temp[env->index]);
				if (!(check_int(env, env->index)))
					env->index++;
			}
		}
	}
	free(env->temp);
	return (0);
}
