/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PZC <PZC@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 12:03:26 by xpouzenc          #+#    #+#             */
/*   Updated: 2017/03/23 19:17:14 by PZC              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_put_pixel(unsigned int* img, int x, int y, int color)
{
	img[(y * W_WIDTH) + x] = color;
}

void	draw_vline(t_env *e, int x)
{
	int y;

	y = 0;
	e->view = (unsigned int*)mlx_get_data_addr(e->img_ptr, &e->img.bpp,\
		&e->img.sl, &e->img.e);
	while (y < e->r.y_start)
	{
		ft_put_pixel(e->view, x, y, 0x33DAFF);
		y++;
	}
	while (e->r.y_start <= e->r.y_end)
	{
		ft_put_pixel(e->view, x, e->r.y_start, e->color);
		e->r.y_start++;
	}
	while (e->r.y_start < W_HEIGHT)
	{
		ft_put_pixel(e->view, x, e->r.y_start, 0x999999);
		e->r.y_start++;
	}
}
