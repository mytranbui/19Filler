/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:22:10 by mbui              #+#    #+#             */
/*   Updated: 2020/12/12 17:20:22 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int debug(int i) //, char *line)
{
	char *line;
	FILE *ID;

	ID = fopen("debugi.txt", "a");
	get_next_line(0, &line);
	fprintf(ID, "line[%d]=%s\n", i, line);
	if (!line)
	{
		fprintf(ID, "ENDNULL");
		fclose(ID);
		return (-1);
	}
	if (line && !ft_strncmp(line, "== X fin: ", 10))
	{
		fprintf(ID, "ENDOK");
		fclose(ID);
		return (-1);
	}
	ft_strdel(&line);
	fclose(ID);
	return (1);
}

int get_player(t_filler filler)
{
	FILE *ID = fopen("debugi.txt", "a");
	char *line;

	get_next_line(0, &line);
	fprintf(ID, "~~get_player~~\n");
	if (line && !ft_strncmp(line, "$$$ exec p", 10) &&
		(line[10] == '1' || line[10] == '2'))
	{
		filler.me.c = (line[10] == '1') ? 'O' : 'X';
		filler.opp.c = (line[10] == '1') ? 'X' : 'O';
		ft_strdel(&line);
		fprintf(ID, "ME=%c\n", filler.me.c);
		fprintf(ID, "OP=%c\n", filler.opp.c);
		fclose(ID);
		return (1);
	}
	fclose(ID);
	return (-1);
}

int		find_space(t_filler *f)
{
	int	l;
	int x;
	int y;

	if (f->res.y != 0)
		f->res.y--;
	if (f->res.x != 0)
		f->res.x--;
	while (++f->res.y < f->map.height)
	{
		while (++f->res.x < f->map.width)
		{
			l = 0;
			while (l < f->piece.nstar && f->map.tab[f->res.y][f->res.x] == '.')
			{
				x = f->res.x + f->piece.tab[l][0] - f->piece.tab[0][0];
				y = f->res.y + f->piece.tab[l][1] - f->piece.tab[0][1];
				l++;
				//l = (y > f-> - 1 || x < 0 || f->map.tab[y][x] != '.') ? 5 : l + 1;
				if (l == f->piece.nstar)
					return (1);
			}
		}
		f->res.x = -1;
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
			if (f->map.tab[j][i] == f->me.c)
			{
				f->me.pt.x = i;
				f->me.pt.y = j;
			}
			else if (f->map.tab[j][i] == f->opp.c)
			{
				f->opp.pt.x = i;
				f->opp.pt.y = j;
			}
			i++;
		}
		j++;
	}
}

int find_place(t_filler *f)
{
	int i;
	int j;

	j = 0;
	while (j < f->map.height)
	{
		i = 0;
		while (i < f->map.width)
		{
			if (f->map.tab[j][i] == f->me.c)
			{
				f->res.x = i;
				f->res.y = j;
			}
			// else if (f->map.tab[j][i] == f->opp.c)
			// {
			// 	f->res.x = i;
			// 	f->res.y = j;
			// }
			i++;
		}
		j++;
	}
	return(-1);
}

void init_object(t_object *object)
{
	//if (object->tab)
	//	free_tab(object->tab, object->height - 1);
	object->tab = NULL;
	object->height = 0;
	object->width = 0;
	object->pt.x = -1;
	object->pt.y = -1;
}

void fill_object(t_object *object, unsigned int start)
{
	int i;
	char *line;

	i = 0;
	line = NULL;
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "~fill_object~\n");
	fclose(ID);
	//if (object->tab)
	//free_tab(object->tab, object->height-1);
	if (!(object->tab = (char **)ft_memalloc(sizeof(char *) * object->height)))
		return;
	while (i < object->height && get_next_line(0, &line) > 0)
	{
		if (!(object->tab[i] = ft_strsub(line, start, object->width)))
			return;
		ID = fopen("debugi.txt", "a");
		fprintf(ID, "%03d %s\n", i, object->tab[i]);
		fclose(ID);
		ft_strdel(&line);
		i++;
	}
	ID = fopen("debugi.txt", "a");
	fprintf(ID, "~fill_object~END\n");
	fclose(ID);
	//return (object);
}

void get_map(t_filler *filler, char *line)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "~get_map~\n");
	fclose(ID);
	if (line && !ft_strncmp(line, "Plateau ", 8))
	{
		//init_object(&filler->map);
		ID = fopen("debugi.txt", "a");
		filler->map.height = ft_atoi(ft_strchr(line, ' '));
		filler->map.width = ft_atoi(ft_strrchr(line, ' '));
		ft_strdel(&line);
		get_next_line(0, &line); // skip line lol
		ft_strdel(&line);
		// if (filler->map.tab)
		// 	free_tab(filler->map.tab, filler->map.height - 1);
		fill_object(&filler->map, 4);
		fprintf(ID, "M.height =	%d\n", filler->map.height);
		fprintf(ID, "M.width  =	%d\n", filler->map.width);
		fclose(ID);
		//return (1);
	}
	//	return (-1);
}

void find_stars(t_object *object)
{
	FILE *ID = fopen("debugi.txt", "a");
	int i;
	int j;

	object->nstar = 0;
	object->pt.x = object->width;
	object->pt.y = object->height;
	j = 0;
	while (j < object->height)
	{
		i = 0;
		while (i < object->width)
		{
			if (object->tab[j][i] == '*')
			{
				object->nstar++;
				if (i < object->pt.x)
					object->pt.x = i;
				if (j < object->pt.y)
					object->pt.y = j;
			}
			i++;
		}
		j++;
	}
	ID = fopen("debugi.txt", "a");
	fprintf(ID, "STARNB=%d\n", object->nstar);
	fclose(ID);
}

void get_piece(t_filler *filler, char *line)
{
	FILE *ID = fopen("debugi.txt", "a");
	if (line && !ft_strncmp(line, "Piece ", 6))
	{
		//init_object(&filler->piece);
		fprintf(ID, "~get_piece~\n");
		fclose(ID);
		filler->piece.height = ft_atoi(ft_strchr(line, ' '));
		filler->piece.width = ft_atoi(ft_strrchr(line, ' '));
		fill_object(&filler->piece, 0);
		ID = fopen("debugi.txt", "a");
		fprintf(ID, "P.height =	%d\n", filler->piece.height);
		fprintf(ID, "P.width  =	%d\n", filler->piece.width);
		fclose(ID);
		find_stars(&filler->piece);
		ID = fopen("debugi.txt", "a");
		fprintf(ID, "STAR.x=%d\n", filler->piece.min.x);
		fprintf(ID, "STAR.y=%d\n", filler->piece.min.y);
		fclose(ID);
	}
	ID = fopen("debugi.txt", "a");
	fprintf(ID, "~get_piece~END\n");
	fclose(ID);
	//	return (-1);
}

void place(t_filler *filler)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "\nPLACE\n");
	filler->res.x = filler->map.min.x - filler->piece.min.x;
	filler->res.y = filler->map.min.y - filler->piece.min.y;
	ft_printf("%d %d\n", filler->res.y, filler->res.x);
	fprintf(ID, "%d %d\n", filler->res.y, filler->res.x);
	fclose(ID);
}

int main(void)
{
	t_filler f;
	char *line;
	int	i;

	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "\n\n----------MAIN START----------\n");
	fclose(ID);
	line = NULL;
	i = 0;
	ft_bzero(&f, sizeof(t_filler));
	if (!(get_player(f)))
		return (-1);
	while (get_next_line(0, &line) > 0)
	{
		ID = fopen("debugi.txt", "a");
		fprintf(ID, "MAIN WHILE START line [%s]\n", line);
		fclose(ID);
		if (line && !ft_strncmp(line, "Plateau ", 8))
		{
			get_map(&f, line);
		}
		else if (line && !ft_strncmp(line, "Piece ", 6))
		{
			get_piece(&f, line);
			find_place(&f);
			place(&f);
		}
		ID = fopen("debugi.txt", "a");
		fprintf(ID, "MAIN WHILE END line%d [%s]\n", i, line);
		fclose(ID);
		//if (line)
		//ft_strdel(&line);
		i++;
	}
	/*while ((ret = debug(i)) == 1)
	{
		fprintf(ID,"line[%d]=%s\n",i, line);
		ft_strdel(&line);
		i++;
	}*/
	return (0);
}