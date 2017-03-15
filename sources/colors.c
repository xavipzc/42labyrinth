/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xpouzenc <xpouzenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 11:48:30 by xpouzenc          #+#    #+#             */
/*   Updated: 2017/03/15 16:51:42 by xpouzenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wall_color(t_env *e)
{
	if (e->map[e->r.map.x][e->r.map.y] == 1)
		e->color = 0xFF0000; //red
	if (e->map[e->r.map.x][e->r.map.y] == 2)
		e->color = 0x00FF00; //green
	if (e->map[e->r.map.x][e->r.map.y] == 3)
		e->color = 0x0000FF; //blue
	if (e->map[e->r.map.x][e->r.map.y] == 4)
		e->color = 0xFFFFFF; //white
	if (e->map[e->r.map.x][e->r.map.y] == 5)
		e->color = 0xFFFF00; //yellow
	if (e->p.side == 1)
		e->color = e->color / 2;
}
