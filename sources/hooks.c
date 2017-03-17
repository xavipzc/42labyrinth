/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PZC <PZC@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 11:48:30 by xpouzenc          #+#    #+#             */
/*   Updated: 2017/03/16 14:44:50 by PZC              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** 1 = S 				< Change speed
** 126 = Up arrow		< MOVE UP
** 125 = Down arrow 	< MOVE DOWN
** 124 = Right arrow	< MOVE RIGHT
** 123 = Left arrow		< MOVE LEFT
** 53 = ESC 			< QUIT
*/

int		key_press(int key, t_env *e)
{
	if (key == 126)
		MOVE_UP = 1;
	if (key == 125)
		MOVE_DOWN = 1;
	if (key == 123)
		MOVE_LEFT = 1;
	if (key == 124)
		MOVE_RIGHT = 1;
	if (key == 1)
		SPEEDX2 = 1;
	return (0);
}

int		key_release(int key, t_env *e)
{
	if (key == 126)
		MOVE_UP = 0;
	if (key == 125)
		MOVE_DOWN = 0;
	if (key == 123)
		MOVE_LEFT = 0;
	if (key == 124)
		MOVE_RIGHT = 0;
	if (key == 1)
		SPEEDX2 = 0;
	if (key == 53)
	{
		mlx_destroy_window(e->mlx_ptr, e->mlx_win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
