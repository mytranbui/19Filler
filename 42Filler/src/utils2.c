/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:11:25 by mbui              #+#    #+#             */
/*   Updated: 2021/04/08 18:18:46 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int	touch_border_right(t_filler *f)
{
	int	i;
	int	j;

	j = f->map.h - 1;
	i = 0;
	while (i < f->map.w)
	{
		if (f->map.tab[j][i] == f->me.let)
			return (1);
		i++;
	}
	return (-1);
}

int	touch_border_left(t_filler *f)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < f->map.w)
	{
		if (f->map.tab[j][i] == f->me.let)
			return (1);
		i++;
	}
	return (-1);
}

int	exit_n_free(t_filler *f)
{
	free_tabs(f);
	exit(1);
}
