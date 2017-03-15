/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xpouzenc <xpouzenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 14:28:41 by xpouzenc          #+#    #+#             */
/*   Updated: 2016/11/16 15:45:46 by xpouzenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	j = 0;
	size = ft_strlen(little);
	if (size == 0)
		return ((char*)big);
	while (big[i] && (i + size) <= len)
	{
		while (little[j] == big[i + j])
		{
			if (j == size - 1)
				return ((char*)big + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
