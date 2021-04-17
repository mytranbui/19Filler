/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:53:46 by mbui              #+#    #+#             */
/*   Updated: 2021/03/29 10:23:04 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

t_point	*assign_pt(t_point *p, int x, int y)
{
	p->x = x;
	p->y = y;
	return (p);
}

void	init_object(t_object *o)
{
	o->tab = NULL;
	o->h = 0;
	o->w = 0;
	o->nb = 0;
}

void	get_nb_chartab(t_object *o, char c)
{
	int	i;
	int	j;

	j = 0;
	while (j < o->h)
	{
		i = 0;
		while (i < o->w)
		{
			if (o->tab[j][i] == c)
				o->nb++;
			i++;
		}
		j++;
	}
}

void	free_tabs(t_filler *f)
{
	f->map.tab = free_tab(f->map.tab, f->map.h - 1);
	f->piece.tab = free_tab(f->piece.tab, f->piece.h - 1);
}

void	place(t_filler *f, int j, int i)
{
	f->nb_piece++;
	ft_printf("%d %d\n", j, i);
	free_tabs(f);
}
