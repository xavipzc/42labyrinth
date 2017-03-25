/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PZC <PZC@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 11:48:30 by xpouzenc          #+#    #+#             */
/*   Updated: 2017/03/25 18:51:51 by PZC              ###   ########.fr       */
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
			COLOR = GREY1;
		else if (R_DIR_X < 0 && SIDE == 0)
			COLOR = GREY2;
		else if (R_DIR_Y > 0 && SIDE == 1)
			COLOR = GREY3;
		else
			COLOR = GREY3;
	}
	if (MAP[R_MAP_X][R_MAP_Y] == 2)
		COLOR = GREEN;
	if (MAP[R_MAP_X][R_MAP_Y] == 3)
		COLOR = BLUE;
	if (MAP[R_MAP_X][R_MAP_Y] == 4)
		COLOR = RED;
}
