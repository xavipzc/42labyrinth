/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: PZC <PZC@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:07:36 by xpouzenc          #+#    #+#             */
/*   Updated: 2017/01/30 14:51:43 by PZC              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static int		ft_count_words(char const *s, char c)
{
	int	i;
	int	j;
	int	word;

	i = 0;
	j = 0;
	word = 0;
	if (s[0] != '\0' && s[0] != c)
		word++;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			j++;
			if (s[i] != c && s[i] != '\0')
				word++;
		}
		else
			i++;
	}
	if (i != 0 && word == 0 && i != j)
		word = 1;
	return (word);
}

static int		ft_wordlen(const char *s, char c, int *j)
{
	int	len;

	len = 0;
	while (s[*j] != c && s[*j])
	{
		len++;
		*j += 1;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		word;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	word = ft_count_words(s, c);
	if ((tab = (char**)malloc(sizeof(*tab) * (word + 1))) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < word && s[j])
	{
		while (s[j] == c && s[j])
			j++;
		tab[i] = ft_strsub(s, j, ft_wordlen(s, c, &j));
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
