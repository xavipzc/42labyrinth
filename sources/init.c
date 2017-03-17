/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PZC <PZC@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 11:48:30 by xpouzenc          #+#    #+#             */
/*   Updated: 2017/03/16 19:57:46 by PZC              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** Pos XY - The player position
** Dir XY - Player's direction view
** Plane XY - The 2D raycaster version of camera plane
*/

static void	init_player(t_env *e)
{
	POS_X = 22;
	POS_Y = 12;
	DIR_X = -1;
	DIR_Y = 0;
	PLANE_X = 0;
	PLANE_Y = 0.66;
	CAMERA_X = 0;
}

void		init_env(t_env *e)
{
	e->mlx_ptr = mlx_init();
	e->mlx_win = mlx_new_window(e->mlx_ptr, W_WIDTH, W_HEIGHT, "Wolf3d");
	e->img_ptr = NULL;
	e->img.width = W_WIDTH;
	e->img.height = W_HEIGHT;
	e->img.e = 0;
	e->img.bpp = 32;
	e->img.sl = e->img.width * 4;
	TIME = 0;
	OLD_TIME = 0;
	MOVE_UP = 0;
	MOVE_DOWN = 0;
	MOVE_LEFT = 0;
	MOVE_RIGHT = 0;
	SPEEDX2 = 0;
	init_player(e);
}

/*
** Ray.Pos XY - The ray positoin is initially set to the position of the player.
** Ray.Dir XY - The Ray direction
** Map XY - The Ray position in the 2D map
** Hit - Boolean to know if a wall is hitting
** Delta Distance XY - length of ray from one x or y-side to next x or y-side
*/

void		init_ray(t_env *e, int x)
{
	CAMERA_X = 2 * x / (double)W_WIDTH - 1;
	e->p.hit = 0;
	e->r.pos.x = POS_X;
	e->r.pos.y = POS_Y;
	e->r.dir.x = DIR_X + PLANE_X * CAMERA_X;
	e->r.dir.y = DIR_Y + PLANE_Y * CAMERA_X;
	e->r.map.x = (int)e->r.pos.x;
	e->r.map.y = (int)e->r.pos.y;
	e->r.d_dist.x = sqrt(1 + (e->r.dir.y * e->r.dir.y) / (e->r.dir.x * e->r.dir.x));
	e->r.d_dist.y = sqrt(1 + (e->r.dir.x * e->r.dir.x) / (e->r.dir.y * e->r.dir.y));
}
