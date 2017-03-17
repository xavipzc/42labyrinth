/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PZC <PZC@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 11:48:30 by xpouzenc          #+#    #+#             */
/*   Updated: 2017/03/16 13:03:07 by PZC              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wall_color(t_env *e)
{
	if (MAP[e->r.map.x][e->r.map.y] == 1)
		e->color = 0xFF0000; //red
	if (MAP[e->r.map.x][e->r.map.y] == 2)
		e->color = 0x00FF00; //green
	if (MAP[e->r.map.x][e->r.map.y] == 3)
		e->color = 0x0000FF; //blue
	if (MAP[e->r.map.x][e->r.map.y] == 4)
		e->color = 0xFFFFFF; //white
	if (MAP[e->r.map.x][e->r.map.y] == 5)
		e->color = 0xFFFF00; //yellow
	if (e->p.side == 1)
		e->color = e->color / 2;
}
