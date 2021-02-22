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
		//fprintf(ID, "head->nb=%d\n", head->nb);
		//fprintf(ID, "gap.x=%d\ngap.y=%d\ni=%d\n", head->gap.x, head->gap.y, i);
		head = head->next;
	}
	fclose(ID);
}