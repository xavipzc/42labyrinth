/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PZC <PZC@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:14:16 by PZC               #+#    #+#             */
/*   Updated: 2017/03/14 18:19:31 by PZC              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_put_pixel(t_env *e, int x, int y, int color)
{
	e->view[(y * W_WIDTH) + x] = color;
}

void	draw_vline(t_env *e, int x, int y1, int y2, int color)
{
	int y = 0;

	e->view = (unsigned int*)mlx_get_data_addr(e->img_ptr, &e->img.bpp, &e->img.sl,\
			&e->img.e);
	while (y < y1)
	{
		ft_put_pixel(e, x, y, 0xFFFFFF);
		y++;
	}
	while (y1 <= y2)
	{
		ft_put_pixel(e, x, y1, color);
		y1++;
	}
	while (y1 < W_HEIGHT)
	{
		ft_put_pixel(e, x, y1, 0x7e5f1a);
		y1++;
	}
}