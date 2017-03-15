/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xpouzenc <xpouzenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:11:41 by xpouzenc          #+#    #+#             */
/*   Updated: 2016/11/22 15:26:56 by xpouzenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*tab;

	i = 0;
	tab = (void*)malloc(size);
	if (tab == NULL)
		return (NULL);
	ft_memset(tab, '\0', size);
	return (tab);
}
