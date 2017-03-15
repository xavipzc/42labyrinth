/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PZC <PZC@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 12:04:24 by xpouzenc          #+#    #+#             */
/*   Updated: 2017/03/16 00:14:23 by PZC              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	main(int ac, char **av)
{
	t_env e;

	if (ac < 2)
	{
		printf("%s\n", av[0]);
		readfile(&e);
		init_env(&e);
		//loop_hook(&e);
		mlx_loop_hook(e.mlx_ptr, loop_hook, &e);
		mlx_key_hook(e.mlx_win, key_hook, &e);
		mlx_hook(e.mlx_win, 2, (1L << 0), key_press, &e);
		//mlx_hook(e.mlx_win, 3, (1L << 1), &key_release, &e);
		mlx_loop(e.mlx_ptr);
	}
	else
		show_error(1);
	return (0);
}
