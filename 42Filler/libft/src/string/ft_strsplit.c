/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:59:58 by mbui              #+#    #+#             */
/*   Updated: 2021/04/02 13:46:22 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	lstring(char const *s, int start, char c)
{
	int	end;

	end = 0;
	while (s[start + end] != c)
		end++;
	return (end);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab = (char **)malloc(sizeof(char *) * nbwords(s, c) + 1);
	if (s == 0 || !tab)
		return (NULL);
	while (j < nbwords(s, c))
	{
		if (s[i] == c)
			i++;
		else
		{
			tab[j] = ft_strsub(s, i, lstring(s, i, c));
			if (!tab[j])
				return (free_tab(tab, j));
			i = i + ft_strlen(tab[j]);
			j++;
		}
	}
	tab[j] = 0;
	return (tab);
}
