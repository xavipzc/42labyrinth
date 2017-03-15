/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xpouzenc <xpouzenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 11:18:44 by xpouzenc          #+#    #+#             */
/*   Updated: 2016/11/18 18:13:04 by xpouzenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	if (c == '\0')
		return ((char*)s + len);
	while (0 < (len + 1))
	{
		if (s[len] == (unsigned char)c)
			return ((char*)s + len);
		len--;
	}
	return (NULL);
}
