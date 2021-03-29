/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 18:55:26 by mbui              #+#    #+#             */
/*   Updated: 2021/03/09 14:02:04 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int get_player(t_filler *f)
{
	FILE *ID = fopen("debugi.txt", "a");
	fclose(ID);
	char *line;

	assign_pt(&f->me.init, -1, -1);
	assign_pt(&f->opp.init, -1, -1);
	get_next_line(0, &line);
	if (line && !ft_strncmp(line, "$$$ exec p", 10) &&
			(line[10] == '1' || line[10] == '2'))
	{
		f->me.let = (line[10] == '1') ? 'O' : 'X';
		f->opp.let = (line[10] == '1') ? 'X' : 'O';
		ft_strdel(&line);
		ID = fopen("debugi.txt", "a");
		fprintf(ID, "ME=%c\nOP=%c\n", f->me.let, f->opp.let);
		fclose(ID);
		return (1);
	}
	return (-1);
}

void fill_object(t_object *o, unsigned int start)
{
	int i;
	char *line;

	i = 0;
	line = NULL;
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "~fill_object~\n");
	fclose(ID);
	//if (o->tab)
	//free_tab(o->tab, o->height-1);
	if (!(o->tab = (char **)ft_memalloc(sizeof(char *) * o->height)))
		return;
	while (i < o->height && get_next_line(0, &line) > 0)
	{
		if (!(o->tab[i] = ft_strsub(line, start, o->width)))
			return;
		// ID = fopen("debugi.txt", "a");
		// fprintf(ID, "%03d %s\n", i, o->tab[i]);
		// fclose(ID);
		if (line)
		ft_strdel(&line);
		i++;
	}
	ID = fopen("debugi.txt", "a");
	fprintf(ID, "~fill_object~END\n");
	fclose(ID);
	//return (object);
}

void	find_start(t_filler *f)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "~find_start~\n");
	fclose(ID);
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
	ID = fopen("debugi.txt", "a");
	fprintf(ID, "INITme: x = %d  y = %d\n", f->me.init.x, f->me.init.y);
	fprintf(ID, "INITop: x = %d  y = %d\n", f->opp.init.x, f->opp.init.y);
	fclose(ID);
}

void get_map(t_filler *f, char *line)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "~get_map~\n");
	fclose(ID);
	if (line && !ft_strncmp(line, "Plateau ", 8))
	{
		ID = fopen("debugi.txt", "a");
	fprintf(ID, "KKK\n");
	fclose(ID);
		//init_object(&f->map); working fine without it
		f->map.height = ft_atoi(ft_strchr(line, ' '));
		f->map.width = ft_atoi(ft_strrchr(line, ' '));
		ft_strdel(&line);
		get_next_line(0, &line); // skip line lol
		ft_strdel(&line);
		// if (f->map.tab)
		// 	free_tab(f->map.tab, f->map.height - 1);
		fill_object(&f->map, 4);
		if (f->me.init.x == -1 && f->me.init.y == -1 && f->opp.init.x == -1 && f->opp.init.y == -1)
			find_start(f);
		ID = fopen("debugi.txt", "a");
		fprintf(ID, "M.height =	%d\n", f->map.height);
		fprintf(ID, "M.width  =	%d\n", f->map.width);
		fclose(ID);
		//return (1);
	}
	//	return (-1);
	ID = fopen("debugi.txt", "a");
	fprintf(ID, "~get_map~END\n");
	fclose(ID);
}

void get_piece(t_filler *f, char *line)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "~get_piece~\n");
	fclose(ID);
	if (line && !ft_strncmp(line, "Piece ", 6))
	{
		//init_object(&f->piece); working fine without it
		// fprintf(ID, "~get_piece~\n");
		// fclose(ID);
		f->piece.height = ft_atoi(ft_strchr(line, ' '));
		f->piece.width = ft_atoi(ft_strrchr(line, ' '));
		fill_object(&f->piece, 0);
		ID = fopen("debugi.txt", "a");
		fprintf(ID, "P.height =	%d\n", f->piece.height);
		fprintf(ID, "P.width  =	%d\n", f->piece.width);
		fclose(ID);
		f->piece.nb = 0;
		// f->s = find_stars(&f->piece);
		get_nbstars(&f->piece);
		//printlst(f->s);
	}
	ID = fopen("debugi.txt", "a");
	fprintf(ID, "~get_piece~END\n");
	fclose(ID);
	//	return (-1);
}
