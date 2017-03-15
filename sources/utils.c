/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PZC <PZC@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:16:23 by xpouzenc          #+#    #+#             */
/*   Updated: 2017/03/16 00:15:56 by PZC              ###   ########.fr       */
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

void			show_fps(t_env *e)
{
	double frame_time;

	e->old_time = e->cur_time;
	e->cur_time = get_tick_count();
	frame_time = (e->cur_time - e->old_time) / 1000.0;
	e->move_s = frame_time * 5.0;
	e->rot_s = frame_time * 3.0;
}
