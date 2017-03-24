/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PZC <PZC@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:40:45 by PZC               #+#    #+#             */
/*   Updated: 2017/03/23 21:41:49 by PZC              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	action_event(t_env *e)
{
	if (MAP[8][8] == 2 && (int)POS_X == 9 && (int)POS_Y == 8)
		MAP[8][8] = 0;
	if (MAP[18][3] == 2 && (int)POS_X == 18 && (int)POS_Y == 2)
		MAP[18][3] = 0;
	if (MAP[17][22] == 2 && (int)POS_X == 18 && (int)POS_Y == 22)
		MAP[17][22] = 0;
}

void 	music_append(t_env *e)
{
	if ((int)POS_X == 21 && (int)POS_Y == 7 && e->music == 0)
	{
		printf("MUSIC ON\n");
		system("afplay data/music.wav &");
		e->music = 1;
	}
	if ((int)POS_X == 21 && (int)POS_Y == 8 && e->music == 1)
	{
		printf("MUSIC OFF\n");
		system("killall afplay");
		e->music = 0;
	}
}
