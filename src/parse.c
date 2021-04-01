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

int		get_player(t_filler *f)
{
	char	*line;

	if (!(get_next_line(0, &line)))
		return (-1);
	if (line && !ft_strncmp(line, "$$$ exec p", 10) &&
			(line[10] == '1' || line[10] == '2'))
	{
		f->me.let = (line[10] == '1') ? 'O' : 'X';
		f->opp.let = (line[10] == '1') ? 'X' : 'O';
		ft_strdel(&line);
		return (1);
	}
	return (-1);
}

void	find_start(t_filler *f)
{
	int i;
	int j;

	j = 0;
	while (j < f->map.height)
	{
		i = 0;
		while (i < f->map.width)
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
	FILE	*ID;
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	if (!(o->tab = (char **)ft_memalloc(sizeof(char *) * o->height)))
		return ;
	while (i < o->height && get_next_line(0, &line) > 0)
	{
		if (!(o->tab[i] = ft_strsub(line, start, o->width)))
		{
			o->tab = free_tab(o->tab, i);
			return ;
		}
		ID = fopen("debugi.txt", "a");
		fprintf(ID, "%03d %s\n", i, o->tab[i]);
		fclose(ID);
		if (line)
			ft_strdel(&line);
		i++;
	}
}

/*
 ** line 87-88: skips a line from the vm
 */

void	get_map(t_filler *f, char *line)
{
	init_object(&f->map);
	f->map.height = ft_atoi(ft_strchr(line, ' '));
	f->map.width = ft_atoi(ft_strrchr(line, ' '));
	if (!(get_next_line(0, &line)))
		return ;
	if (line)
		ft_strdel(&line);
	fill_object(&f->map, 4);
	if (f->me.init.x == -1 && f->me.init.y == -1 &&
			f->opp.init.x == -1 && f->opp.init.y == -1)
		find_start(f);
}

void	get_piece(t_filler *f, char *line)
{
	init_object(&f->piece);
	f->piece.height = ft_atoi(ft_strchr(line, ' '));
	f->piece.width = ft_atoi(ft_strrchr(line, ' '));
	fill_object(&f->piece, 0);
	get_nb_chartab(&f->piece, '*');
}
