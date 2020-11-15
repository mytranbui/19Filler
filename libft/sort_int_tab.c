/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:05:08 by mbui              #+#    #+#             */
/*   Updated: 2019/09/30 18:05:40 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (i++ < size)
	{
		j = -1;
		while (++j < size - 1)
			if (tab[j] > tab[j + 1])
				ft_swap(&tab[j], &tab[j + 1]);
	}
}
