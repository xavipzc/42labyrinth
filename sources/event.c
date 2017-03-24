/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xpouzenc <xpouzenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:40:45 by PZC               #+#    #+#             */
/*   Updated: 2017/03/24 19:00:41 by xpouzenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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
}

static void	error_sound(t_env *e)
{
	if ((((int)POS_X == 22 && (int)POS_Y == 18) || ((int)POS_X == 9\
		&& (int)POS_Y == 17) || ((int)POS_X == 11 && (int)POS_Y == 17)))
		e->m.error = 1;
	else
		e->m.error = 0;
	if (e->m.error == 1 && e->music == 0)
	{
		system("afplay data/error.wav &");
		e->music = 1;
	}
	if (e->m.error == 0)
		e->music = 0;
}

void		event_append(t_env *e)
{
	error_sound(e);
	if (((int)POS_Y >= 1 && (int)POS_Y <= 10) && ((int)POS_X >= 15 && (int)POS_X <= 22) && e->music == 0 && e->m.error == 0)
	{
		printf("TEST\n");
		//system("afplay data/music.wav &");
		e->music = 1;
	}
	if ((int)POS_X == 14 && (int)POS_Y == 9 && e->music == 1 && e->m.error == 0)
	{
		system("killall afplay");
		e->music = 0;
	}
	if ((int)POS_X == 18 && (int)POS_Y == 22)
		mlx_string_put(e->mlx_ptr, e->mlx_win, 250, 280, BLACK,\
			" - Use [SPACE BAR] to action - ");
	if ((int)POS_X == 22 && (int)POS_Y == 22)
		mlx_string_put(e->mlx_ptr, e->mlx_win, 250, 280, WHITE,\
			" - Use [ARROWS] to move - ");
}
