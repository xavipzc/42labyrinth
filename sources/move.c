/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PZC <PZC@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 12:37:43 by PZC               #+#    #+#             */
/*   Updated: 2017/03/16 14:55:55 by PZC              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void rot_player(t_env *e, int w)
{
	double	tmp;
	double	tmp2;

	if (w == 2)
		R_SPEED *= -1;
	tmp = DIR_X;
	DIR_X = DIR_X * cos(R_SPEED) - DIR_Y * sin(R_SPEED);
	DIR_Y = tmp * sin(R_SPEED) + DIR_Y * cos(R_SPEED);
	tmp2 = PLANE_X;
	PLANE_X = PLANE_X * cos(R_SPEED) - PLANE_Y * sin(R_SPEED);
	PLANE_Y = tmp2 * sin(R_SPEED) + PLANE_Y * cos(R_SPEED);
}

void		move_player(t_env *e)
{
	if (SPEEDX2)
		M_SPEED *= 2;
	if (MOVE_UP)
	{
		if (!(MAP[(int)(POS_X + DIR_X * M_SPEED)][(int)POS_Y]))
			POS_X += DIR_X * M_SPEED;
		if (!(MAP[(int)(POS_X)][(int)(POS_Y + DIR_Y * M_SPEED)]))
			POS_Y += DIR_Y * M_SPEED;
	}
	if (MOVE_DOWN)
	{
		if (!(MAP[(int)(POS_X - DIR_X * M_SPEED)][(int)POS_Y]))
			POS_X -= DIR_X * M_SPEED;
		if (!(MAP[(int)(POS_X)][(int)(POS_Y - DIR_Y * M_SPEED)]))
			POS_Y -= DIR_Y * M_SPEED;
	}
	if (MOVE_LEFT)
		rot_player(e, 1);
	if (MOVE_RIGHT)
		rot_player(e, 2);
}
