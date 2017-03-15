/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xpouzenc <xpouzenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 15:35:37 by xpouzenc          #+#    #+#             */
/*   Updated: 2017/03/15 14:10:33 by xpouzenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	show_usage(void)
{
	ft_putendl("usage:\t./wolf3d");
}

static void	malloc_error(void)
{
	ft_putendl_fd("malloc error", 2);
	exit(1);
}

static void	read_error(void)
{
	ft_putendl_fd("read error", 2);
	exit(1);
}

void		show_error(int n)
{
	if (n == 1)
		show_usage();
	if (n == 2)
		malloc_error();
	if (n == 3)
		read_error();
}
