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

int		find_space(t_filler *f)
{
	int	l;
	int x;
	int y;

	if (f->map.pt.y != 0)
		f->map.pt.y--;
	if (f->map.pt.x != 0)
		f->map.pt.x--;
	while (++f->map.pt.y < f->map.height)
	{
		while (++f->map.pt.x < f->map.width)
		{
			l = 0;
			while (l < f->piece.nstar && f->map.tab[f->map.pt.y][f->map.pt.x] == '.')
			{
				x = f->map.pt.x + f->piece.tab[l][0] - f->piece.tab[0][0];
				y = f->map.pt.y + f->piece.tab[l][1] - f->piece.tab[0][1];
				l++;
				//l = (y > f-> - 1 || x < 0 || f->map.tab[y][x] != '.') ? 5 : l + 1;
				if (l == f->piece.nstar)
					return (1);
			}
		}
		f->map.pt.x = -1;
	}
	return (-1);
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
	ID = fopen("debugi.txt", "a");
	fprintf(ID, "startme: x = %d  y = %d\n", f->me.pt.x, f->me.pt.y);
	fprintf(ID, "startopp: x = %d  y = %d\n", f->opp.pt.x, f->opp.pt.y);
	fclose(ID);
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
				f->map.pt.x = i;
				f->map.pt.y = j;
			}
			// else if (f->map.tab[j][i] == f->opp.c)
			// {
			// 	f->map.pt.x = i;
			// 	f->map.pt.y = j;
			// }
			i++;
		}
		j++;
	}
	return(-1);
}

void place(t_filler *f)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "\nPLACE\n");
	f->res.x = f->map.pt.x - f->piece.pt.x;
	f->res.y = f->map.pt.y - f->piece.pt.y;
	ft_printf("%d %d\n", f->res.y, f->res.x);
	fprintf(ID, "%d %d\n", f->res.y, f->res.x);
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
	if (!(get_player(&f)))
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