/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PZC <PZC@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:05:31 by xpouzenc          #+#    #+#             */
/*   Updated: 2017/03/25 16:38:14 by PZC              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	fill_tab(t_env *e, char *line, int h)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	MAP[h][j] = ft_atoi(&line[i]);
	if (ft_isdigit(MAP[h][j] + '0') == 0)
		show_error(3);
	j++;
	while (j < e->m.width)
	{
		while (line[i] != ',')
			i++;
		i++;
		MAP[h][j] = ft_atoi(&line[i]);
		if (ft_isdigit(MAP[h][j] + '0') == 0)
			show_error(3);
		j++;
	}
	return (0);
}

static int	init_map(t_env *e, char *line)
{
	int	i;

	MAP = NULL;
	e->m.height = ft_atoi(line);
	if (!(MAP = (int**)malloc(sizeof(int*) * e->m.height)))
		show_error(2);
	i = 0;
	while (line[i] != ',')
		i++;
	e->m.width = ft_atoi(&line[i + 1]);
	i = 0;
	while (i < e->m.height)
	{
		if (!(MAP[i] = (int*)malloc(sizeof(int) * e->m.width)))
			show_error(2);
		i++;
	}
	return (0);
}

int			readfile(t_env *e)
{
	int		i;
	int		fd;
	int		ret;
	char	*line;

	i = 0;
	if ((fd = open("levels/lvl_1.wolf", O_RDONLY)) == -1)
		show_error(3);
	ret = get_next_line(fd, &line);
	init_map(e, line);
	ft_strdel(&line);
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			show_error(3);
		if (i < e->m.height)
			fill_tab(e, line, i);
		ft_strdel(&line);
		i++;
	}
	if (close(fd) == -1)
		show_error(3);
	return (0);
}
