/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cletinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 13:26:18 by cletinic          #+#    #+#             */
/*   Updated: 2018/08/06 13:26:22 by cletinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "libft/libft.h"
# include "minilibx/mlx.h"

# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define WIN_WIDTH 512
# define WIN_HEIGHT 384

typedef	struct	s_vector
{
	int			x;
	int			y;
	int			z;
}				t_vector;

typedef	struct	s_env
{
	void		*mlx;
	void		*win;
	void		*win2;
	char		**fileinput;

	int			fd;
	int			index;
	int			columns;
	int			columnsindex;
	int			rows;
	int			rowindex;
	int			retint;
	char		*line;
	char		*ret;
	char		*temp1;
	char		**temp;
	t_vector	*map;

	int			pointx0;
	int			pointy0;
	int			pointz0;
	int			pointx1;
	int			pointy1;
	int			pointz1;
	int			delta_x;
	int			delta_y;
	float		x;
	float		y;

	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			colour;
	double		move_speed;
	double		rot_speed;
	double		prev_dir_x;
	double		prev_plane_x;
}				t_env;

void			read_columns(t_env *env);
int				read_rows(t_env *env);
void			split_into_array(t_env *env);
int				read_initialise(t_env *env);
int				fill_map_array(t_env *env);

void			draw_line(t_env *env);

void			draw_ceiling(t_env *env);
void			draw_walls(t_env *env);
void			draw_floor(t_env *env);
void			draw_surroundings(t_env *env);

void			ray_variables(t_env *env, int *x);
void			step_and_distance(t_env *env);
void			ray_caster(t_env *env);
void			cast_ray(t_env *env);

int				exit_program(t_env *env);
int				key_released(int keycode, t_env *env);
int				key_pressed(int keycode, t_env *env);

void			forward(t_env *env);
void			backward(t_env *env);
void			rotate_left(t_env *env);
void			rotate_right(t_env *env);

int				check_int(t_env *env, int i);
void			return_error(t_env *env, int returnvalue);

#endif
