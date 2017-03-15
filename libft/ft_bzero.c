/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xpouzenc <xpouzenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:38:37 by xpouzenc          #+#    #+#             */
/*   Updated: 2016/11/10 13:53:25 by xpouzenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*s2;

	i = 0;
	s2 = (char*)s;
	if (n > 0)
	{
		while (i < n)
		{
			s2[i] = '\0';
			i++;
		}
	}
}