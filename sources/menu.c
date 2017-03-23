/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PZC <PZC@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:19:26 by PZC               #+#    #+#             */
/*   Updated: 2017/03/22 16:30:34 by PZC              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	draw_menu(t_env *e)
{
	int x;
	int y;

	y = 0;
	e->menu.menu_img = (unsigned int*)mlx_get_data_addr(e->menu.menu_ptr,\
		&e->img.bpp, &e->img.sl, &e->img.e);
	while (y < e->img.height)
	{
		x = 0;
		while (x < e->img.width)
		{
			ft_put_pixel(e->menu.menu_img, x, y, 0x26000000);
			x++;
		}
		y++;
	}
}

int		show_menu(t_env *e)
{
	e->menu.menu_ptr = mlx_new_image(e->mlx_ptr, e->img.width, e->img.height);
	draw_menu(e);
	mlx_put_image_to_window(e->mlx_ptr, e->mlx_win, e->menu.menu_ptr, 0, 0);
	if (e->menu.on == -1)
	{
		mlx_string_put(e->mlx_ptr, e->mlx_win, 20, 20, 0x333333, "  1. Continue");
		mlx_string_put(e->mlx_ptr, e->mlx_win, 20, 40, 0xFFFFFF, "  2. Start");
	}
	else
	{
		mlx_string_put(e->mlx_ptr, e->mlx_win, 20, 20, 0xFFFFFF, "  1. Continue");
		mlx_string_put(e->mlx_ptr, e->mlx_win, 20, 40, 0xFFFFFF, "  2. New game");
	}
	mlx_string_put(e->mlx_ptr, e->mlx_win, 20, 60, 0xFFFFFF, "ESC. Quit");
	return (0);
}
