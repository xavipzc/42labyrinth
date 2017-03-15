/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xpouzenc <xpouzenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 15:47:53 by xpouzenc          #+#    #+#             */
/*   Updated: 2016/11/17 15:46:32 by xpouzenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src <= dst)
	{
		while (len > 0)
		{
			len--;
			((char*)dst)[len] = ((char*)src)[len];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
