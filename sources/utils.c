/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PZC <PZC@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:16:23 by xpouzenc          #+#    #+#             */
/*   Updated: 2017/03/25 19:04:21 by PZC              ###   ########.fr       */
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
	MOVE_SPEED = frame_time * 4.0;
	ROT_SPEED = frame_time * 2.0;
}

/*
** Save & Reset the game
*/

void			is_savefile(t_env *e)
{
	int fd;

	if ((fd = open("levels/save.wolf", O_RDONLY)) == -1)
		SAVE = 0;
	else
		SAVE = 1;
	close(fd);
}

void			reset_game(t_env *e)
{
	POS_X = 22;
	POS_Y = 22;
	DIR_X = -1;
	DIR_Y = 0;
	PLANE_X = 0;
	PLANE_Y = 0.66;
	CAMERA_X = 0;
	MENU = 0;
	SUSPENS = 0;
	WIN = 0;
}

void			save_game(t_env *e)
{
	int fd;

	if (!(fd = open("levels/save.wolf", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR)))
		show_error(3);
	ft_putnendl_fd((int)fabs(POS_X), fd);
	ft_putnendl_fd((int)fabs(POS_Y), fd);
	if (close(fd) == -1)
		show_error(3);
}
