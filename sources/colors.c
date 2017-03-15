/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PZC <PZC@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:50:54 by PZC               #+#    #+#             */
/*   Updated: 2017/03/14 17:56:56 by PZC              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wall_color(t_env *e, int (*tab)[24][24])
{
	if ((*tab)[e->r.map.x][e->r.map.y] == 1)
		e->color = 0xFF0000; //red
	if ((*tab)[e->r.map.x][e->r.map.y] == 2)
		e->color = 0x00FF00; //green
	if ((*tab)[e->r.map.x][e->r.map.y] == 3)
		e->color = 0x0000FF; //blue
	if ((*tab)[e->r.map.x][e->r.map.y] == 4)
		e->color = 0xFFFFFF; //white
	if ((*tab)[e->r.map.x][e->r.map.y] == 5)
		e->color = 0xFFFF00; //yellow
	if (e->p.side == 1)
		e->color = e->color / 2;
}
