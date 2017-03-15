/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xpouzenc <xpouzenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:57:05 by xpouzenc          #+#    #+#             */
/*   Updated: 2016/11/22 16:06:52 by xpouzenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	size_t	size;
	char	*s2;

	if (s && f)
	{
		i = 0;
		size = ft_strlen(s);
		s2 = (char*)malloc(sizeof(*s2) * (size + 1));
		if (s2 == NULL)
			return (NULL);
		while (i < size)
		{
			s2[i] = (*f)(s[i]);
			i++;
		}
		s2[i] = '\0';
		return (s2);
	}
	else
		return (NULL);
}
