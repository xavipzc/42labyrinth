/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xpouzenc <xpouzenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 12:04:24 by xpouzenc          #+#    #+#             */
/*   Updated: 2017/03/15 16:52:59 by xpouzenc         ###   ########.fr       */
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
		loop_hook(&e);
		//mlx_loop_hook(e.mlx_ptr, &loop_hook, &e);
		mlx_key_hook(e.mlx_win, key_hook, &e);
		mlx_loop(e.mlx_ptr);
	}
	else
		show_error(1);
	return (0);
}
