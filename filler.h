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

//delete
#include <stdio.h>

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_player
{
	char	c;
	t_point	pt;
}				t_player;

typedef struct	s_object
{
	int 	width;
	int 	height;
	char 	**tab;
	t_point	pt;
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

int main(void);
#endif
