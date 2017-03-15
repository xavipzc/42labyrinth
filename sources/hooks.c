/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PZC <PZC@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:24:52 by PZC               #+#    #+#             */
/*   Updated: 2017/03/14 14:31:08 by PZC              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** 1 = S 				< S
** 4 = Scroll up 		< Zoom +
** 5 = Scroll down 		< Zoom -
** 15 = R 				< Reset
** 34 = I 				< Iter +
** 31 = O 				< Iter -
** 8 = C 				< Color palette
** 53 = ESC 			< QUIT
** 126 = Up arrow		< MOVE UP
** 125 = Down arrow 	< MOVE DOWN
** 124 = Right arrow	< MOVE RIGHT
** 123 = Left arrow		< MOVE LEFT
*/

int		key_hook(int key, t_env *e)
{
	//printf("%d\n", key);
	//if (key == 123 || key == 124 || key == 125 || key == 126)
		//move(e, key);
	if (key == 53)
	{
		mlx_destroy_window(e->mlx_ptr, e->mlx_win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

/*
** Mouse Position
*/

// int		mouse_pos(int x, int y, t_env *e)
// {
// 	if (x > 0 && x < W_WIDTH && y > 0 && y < W_HEIGHT)
// 	{
// 		e->f.c_r = (double)x / W_WIDTH;
// 		e->f.c_i = (double)y / W_HEIGHT;
// 		while (e->f.c_r > 0.5)
// 			e->f.c_r /= 10;
// 		while (e->f.c_i > 0.5)
// 			e->f.c_i /= 10;
// 		while (e->f.c_r < -0.5)
// 			e->f.c_r *= 10;
// 		while (e->f.c_i < -0.5)
// 			e->f.c_i *= 10;
// 		reset_img(e);
// 	}
// 	return (0);
// }
