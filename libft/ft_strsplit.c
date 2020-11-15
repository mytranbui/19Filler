/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:59:58 by mbui              #+#    #+#             */
/*   Updated: 2019/11/21 15:01:57 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lstring(char const *s, int start, char c)
{
	int	end;

	end = 0;
	while (s[start + end] != c)
		end++;
	return (end);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		l;

	i = 0;
	j = 0;
	if (s == 0 || !(tab = (char **)malloc(sizeof(char *) * nbwords(s, c) + 1)))
		return (NULL);
	while (j < nbwords(s, c))
	{
		if (s[i] == c)
			i++;
		else
		{
			l = lstring(s, i, c);
			if (!(tab[j] = ft_strsub(s, i, l)))
				return (free_tab(tab, j));
			i = i + l;
			j++;
		}
	}
	tab[j] = 0;
	return (tab);
}
