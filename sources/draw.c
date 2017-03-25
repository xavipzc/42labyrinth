/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PZC <PZC@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 12:03:26 by xpouzenc          #+#    #+#             */
/*   Updated: 2017/03/25 18:51:58 by PZC              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_put_pixel(unsigned int *img, int x, int y, int color)
{
	img[(y * W_WIDTH) + x] = color;
}

void	draw_vline(t_env *e, int x)
{
	int y;

	y = 0;
	e->view = (unsigned int*)mlx_get_data_addr(e->img_ptr, &e->img.bpp,\
		&e->img.sl, &e->img.e);
	while (y < R_Y_START)
	{
		ft_put_pixel(e->view, x, y, SKY);
		y++;
	}
	while (R_Y_START <= R_Y_END)
	{
		ft_put_pixel(e->view, x, R_Y_START, COLOR);
		R_Y_START++;
	}
	while (R_Y_START < W_HEIGHT)
	{
		ft_put_pixel(e->view, x, R_Y_START, GREY9);
		R_Y_START++;
	}
}
