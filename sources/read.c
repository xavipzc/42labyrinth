/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xpouzenc <xpouzenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:05:31 by xpouzenc          #+#    #+#             */
/*   Updated: 2017/03/15 16:55:15 by xpouzenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	fill_tab(t_env *e, char *line, int h)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	e->map[h][j] = ft_atoi(&line[i]);
	j++;
	while (j < 24)
	{
		while (line[i] != ',')
			i++;
		i++;
		e->map[h][j] = ft_atoi(&line[i]);
		j++;
	}
	return (0);
}

static int	init_map(t_env *e, char *line)
{
	int	height;
	int	width;
	int	i;

	height = ft_atoi(line);
	e->map = (int**)malloc(sizeof(e->map) * height);
	i = 0;
	while (line[i] != ',')
		i++;
	width = ft_atoi(&line[i + 1]);
	i = 0;
	while (i < height)
	{
		e->map[i] = (int*)malloc(sizeof(e->map[i]) * width);
		i++;
	}
	e->map[i] = NULL;
	return (0);
}

int			readfile(t_env *e)
{
	int		i;
	int		fd;
	int		ret;
	char	*line;

	printf("%f\n", e->cur_time);
	i = 0;
	fd = open("room.wolf", O_RDONLY);
	ret = get_next_line(fd, &line);
	init_map(e, line);
	ft_strdel(&line);
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			show_error(3);
		ft_putendl(line);
		if (i < 24)
			fill_tab(e, line, i);
		ft_strdel(&line);
		i++;
	}
	if (close(fd) == -1)
		return (-1);
	return (0);
}
