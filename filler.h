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
# define MAX_READ 545

typedef struct	s_coord
{
	int	x;
	int	y;
}		t_coord;

/*typedef struct	s_tetro
{

}		t_tetro;

typedef struct	s_map;
{
}		t_map;
*/

typedef struct	s_filler
{
	int	player;
	int	cpu;
}				t_filler;


int	main(void);
#endif
