/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xpouzenc <xpouzenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:47:49 by xpouzenc          #+#    #+#             */
/*   Updated: 2016/11/17 14:46:37 by xpouzenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	size;
	char			*s2;

	if (!s)
		return (NULL);
	i = 0;
	size = start + len;
	s2 = (char*)malloc(sizeof(*s2) * (len + 1));
	if (s2 == NULL)
		return (NULL);
	while (start < size)
	{
		s2[i] = s[start];
		start++;
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
