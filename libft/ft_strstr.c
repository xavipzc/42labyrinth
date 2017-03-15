/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xpouzenc <xpouzenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 11:30:34 by xpouzenc          #+#    #+#             */
/*   Updated: 2016/11/16 14:27:24 by xpouzenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int	i;
	int	j;
	int len;

	i = 0;
	j = 0;
	len = ft_strlen(little);
	if (len == 0)
		return ((char*)big);
	while (big[i])
	{
		while (little[j] == big[i + j])
		{
			if (j == len - 1)
				return ((char*)big + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
