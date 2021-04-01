/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 09:52:37 by mbui              #+#    #+#             */
/*   Updated: 2021/04/01 17:26:38 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int check_place(t_filler *f, int j, int i)
{
	int nb;
	int nb2;
	int i2;
	int j2;

	nb = 0;
	nb2 = 0;
	j2 = 0;
	if (j + f->piece.height > f->map.height ||
			i + f->piece.width > f->map.width)
		return (-1);
	while (j2 < f->piece.height)
	{
		i2 = 0;
		while (i2 < f->piece.width)
		{
			if (f->piece.tab[j2][i2] == '*' &&
					f->map.tab[j + j2][i + i2] == '.')
				nb++;
			else if (f->piece.tab[j2][i2] == '*' &&
					f->map.tab[j + j2][i + i2] == f->me.let)
				nb2++;
			i2++;
		}
		j2++;
	}
	if (nb == f->piece.nb - 1 && nb2 == 1)
		return (1);
	return (-1);
}
