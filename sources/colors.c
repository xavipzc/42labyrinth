/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PZC <PZC@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 11:48:30 by xpouzenc          #+#    #+#             */
/*   Updated: 2017/03/22 13:59:09 by PZC              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** 1 = RED
** 2 = GREEN
** 3 = BLUE
** 4 = GREY
** 5 = YELLOW
*/

void	wall_color(t_env *e)
{
	if (MAP[R_MAP_X][R_MAP_Y] == 1)
		e->color = 0xFF0000;
	if (MAP[R_MAP_X][R_MAP_Y] == 2)
		e->color = 0x00FF00;
	if (MAP[R_MAP_X][R_MAP_Y] == 3)
		e->color = 0x0000FF;
	if (MAP[R_MAP_X][R_MAP_Y] == 4)
		e->color = 0xAAAAAA;
	if (MAP[R_MAP_X][R_MAP_Y] == 5)
		e->color = 0xFFFF00;
	if (SIDE == 1)
		e->color /= 2;
}
