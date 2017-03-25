/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PZC <PZC@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:19:26 by PZC               #+#    #+#             */
/*   Updated: 2017/03/25 19:04:04 by PZC              ###   ########.fr       */
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
			if (WIN == 1)
				ft_put_pixel(e->menu.menu_img, x, y, BLACK);
			else
				ft_put_pixel(e->menu.menu_img, x, y, 0x1A000000);
			x++;
		}
		y++;
	}
}

int			show_menu(t_env *e)
{
	if (e->menu.menu_ptr != NULL)
		mlx_destroy_image(e->mlx_ptr, e->menu.menu_ptr);
	if (!(e->menu.menu_ptr = mlx_new_image(e->mlx_ptr, e->img.width,\
		e->img.height)))
		show_error(4);
	draw_menu(e);
	mlx_put_image_to_window(e->mlx_ptr, e->mlx_win, e->menu.menu_ptr, 0, 0);
	if (WIN == 1)
		mlx_string_put(e->mlx_ptr, e->mlx_win, 340, 200, BLUE, "Y O U  W I N");
	else
		mlx_string_put(e->mlx_ptr, e->mlx_win, 340, 200, BLUE, " [ M E N U ]");
	mlx_string_put(e->mlx_ptr, e->mlx_win, 340, 220, BLUE, "     ---    ");
	if ((MENU == -1 && SAVE == 0) || WIN == 1)
		mlx_string_put(e->mlx_ptr, e->mlx_win, 340, 260, GREY3, "[1] Continue");
	else
		mlx_string_put(e->mlx_ptr, e->mlx_win, 340, 260, WHITE, "[1] Continue");
	mlx_string_put(e->mlx_ptr, e->mlx_win, 340, 280, WHITE, "[2] New game");
	mlx_string_put(e->mlx_ptr, e->mlx_win, 340, 300, WHITE, " [ESC] Quit");
	mlx_string_put(e->mlx_ptr, e->mlx_win, 340, 340, GREY9, "  [M] Menu");
	return (0);
}
