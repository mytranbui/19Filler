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
