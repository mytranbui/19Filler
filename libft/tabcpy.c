/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:13:37 by mbui              #+#    #+#             */
/*   Updated: 2019/10/11 11:13:57 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**tabcpy(char **map, size_t size)
{
	char	**tab;
	size_t	j;
	size_t	i;

	j = -1;
	if (!(tab = (char**)ft_memalloc(sizeof(char*) * size + 1)))
		return (NULL);
	while (++j < size)
	{
		if (!(tab[j] = (char*)ft_strnew(sizeof(char) * size + 1)))
			return (NULL);
		i = -1;
		while (++i < size)
			tab[j][i] = map[j][i];
	}
	tab[j] = 0;
	return (tab);
}
