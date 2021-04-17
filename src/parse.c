/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 18:55:26 by mbui              #+#    #+#             */
/*   Updated: 2021/04/01 17:26:16 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int	get_player(t_filler *f)
{
	char	*line;

	if (!(get_next_line(0, &line)))
		return (-1);
	if (line && !ft_strncmp(line, "$$$ exec p", 10)
		&& (line[10] == '1' || line[10] == '2'))
	{
		if (line[10] == '1')
		{
			f->me.let = 'O';
			f->opp.let = 'X';
		}
		else
		{
			f->me.let = 'X';
			f->opp.let = 'O';
		}
		ft_strdel(&line);
		return (1);
	}
	return (-1);
}

void	find_start(t_filler *f)
{
	int	i;
	int	j;

	j = 0;
	while (j < f->map.h)
	{
		i = 0;
		while (i < f->map.w)
		{
			if (f->map.tab[j][i] == f->me.let)
				assign_pt(&f->me.init, i, j);
			else if (f->map.tab[j][i] == f->opp.let)
				assign_pt(&f->opp.init, i, j);
			i++;
		}
		j++;
	}
}

void	fill_object(t_object *o, unsigned int start)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	o->tab = (char **)ft_memalloc(sizeof(char *) * o->h);
	if (!o->tab)
		return ;
	while (i < o->h && get_next_line(0, &line) > 0)
	{
		o->tab[i] = ft_strsub(line, start, o->w);
		if (!o->tab[i])
		{
			o->tab = free_tab(o->tab, i);
			return ;
		}
		if (line)
			ft_strdel(&line);
		i++;
	}
}

/*
** line 94-95: skips a line from the vm
*/

void	get_map(t_filler *f, char *line)
{
	init_object(&f->map);
	f->map.h = ft_atoi(ft_strchr(line, ' '));
	f->map.w = ft_atoi(ft_strrchr(line, ' '));
	if (!(get_next_line(0, &line)))
		return ;
	if (line)
		ft_strdel(&line);
	fill_object(&f->map, 4);
	if (f->me.init.x == -1 && f->me.init.y == -1
		&& f->opp.init.x == -1 && f->opp.init.y == -1)
		find_start(f);
}

void	get_piece(t_filler *f, char *line)
{
	init_object(&f->piece);
	f->piece.h = ft_atoi(ft_strchr(line, ' '));
	f->piece.w = ft_atoi(ft_strrchr(line, ' '));
	fill_object(&f->piece, 0);
	get_nb_chartab(&f->piece, '*');
}
