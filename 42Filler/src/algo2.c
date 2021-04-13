/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 09:52:37 by mbui              #+#    #+#             */
/*   Updated: 2021/04/08 18:25:17 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

static int	check_place2(t_filler *f, int nb, int nb2)
{
	if (nb == f->piece.nb - 1 && nb2 == 1)
		return (1);
	return (-1);
}

int	check_place(t_filler *f, int j, int i)
{
	int		nb;
	int		nb2;
	t_point	piece_ij;

	nb = 0;
	nb2 = 0;
	piece_ij.y = 0;
	if (j + f->piece.h > f->map.h || i + f->piece.w > f->map.w)
		return (-1);
	while (piece_ij.y < f->piece.h)
	{
		piece_ij.x = 0;
		while (piece_ij.x < f->piece.w)
		{
			if (f->piece.tab[piece_ij.y][piece_ij.x] == '*'
					&& f->map.tab[j + piece_ij.y][i + piece_ij.x] == '.')
				nb++;
			else if (f->piece.tab[piece_ij.y][piece_ij.x] == '*'
					&& f->map.tab[j + piece_ij.y][i + piece_ij.x] == f->me.let)
				nb2++;
			piece_ij.x++;
		}
		piece_ij.y++;
	}
	return (check_place2(f, nb, nb2));
}

static void	which_algo2(t_filler *f)
{
	if (f->me.init.x < f->opp.init.x)
	{
		if (possible_sp_so(f) == -1)
			if (possible_sp_ne(f) == -1)
				if (possible_sp_last(f) == -1)
					exit_n_free(f);
	}
	else if (f->me.init.x >= f->opp.init.x)
	{
		if (possible_sp_no(f) == -1)
			if (possible_sp_se(f) == -1)
				if (possible_sp_last(f) == -1)
					exit_n_free(f);
	}
}

void	which_algo(t_filler *f)
{
	if (f->me.init.y < f->opp.init.y)
	{
		if (f->me.init.x < f->opp.init.x)
		{
			if (possible_sp_se(f) == -1)
				if (possible_sp_no(f) == -1)
					if (possible_sp_last(f) == -1)
						exit_n_free(f);
		}
		else if (f->me.init.x >= f->opp.init.x)
		{
			if (possible_sp_ne(f) == -1)
				if (possible_sp_so(f) == -1)
					if (possible_sp_last(f) == -1)
						exit_n_free(f);
		}
	}
	else if (f->me.init.y >= f->opp.init.y)
		which_algo2(f);
}
