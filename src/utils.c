/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:53:46 by mbui              #+#    #+#             */
/*   Updated: 2021/03/27 16:26:57 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

//to delete
void print_tab(t_object *o)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "~print_tab~\n");
	fclose(ID);
	int j;
	j = 0;
	while (j < o->height)
	{
		ID = fopen("debugi.txt", "a");
		fprintf(ID, "%03d %s\n", j, o->tab[j]);
		fclose(ID);
		j++;
	}
	ID = fopen("debugi.txt", "a");
	fprintf(ID, "~print_tab~END\n");
	fclose(ID);
}

// t_point	*init_pt(t_point *p)
// {
// 	p->x = 0;
// 	p->y = 0;
// 	return (p);
// }

t_point	*assign_pt(t_point *p, int x, int y)
{
	p->x = x;
	p->y = y;
	return (p);
}

//no use rn
void init_object(t_object *o)
{
	//if (o->tab)
	//	free_tab(o->tab, o->height - 1);
	o->tab = NULL;
	o->height = 0;
	o->width = 0;
}

void	get_nbstars(t_object *o)
{
	// FILE *ID = fopen("debugi.txt", "a");
	int i;
	int j;

	j = 0;
	while (j < o->height)
	{
		i = 0;
		while (i < o->width)
		{
			if (o->tab[j][i] == '*')
				o->nstar++;
			i++;
		}
		j++;
	}
	// ID = fopen("debugi.txt", "a");
	// fprintf(ID, "nstar=%d\n", o->nstar);
	// fprintf(ID, "~find_star~END\n");
	// fclose(ID);
}

void	place(t_filler *f)
{
	//static int i = 0;
	FILE *ID = fopen("debugi.txt", "a");
	ft_printf("%d %d\n", f->res.y, f->res.x);
	fprintf(ID, "P L A C E ==> %d %d <==\n", f->res.y, f->res.x);
	fclose(ID);
	f->map.tab = free_tab(f->map.tab, f->map.height - 1);
	f->piece.tab = free_tab(f->piece.tab, f->piece.height - 1);
//	i++;
//	if (i == 2)
//		exit(1);
}
