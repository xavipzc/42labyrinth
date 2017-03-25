/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PZC <PZC@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:40:45 by PZC               #+#    #+#             */
/*   Updated: 2017/03/25 19:03:06 by PZC              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	error_sound(t_env *e)
{
	if ((((int)POS_X == 22 && (int)POS_Y == 18)\
		|| ((int)POS_X == 2 && (int)POS_Y == 2)\
		|| (((int)POS_X == 9 || (int)POS_X == 11) && (int)POS_Y == 17)\
		|| (((int)POS_X == 6 || (int)POS_X == 8) && (int)POS_Y == 2)))
		ERROR = 1;
	else
		ERROR = 0;
	if (ERROR == 1 && SOUND == 0)
	{
		system("afplay data/error.wav &");
		SOUND = 1;
	}
	if (ERROR == 0)
		SOUND = 0;
}

void		event_append(t_env *e)
{
	error_sound(e);
	if (((int)POS_Y >= 1 && (int)POS_Y <= 10) && ((int)POS_X >= 15 &&\
		(int)POS_X <= 22) && SUSPENS == 0 && MENU == 0)
	{
		system("afplay data/music.wav &");
		SUSPENS = 1;
	}
	if ((int)POS_X == 14 && (int)POS_Y == 9 && SUSPENS == 1)
	{
		system("killall afplay");
		SUSPENS = 0;
	}
	if ((int)POS_X == 18 && (int)POS_Y == 22)
		mlx_string_put(e->mlx_ptr, e->mlx_win, 250, 280, BLACK,\
			" - Use [SPACE BAR] to action - ");
	if ((int)POS_X == 22 && (int)POS_Y == 22)
		mlx_string_put(e->mlx_ptr, e->mlx_win, 250, 280, WHITE,\
			" - Use [ARROWS] to move - ");
}

static void	open_sound(t_env *e)
{
	if ((((int)POS_X == 1 && (int)POS_Y == 17)\
		|| ((int)POS_X == 9 && (int)POS_Y == 8)\
		|| ((int)POS_X == 18 && (int)POS_Y == 1)\
		|| ((int)POS_X == 16 && (int)POS_Y == 15)\
		|| ((int)POS_X == 18 && (int)POS_Y == 22)))
		system("afplay data/door.wav &");
	if ((int)POS_X == 17 && (int)POS_Y == 6)
	{
		MENU = 1;
		system("killall afplay");
		system("afplay data/win.wav &");
		if (SAVE == 1)
			system("rm levels/save.wolf");
	}
}

void		action_event(t_env *e)
{
	if (MAP[1][16] == 2 && (int)POS_X == 1 && (int)POS_Y == 17)
		MAP[1][16] = 0;
	if (MAP[8][8] == 2 && (int)POS_X == 9 && (int)POS_Y == 8)
		MAP[8][8] = 0;
	if (MAP[18][2] == 2 && (int)POS_X == 18 && (int)POS_Y == 1)
		MAP[18][2] = 0;
	if (MAP[17][22] == 2 && (int)POS_X == 18 && (int)POS_Y == 22)
		MAP[17][22] = 0;
	if (MAP[17][15] == 2 && (int)POS_X == 16 && (int)POS_Y == 15)
		MAP[17][15] = 0;
	if (MAP[17][5] == 3 && (int)POS_X == 17 && (int)POS_Y == 6)
		WIN = 1;
	open_sound(e);
}
