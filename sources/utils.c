/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PZC <PZC@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:16:23 by PZC               #+#    #+#             */
/*   Updated: 2017/03/14 18:00:44 by PZC              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

unsigned	getTickCount(void)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (0);
	return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

void		show_fps(t_env *e)
{
	double frame_time;

	e->old_time = e->cur_time;
    e->cur_time = getTickCount();
    frame_time = (e->cur_time - e->old_time) / 1000.0; //frame_time is the time this frame has taken, in seconds
    printf("FPS = %f\n", 1.0 / frame_time); //FPS counter
}
