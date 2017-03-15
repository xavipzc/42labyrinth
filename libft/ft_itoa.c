/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xpouzenc <xpouzenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:37:06 by xpouzenc          #+#    #+#             */
/*   Updated: 2016/11/21 16:09:42 by xpouzenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_itoa(int n)
{
	int		size;
	char	*tab;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_intlen(n);
	if ((tab = (char*)malloc(sizeof(*tab) * (size + 1))) == NULL)
		return (NULL);
	tab[size] = '\0';
	size--;
	if (n < 0)
	{
		tab[0] = '-';
		n *= -1;
	}
	while (n != 0)
	{
		tab[size] = n % 10 + '0';
		n = n / 10;
		size--;
	}
	return (tab);
}
