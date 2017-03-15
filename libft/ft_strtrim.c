/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xpouzenc <xpouzenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:33:37 by xpouzenc          #+#    #+#             */
/*   Updated: 2016/11/17 12:16:47 by xpouzenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strtrim(char const *s)
{
	unsigned int	i;
	size_t			len;
	char			*s2;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	len = ft_strlen(s) - 1;
	while (len > i && (s[len] == ' ' || s[len] == '\t' || s[len] == '\n'))
		len--;
	if (len < i)
		return (s2 = ft_strdup(""));
	return (s2 = ft_strsub(s, i, len - (size_t)i + 1));
}
