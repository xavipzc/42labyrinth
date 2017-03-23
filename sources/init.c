/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PZC <PZC@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 11:48:30 by xpouzenc          #+#    #+#             */
/*   Updated: 2017/03/23 17:15:21 by PZC              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	init_last_position(t_env *e)
{
	int		fd;
	char	*data;

	if ((fd = open("data/save.wolf", O_RDONLY)) == -1)
		show_error(3);
	if ((get_next_line(fd, &data)) == -1)
		show_error(3);
	POS_X = ft_atoi(data);
	ft_strdel(&data);
	if ((get_next_line(fd, &data)) == -1)
		show_error(3);
	POS_Y = ft_atoi(data);
	ft_strdel(&data);
	close(fd);
}

/*
** Pos XY - The player position
** Dir XY - Player's direction view
** Plane XY - The 2D raycaster version of camera plane
*/

static void	init_player(t_env *e)
{
	if (e->save_file == 1)
		init_last_position(e);
	else
	{
		POS_X = 22;
		POS_Y = 12;
	}
	DIR_X = -1;
	DIR_Y = 0;
	PLANE_X = 0;
	PLANE_Y = 0.66;
	CAMERA_X = 0;
}

void		init_env(t_env *e, char *bin)
{
	if (!(e->mlx_ptr = mlx_init()))
		show_error(4);
	if (!(e->mlx_win = mlx_new_window(e->mlx_ptr, W_WIDTH, W_HEIGHT, bin)))
		show_error(4);
	e->img_ptr = NULL;
	e->menu.menu_ptr = NULL;
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
** Ray.Pos XY - The ray positoin is initially set to the position of the player
** Ray.Dir XY - The Ray direction
** Map XY - The Ray position in the 2D map
** Hit - Boolean to know if a wall is hitting
** Delta Distance XY - length of ray from one x or y-side to next x or y-side
*/

void		init_ray(t_env *e, int x)
{
	HIT = 0;
	CAMERA_X = 2 * x / (double)W_WIDTH - 1;
	R_POS_X = POS_X;
	R_POS_Y = POS_Y;
	R_DIR_X = DIR_X + PLANE_X * CAMERA_X;
	R_DIR_Y = DIR_Y + PLANE_Y * CAMERA_X;
	R_MAP_X = (int)R_POS_X;
	R_MAP_Y = (int)R_POS_Y;
	R_DELTAD_X = sqrt(1 + (R_DIR_Y * R_DIR_Y) / (R_DIR_X * R_DIR_X));
	R_DELTAD_Y = sqrt(1 + (R_DIR_X * R_DIR_X) / (R_DIR_Y * R_DIR_Y));
}
