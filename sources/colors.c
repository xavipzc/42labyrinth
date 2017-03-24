/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xpouzenc <xpouzenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 11:48:30 by xpouzenc          #+#    #+#             */
/*   Updated: 2017/03/24 12:44:52 by xpouzenc         ###   ########.fr       */
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
	{
		if (R_DIR_X > 0 && SIDE == 0)
			e->color = 0x111111;
		else if (R_DIR_X < 0 && SIDE == 0)
			e->color = 0x222222;
		else if (R_DIR_Y > 0 && SIDE == 1)
			e->color = GREY3;
		else
			e->color = GREY3;
	}
	if (MAP[R_MAP_X][R_MAP_Y] == 2)
		e->color = 0x00FF00;
	if (MAP[R_MAP_X][R_MAP_Y] == 3)
		e->color = 0x33FFD7;
	if (MAP[R_MAP_X][R_MAP_Y] == 4)
		e->color = 0xFF0000;
}
