/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xpouzenc <xpouzenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 12:37:43 by PZC               #+#    #+#             */
/*   Updated: 2017/03/17 14:39:39 by xpouzenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	rot_player(t_env *e, int w)
{
	double	tmp;
	double	tmp2;

	if (w == 2)
		ROT_SPEED *= -1;
	tmp = DIR_X;
	DIR_X = DIR_X * cos(ROT_SPEED) - DIR_Y * sin(ROT_SPEED);
	DIR_Y = tmp * sin(ROT_SPEED) + DIR_Y * cos(ROT_SPEED);
	tmp2 = PLANE_X;
	PLANE_X = PLANE_X * cos(ROT_SPEED) - PLANE_Y * sin(ROT_SPEED);
	PLANE_Y = tmp2 * sin(ROT_SPEED) + PLANE_Y * cos(ROT_SPEED);
}

void		move_player(t_env *e)
{
	if (SPEEDX2)
		MOVE_SPEED *= 2;
	if (MOVE_UP)
	{
		if (!(MAP[(int)(POS_X + DIR_X * MOVE_SPEED)][(int)POS_Y]))
			POS_X += DIR_X * MOVE_SPEED;
		if (!(MAP[(int)(POS_X)][(int)(POS_Y + DIR_Y * MOVE_SPEED)]))
			POS_Y += DIR_Y * MOVE_SPEED;
	}
	if (MOVE_DOWN)
	{
		if (!(MAP[(int)(POS_X - DIR_X * MOVE_SPEED)][(int)POS_Y]))
			POS_X -= DIR_X * MOVE_SPEED;
		if (!(MAP[(int)(POS_X)][(int)(POS_Y - DIR_Y * MOVE_SPEED)]))
			POS_Y -= DIR_Y * MOVE_SPEED;
	}
	if (MOVE_LEFT)
		rot_player(e, 1);
	if (MOVE_RIGHT)
		rot_player(e, 2);
}
