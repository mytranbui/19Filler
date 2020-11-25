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
# define FILLER_H

# include "libft/libft.h"
# include <stdio.h>
# define MAX_READ 545

typedef struct	s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct	s_piece
{
	int	width;
	int	height;
}		t_piece;

/*typedef struct	s_map;
{
}		t_map;
*/

typedef struct	s_filler
{
	//char	**map;
	//char	**piece;
	char	me;
	char	opp;
	t_piece	piece;
	t_piece	map;
	int		score;
}				t_filler;


int		main(void);
#endif
