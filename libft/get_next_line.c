/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xpouzenc <xpouzenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 15:26:41 by xpouzenc          #+#    #+#             */
/*   Updated: 2016/12/28 19:09:10 by xpouzenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_stock(char **stock, char **line)
{
	char	*cursor;

	if ((cursor = ft_strchr(*stock, '\n')))
	{
		*cursor = '\0';
		*line = ft_strdup(*stock);
		ft_strcpy(*stock, cursor + 1);
		return (1);
	}
	return (0);
}

static int	check_buffer(char *buffer, char **stock, char **line)
{
	char	*cursor;
	char	*tmp;

	if (!*stock)
		*stock = ft_strnew(0);
	if ((cursor = ft_strchr(buffer, '\n')))
	{
		*cursor = '\0';
		*line = ft_strjoin(*stock, buffer);
		ft_strdel(stock);
		ft_strdel(&buffer);
		*stock = ft_strdup(cursor + 1);
		return (1);
	}
	tmp = *stock;
	*stock = ft_strjoin(*stock, buffer);
	ft_strdel(&tmp);
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*stock = NULL;
	char		*buffer;
	int			ret;

	if (stock)
		if ((check_stock(&stock, line)))
			return (1);
	buffer = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		if (ret == -1 || fd < 0 || !line)
			return (-1);
		buffer[ret] = '\0';
		if (check_buffer(buffer, &stock, line))
			return (1);
	}
	ft_strdel(&buffer);
	if (stock == NULL || stock[0] == '\0')
		return (0);
	*line = ft_strdup(stock);
	ft_strdel(&stock);
	return (1);
}
