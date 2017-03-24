/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xpouzenc <xpouzenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 11:48:30 by xpouzenc          #+#    #+#             */
/*   Updated: 2017/03/24 18:31:46 by xpouzenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** 1 = S 				< Change speed
** 126 = Up arrow		< MOVE UP
** 125 = Down arrow 	< MOVE DOWN
** 124 = Right arrow	< MOVE RIGHT
** 123 = Left arrow		< MOVE LEFT
** 46 = M				< MENU
** 83 = 1				< CONTINUE
** 84 = 2				< NEW GAME
** 49 = SPACE BAR 		< ACTION
** 53 = ESC 			< QUIT
*/

int			key_press(int key, t_env *e)
{
	if (key == 126 && e->menu.on == 0)
		MOVE_UP = 1;
	if (key == 125 && e->menu.on == 0)
		MOVE_DOWN = 1;
	if (key == 123 && e->menu.on == 0)
		MOVE_LEFT = 1;
	if (key == 124 && e->menu.on == 0)
		MOVE_RIGHT = 1;
	if (key == 1 && e->menu.on == 0)
		SPEEDX2 = 1;
	return (0);
}

static int	key_release_menu(int key, t_env *e)
{
	if (key == 46 && e->menu.on != -1)
		e->menu.on = 1;
	if ((key == 83 || key == 18) && e->menu.on != -1)
		e->menu.on = 0;
	if ((key == 84 || key == 19) && e->menu.on == -1)
		e->menu.on = 0;
	if ((key == 84 || key == 19) && e->menu.on == 1)
		reset_game(e);
	return (0);
}

int			key_release(int key, t_env *e)
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
	if (key == 49)
		action_event(e);
	if (key == 53)
	{
		save_game(e);
		if (e->music == 1)
			system("killall afplay");
		mlx_destroy_window(e->mlx_ptr, e->mlx_win);
		exit(EXIT_SUCCESS);
	}
	key_release_menu(key, e);
	return (0);
}

int			quit_window(t_env *e)
{
	save_game(e);
	if (e->music == 1)
			system("killall afplay");
	mlx_destroy_window(e->mlx_ptr, e->mlx_win);
	exit(EXIT_SUCCESS);
	return (0);
}
