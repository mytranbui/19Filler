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

//to delete
void	print_tab(t_object *o)
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

t_point	*assign_pt(t_point *p, int x, int y)
{
	p->x = x;
	p->y = y;
	return (p);
}

void	init_object(t_object *o)
{
	// if (o->tab) //works fine without it
	// 	free_tab(o->tab, o->height - 1);
	o->tab = NULL;
	o->height = 0;
	o->width = 0;
	o->nb = 0;
}

void	get_nb_chartab(t_object *o, char c)
{
	int i;
	int j;

	j = 0;
	while (j < o->height)
	{
		i = 0;
		while (i < o->width)
		{
			if (o->tab[j][i] == c)
				o->nb++;
			i++;
		}
		j++;
	}
}

void	place_and_free(t_filler *f, int j, int i)
{
	// static int	o = 0;
	FILE		*ID = fopen("debugi.txt", "a");

	fprintf(ID, "P L A C E ==> %d %d <==\n", j, i);
	fclose(ID);
	ft_printf("%d %d\n", j, i);
	f->map.tab = free_tab(f->map.tab, f->map.height - 1);
	f->piece.tab = free_tab(f->piece.tab, f->piece.height - 1);
	// o++;
	// if (o == 5)
	// 	exit(1);
}
