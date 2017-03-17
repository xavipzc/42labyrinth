/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PZC <PZC@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:16:23 by xpouzenc          #+#    #+#             */
/*   Updated: 2017/03/16 15:34:57 by PZC              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static unsigned	get_tick_count(void)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (0);
	return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

/*
** FPS counter
** frame_time is the time this frame has taken, in seconds
*/

void			get_fps(t_env *e)
{
	double frame_time;

	OLD_TIME = TIME;
	TIME = get_tick_count();
	frame_time = (TIME - OLD_TIME) / 1000.0;
	M_SPEED = frame_time * 5.0;
	R_SPEED = frame_time * 2.0;
}
