/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:53:46 by mbui              #+#    #+#             */
/*   Updated: 2021/02/17 15:44:33 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

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

t_star	*lstdel_star(t_star **head)
{
	t_star	*curr;
	t_star	*next;

	curr = *head;
	while (curr != NULL)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*head = NULL;
	return (NULL);
}

void	printlst(t_star *head)
{
	FILE *ID = fopen("debugi.txt", "a");
	int i;

	i = 0;
	while (head->next != NULL)
	{
		i++;
		fprintf(ID, "head->nb=%d\n", head->nb);
		fprintf(ID, "gap.x=%d\ngap.y=%d\ni=%d\n", head->gap.x, head->gap.y, i);
		head = head->next;
	}
	fclose(ID);
}

t_point	*init_pt(t_point *p)
{
	p->x = 0;
	p->y = 0;
	return (p);
}

t_point	*assign_pt(t_point *p, int x, int y)
{
	p->x = x;
	p->y = y;
	return (p);
}

void	place(t_filler *f)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "\nPLACE\n");
	f->res.x = f->map.min.x - f->piece.min.x;
	f->res.y = f->map.min.y - f->piece.min.y;
	ft_printf("%d %d\n", f->res.y, f->res.x);
	fprintf(ID, "minY=%d minX=%d \n", f->piece.min.y, f->piece.min.x);
	fprintf(ID, "==> %d %d <==\n", f->res.y, f->res.x);
	fclose(ID);
}