/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:00:32 by mbui              #+#    #+#             */
/*   Updated: 2021/04/02 14:49:56 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct s_player
{
	char	let;
	t_point	init;
}				t_player;

/*
** w = width & h = height
*/

typedef struct s_object
{
	int		w;
	int		h;
	int		nb;
	char	**tab;
}				t_object;

typedef struct s_filler
{
	t_player	me;
	t_player	opp;
	t_object	piece;
	t_object	map;
	int			nb_piece;
}				t_filler;

int				main(void);

/*
** parse.c
*/
int				get_player(t_filler *f);
void			get_map(t_filler *f, char *line);
void			get_piece(t_filler *f, char *line);
void			fill_object(t_object *o, unsigned int start);
void			find_start(t_filler *f);

/*
** algo.c & algo2.c
*/
void			which_algo(t_filler *f);
int				check_place(t_filler *f, int j, int i);
int				possible_sp_no(t_filler *f);
int				possible_sp_ne(t_filler *f);
int				possible_sp_se(t_filler *f);
int				possible_sp_so(t_filler *f);
int				possible_sp_last(t_filler *f);

/*
** utils.c & utils2.c
*/
void			init_object(t_object *o);
t_point			*assign_pt(t_point *p, int x, int y);
void			get_nb_chartab(t_object *o, char c);
int				touch_border_right(t_filler *f);
int				touch_border_left(t_filler *f);
void			free_tabs(t_filler *f);
void			place(t_filler *f, int j, int i);
int				exit_n_free(t_filler *f);
#endif
