/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xpouzenc <xpouzenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 12:04:24 by xpouzenc          #+#    #+#             */
/*   Updated: 2017/03/24 18:36:31 by xpouzenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			main(int ac, char **av)
{
	t_env e;

	if (ac < 2)
	{
		is_savefile(&e);
		if (e.save_file == 0)
			e.menu.on = -1;
		else
			e.menu.on = 1;
		readfile(&e);
		init_env(&e, av[0] + 2);
		mlx_loop_hook(e.mlx_ptr, loop_hook, &e);
		mlx_hook(e.mlx_win, 2, (1L << 0), key_press, &e);
		mlx_hook(e.mlx_win, 3, (1L << 1), key_release, &e);
		mlx_hook(e.mlx_win, 17, (1L << 17), quit_window, &e);
		mlx_loop(e.mlx_ptr);
	}
	else
		show_error(1);
	return (0);
}
