/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xpouzenc <xpouzenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:37:41 by xpouzenc          #+#    #+#             */
/*   Updated: 2016/11/22 15:48:35 by xpouzenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			s2[i] = (*f)(i, s[i]);
			i++;
		}
		s2[i] = '\0';
		return (s2);
	}
	else
		return (NULL);
}
