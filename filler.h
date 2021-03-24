/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:00:32 by mbui              #+#    #+#             */
/*   Updated: 2020/11/23 10:15:10 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H

#include "libft/libft.h"

//delete, using for fprintf
#include <stdio.h>

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_player
{
	char	let;
	t_point	init;
}				t_player;

typedef struct	s_object
{
	int 	width;
	int 	height;
	char 	**tab;
	t_point	min;
	int		nstar;
}				t_object;

typedef struct	s_filler
{
	t_player	me;
	t_player	opp;
	t_object	piece;
	t_object	map;
	int			score;
	t_point		res;
	t_point		tmp;
}				t_filler;

int		main(void);
int		get_player(t_filler *f);
void	init_object(t_object *o);
void	fill_object(t_object *o, unsigned int start);
void	get_piece(t_filler *f, char *line);
void	get_nbstars(t_object *o);
void	get_map(t_filler *f, char *line);
void	find_start(t_filler *f);

//to delete
void	print_tab(t_object *o);

int		check_sp_pc(t_filler *f, int j, int i);

void	which_algo(t_filler *f);
int		find_possible_sp1(t_filler *f);
int		find_possible_sp1bis(t_filler *f);
int		find_possible_sp2(t_filler *f);
int		find_possible_sp2bis(t_filler *f);

// t_point	*init_pt(t_point *p);
t_point	*assign_pt(t_point *p, int x, int y);
void	place(t_filler *f);
#endif