/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PZC <PZC@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:25:17 by xpouzenc          #+#    #+#             */
/*   Updated: 2017/03/16 20:05:27 by PZC              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ray_direction(t_env *e)
{
	if (e->r.dir.x < 0)
	{
		e->p.step.x = -1;
		e->r.s_dist.x = (e->r.pos.x - e->r.map.x) * e->r.d_dist.x;
	}
	else
	{
		e->p.step.x = 1;
		e->r.s_dist.x = (e->r.map.x + 1.0 - e->r.pos.x) * e->r.d_dist.x;
	}
	if (e->r.dir.y < 0)
	{
		e->p.step.y = -1;
		e->r.s_dist.y = (e->r.pos.y - e->r.map.y) * e->r.d_dist.y;
	}
	else
	{
		e->p.step.y = 1;
		e->r.s_dist.y = (e->r.map.y + 1.0 - e->r.pos.y) * e->r.d_dist.y;
	}
}

static void	dda(t_env *e)
{
	while (e->p.hit == 0)
	{
		if (e->r.s_dist.x < e->r.s_dist.y)
		{
			e->r.s_dist.x += e->r.d_dist.x;
			e->r.map.x += e->p.step.x;
			e->p.side = 0;
		}
		else
		{
			e->r.s_dist.y += e->r.d_dist.y;
			e->r.map.y += e->p.step.y;
			e->p.side = 1;
		}
		if (MAP[e->r.map.x][e->r.map.y] > 0)
			e->p.hit = 1;
	}
}

static void	calculate(t_env *e)
{
	double wall_dist;

	if (e->p.side == 0)
		wall_dist = fabs((e->r.map.x - e->r.pos.x + (1 - e->p.step.x) / 2) / e->r.dir.x);
	else
		wall_dist = fabs((e->r.map.y - e->r.pos.y + (1 - e->p.step.y) / 2) / e->r.dir.y);
	e->r.line_h = abs((int)(W_HEIGHT / wall_dist));
	e->r.y_start = -e->r.line_h / 2 + W_HEIGHT / 2;
	if (e->r.y_start < 0)
		e->r.y_start = 0;
	e->r.y_end = e->r.line_h / 2 + W_HEIGHT / 2;
	if (e->r.y_end >= W_HEIGHT)
		e->r.y_end = W_HEIGHT - 1;
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
		draw_vline(e, x, e->r.y_start, e->r.y_end, e->color);
		x++;
	}
	get_fps(e);
	move_player(e);
	mlx_put_image_to_window(e->mlx_ptr, e->mlx_win, e->img_ptr, 0, 0);
	return (0);
}
