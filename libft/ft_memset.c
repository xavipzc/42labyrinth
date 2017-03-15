/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xpouzenc <xpouzenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:03:47 by xpouzenc          #+#    #+#             */
/*   Updated: 2016/11/10 13:31:42 by xpouzenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	w;
	char	*tab;

	i = 0;
	w = (char)c;
	tab = (char*)b;
	while (i < len)
	{
		tab[i] = w;
		i++;
	}
	return (tab);
}
