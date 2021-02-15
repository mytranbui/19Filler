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

//kk fillit ag
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
			if (f->map.tab[j][i] == f->me.let)
			{
				f->me.init.x = i;
				f->me.init.y = j;
			}
			else if (f->map.tab[j][i] == f->opp.let)
			{
				f->opp.init.x = i;
				f->opp.init.y = j;
			}
			i++;
		}
		j++;
	}
	ID = fopen("debugi.txt", "a");
	fprintf(ID, "INITme: x = %d  y = %d\n", f->me.init.x, f->me.init.y);
	fprintf(ID, "INITopp: x = %d  y = %d\n", f->opp.init.x, f->opp.init.y);
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
			if (f->map.tab[j][i] == f->me.let)
			{
				f->map.pt.x = i;
				f->map.pt.y = j;
				return (1);
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


// t_point findgap(t_object *o, int j, int i)
// {
// 	t_point	gap;

// 	gap.x = 0;
// 	gap.y = 0;
// 	while (j < o->height && o->tab[j][i] != '*')
// 	{
// 		i = 0;
// 		while (i < o->width && o->tab[j][i] != '*')
// 		{
// 			gap.x++;
// 			i++;
// 		}
// 		gap.y++;
// 		j++;
// 	}
// 	return (gap);
// }

// t_point	stars(t_object *o)
// {
// 	int	i;
// 	int	j;
// 	t_point gap;

// 	j = 0;
// 	gap.x = 0;
// 	gap.y = 0;
// 	while (j < o->height)
// 	{
// 		i = 0;
// 		while (i < o->width)
// 		{
// 			if (o->tab[j][i] == '*')
// 			{
// 				return(gap = findgap(o, j, i));
// 			}
// 			i++;
// 		}
// 		j++;
// 	}
// 	return (gap);
// }

int	check_place(t_filler *f, int j, int i)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "CHECK_PLACE\n");
	fclose(ID);
	//int i;
	//int j;
	int nb;
	//t_point	gap;

	//i = f->map.pt.x;
	//j = f->map.pt.y;
	nb = f->s->nb;
	ID = fopen("debugi.txt", "a");
	fprintf(ID, "======NB=%d\n", nb);
	fprintf(ID, "enter J=%d & I=%d & %c", j, i,f->map.tab[j][i]);
	fclose(ID);
	//gap = stars(&f->piece);
	while (j < f->map.height)
	{
		while (i < f->map.width)
		{
			ID = fopen("debugi.txt", "a");
			fprintf(ID, "WHILEI\n");
			fclose(ID);
			if (f->map.tab[j][i] == f->me.let)
			{
							ID = fopen("debugi.txt", "a");
	fprintf(ID, "IFO\n");
	fclose(ID);
				f->map.pt.x = i;
				f->map.pt.y = j;
				ID = fopen("debugi.txt", "a");
				fprintf(ID, "[%c %d %d]\n", f->map.tab[j][i], j, i);
				fclose(ID);
				while (f->s->next != NULL)
				{
					i = i + f->s->gap.x;
					j = j + f->s->gap.y;
					ID = fopen("debugi.txt", "a");
					fprintf(ID, "????gap.x=%d\ngap.y=%d\n", f->s->gap.x, f->s->gap.y);
					fprintf(ID, "%dDOT ?%c %d %d\n", nb,f->map.tab[j][i], j, i);
					fclose(ID);
					if (f->map.tab[j][i] == '.')
					{
						nb--;
						ID = fopen("debugi.txt", "a");
						fprintf(ID, "------ifnb=%d\n", nb);
						fclose(ID);
					}
					if (f->map.tab[j][i] != '.' && i == f->map.width - 1) //&& (j + 1) < f->map.height)
					{
						ID = fopen("debugi.txt", "a");
						fprintf(ID,"recu1\n");
						fclose(ID);
						return (check_place(f, j + 1, i));
					}
					else if (f->map.tab[j][i] != '.')// && i < f->map.width)
					{
						ID = fopen("debugi.txt", "a");
						fprintf(ID,"recu2\n");
						fclose(ID);
						return (check_place(f, j, i + 1));
					}
					//else
					//	return (-1);
					ID = fopen("debugi.txt", "a");
					fprintf(ID, "_______whilenb=%d\n", nb);
					fclose(ID);
					f->s = f->s->next;
				}
				if (nb == 0)
				{
					ID = fopen("debugi.txt", "a");
					fprintf(ID,"STOPOK\n");
					fclose(ID);
					return (1);
				}
				// while ((f->map.tab[j + gap.y][i + gap.x] == '.') && (f->piece.nstar > 0))
				// //while (f->map.tab[j][i] == '.')
				// {
				// 	f->piece.nstar--;
				// }
				// if (f->piece.nstar != 0)
				// 	return (check_place(f));
				// else
				// 	return (1);
			}
			i++;
		}
		i=0;
		j++;
	}
	ID = fopen("debugi.txt", "a");
	fprintf(ID,"STOPNO nb=%d \n",nb);
	fprintf(ID, "CHECK_PLACE--END\n");
	fclose(ID);
	return (-1);
}

void place(t_filler *f)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "\nPLACE\n");
	f->res.x = f->map.pt.x - f->piece.pt.x;
	f->res.y = f->map.pt.y - f->piece.pt.y;
	ft_printf("%d %d\n", f->res.y, f->res.x);
	fprintf(ID, "==> %d %d <==\n", f->res.y, f->res.x);
	fclose(ID);
}

int main(void)
{
	t_filler f;
	char *line;
	int	i;
	int k;
	int lol;

	k = 0;
	lol = 0;
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
			ID = fopen("debugi.txt", "a");
			fprintf(ID, "PIECE%d\n", k);
			fclose(ID);
			k++;
			get_piece(&f, line);
			if ((lol = (check_place(&f, f.me.init.y, f.me.init.x))))
			{
				ID = fopen("debugi.txt", "a");
			fprintf(ID, "lol%d\n", lol);
			fclose(ID);
				place(&f);
			}
			//find_place(&f);
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