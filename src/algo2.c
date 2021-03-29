/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 09:52:37 by mbui              #+#    #+#             */
/*   Updated: 2021/03/29 09:52:42 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int check_place(t_filler *f, int j, int i)
{
	FILE *ID = fopen("debugi.txt", "a");
	int nb;
	int nb2;
	int i2;
	int j2;

	fprintf(ID, "CHECK_SP_PC\n");
	fprintf(ID, "TRY j=[%d] i=[%d]\n" ,j ,i);
	fclose(ID);
	nb = 0;
	nb2 = 0;
	j2 = 0;
	if (j + f->piece.height > f->map.height || i + f->piece.width > f->map.width)
	{
		ID = fopen("debugi.txt", "a");
		fprintf(ID, "OUT OF MAP\n");
		fclose(ID);
		return (-1);
	}
	while (j2 < f->piece.height)
	{
		i2 = 0;
		while (i2 < f->piece.width)
		{
			if (f->piece.tab[j2][i2] == '*' &&
					f->map.tab[j + j2][i + i2] == '.')
				nb++;
			if (f->piece.tab[j2][i2] == '*' &&
					f->map.tab[j + j2][i + i2] == f->me.let)
				nb2++;
			i2++;
		}
		j2++;
	}
	ID = fopen("debugi.txt", "a");
	fprintf(ID, "nb=%d =? nb=%d & nb2=%d\n",f->piece.nb, nb, nb2);
	fclose(ID);
	if (nb == f->piece.nb - 1 && nb2 == 1)
	{
		ID = fopen("debugi.txt", "a");
		fprintf(ID, "check_place OK\n");
		fclose(ID);
		return (1);
	}
	ID = fopen("debugi.txt", "a");
	fprintf(ID, "check_place NO nb=%d\n",nb);
	fclose(ID);
	return (-1);
}
