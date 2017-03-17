/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xpouzenc <xpouzenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:25:17 by xpouzenc          #+#    #+#             */
/*   Updated: 2017/03/17 14:56:19 by xpouzenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ray_direction(t_env *e)
{
	if (R_DIR_X < 0)
	{
		STEP_X = -1;
		R_SIDED_X = (R_POS_X - R_MAP_X) * R_DELTAD_X;
	}
	else
	{
		STEP_X = 1;
		R_SIDED_X = (R_MAP_X + 1.0 - R_POS_X) * R_DELTAD_X;
	}
	if (R_DIR_Y < 0)
	{
		STEP_Y = -1;
		R_SIDED_Y = (R_POS_Y - R_MAP_Y) * R_DELTAD_Y;
	}
	else
	{
		STEP_Y = 1;
		R_SIDED_Y = (R_MAP_Y + 1.0 - R_POS_Y) * R_DELTAD_Y;
	}
}

static void	dda(t_env *e)
{
	while (HIT == 0)
	{
		if (R_SIDED_X < R_SIDED_Y)
		{
			R_SIDED_X += R_DELTAD_X;
			R_MAP_X += STEP_X;
			SIDE = 0;
		}
		else
		{
			R_SIDED_Y += R_DELTAD_Y;
			R_MAP_Y += STEP_Y;
			SIDE = 1;
		}
		if (MAP[R_MAP_X][R_MAP_Y] > 0)
			HIT = 1;
	}
}

static void	calculate(t_env *e)
{
	double wall_dist;

	if (SIDE == 0)
		wall_dist = fabs((R_MAP_X - R_POS_X + (1 - STEP_X) / 2) / R_DIR_X);
	else
		wall_dist = fabs((R_MAP_Y - R_POS_Y + (1 - STEP_Y) / 2) / R_DIR_Y);
	R_LINE_H = abs((int)(W_HEIGHT / wall_dist));
	R_Y_START = -R_LINE_H / 2 + W_HEIGHT / 2;
	if (R_Y_START < 0)
		R_Y_START = 0;
	R_Y_END = R_LINE_H / 2 + W_HEIGHT / 2;
	if (R_Y_END >= W_HEIGHT)
		R_Y_END = W_HEIGHT - 1;
}

int			loop_hook(t_env *e)
{
	int		x;

	x = 0;
	if (e->img_ptr != NULL)
		mlx_destroy_image(e->mlx_ptr, e->img_ptr);
	e->img_ptr = mlx_new_image(e->mlx_ptr, e->img.width, e->img.height);
	while (x < W_WIDTH)
	{
		init_ray(e, x);
		ray_direction(e);
		dda(e);
		calculate(e);
		wall_color(e);
		draw_vline(e, x);
		x++;
	}
	get_fps(e);
	move_player(e);
	mlx_put_image_to_window(e->mlx_ptr, e->mlx_win, e->img_ptr, 0, 0);
	return (0);
}
