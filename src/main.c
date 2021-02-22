/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:22:10 by mbui              #+#    #+#             */
/*   Updated: 2021/02/17 15:44:00 by mbui             ###   ########.fr       */
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
// int		find_space(t_filler *f)
// {
// 	int	l;
// 	int x;
// 	int y;

// 	if (f->map.min.y != 0)
// 		f->map.min.y--;
// 	if (f->map.min.x != 0)
// 		f->map.min.x--;
// 	while (++f->map.min.y < f->map.height)
// 	{
// 		while (++f->map.min.x < f->map.width)
// 		{
// 			l = 0;
// 			while (l < f->piece.nstar && f->map.tab[f->map.min.y][f->map.min.x] == '.')
// 			{
// 				x = f->map.min.x + f->piece.tab[l][0] - f->piece.tab[0][0];
// 				y = f->map.min.y + f->piece.tab[l][1] - f->piece.tab[0][1];
// 				l++;
// 				//l = (y > f-> - 1 || x < 0 || f->map.tab[y][x] != '.') ? 5 : l + 1;
// 				if (l == f->piece.nstar)
// 					return (1);
// 			}
// 		}
// 		f->map.min.x = -1;
// 	}
// 	return (-1);
// }

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
	//if (f->me.init.x > f->opp.init.y)
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
				f->map.min.x = i;
				f->map.min.y = j;
				return (1);
			}
			// else if (f->map.tab[j][i] == f->opp.c)
			// {
			// 	f->map.min.x = i;
			// 	f->map.min.y = j;
			// }
			i++;
		}
		j++;
	}
	return(-1);
}

int checkcheck(t_filler *f, t_star **head, int j, int i)
{
	FILE *ID = fopen("debugi.txt", "a");
	t_star	*curr;
	int nb;

	curr = *head;
	nb = curr->nb;
	fprintf(ID, "CHECKCHECK BF nb=%d\n",nb);
	fclose(ID);
	if ((curr->gap.y == 0 && curr->gap.x == 0) || f->map.tab[j][i] == 'O')
	{
		nb--;
		ID = fopen("debugi.txt", "a");
		fprintf(ID, "CHECKCHECK 00 nb=%d\n", nb);
		fclose(ID);
		curr = curr->next;
	}
	while (f->map.tab[j + curr->gap.y][i + curr->gap.x] == '.' && curr->next != NULL)
	{
		nb--;
		if (f->piece.min.y != 0 && f->piece.min.x != 0 && f->map.tab[j][i] == 'O')
		{
			curr->gap.x = 0;
			curr->gap.y = 0;
		}
		i = i + curr->gap.x;
		j = j + curr->gap.y;
		ID = fopen("debugi.txt", "a");
		fprintf(ID, "GAP.y=%d GAP.x=%d\n", curr->gap.y, curr->gap.x);
		fprintf(ID, "[j=%d][i=%d][%c] nb=%d\n",j,i, f->map.tab[j][i],nb);
		fclose(ID);
		curr = curr->next;
	}
	if (nb == 0)
	{
		ID = fopen("debugi.txt", "a");
		fprintf(ID, "CHECKCHECK OK\n");
		fclose(ID);
		return (1);
	}
	else
	{
		ID = fopen("debugi.txt", "a");
		fprintf(ID, "CHECKCHECK NO nb=%d\n",nb);
		fclose(ID);
		return (-1);
	}
}

int	check_place(t_filler *f, int j, int i)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "CHECK_PLACE\n");
	fclose(ID);
	ID = fopen("debugi.txt", "a");
	fprintf(ID, "enter J=%d & I=%d & %c\n", j, i,f->map.tab[j][i]);
	fclose(ID);
	int kk;

	kk = 0; 
	while (j < f->map.height)
	{
		while (i < f->map.width)
		{
			if (f->map.tab[j][i] == f->me.let)
			{
				f->map.min.x = i;
				f->map.min.y = j;
				ID = fopen("debugi.txt", "a");
	fprintf(ID, "map.minY=%d map.minX=%d\n", f->map.min.y, f->map.min.x);
	fclose(ID);
				kk = checkcheck(f, &f->s, j, i);
				if (kk==1)
					return (1);
				else
				{
ID = fopen("debugi.txt", "a");
					fprintf(ID, "-----RECUR\n");
					fclose(ID);
					return (check_place(f, j, i + 1));
				}
			}
			i++;
		}
		i = 0;
		j++;
	}
	if (i >= f->map.width && j < f->map.height)
	{
		ID = fopen("debugi.txt", "a");
					fprintf(ID, "-----RECURJJJ\n");
					fclose(ID);
		return (check_place(f, j + 1, 0));
	}
	ID = fopen("debugi.txt", "a");
	fprintf(ID, "CHECK_PLACE--END\n");
	fclose(ID);
	return (-1);
}

void place(t_filler *f)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "\nPLACE\n");
	f->res.x = f->map.min.x - f->piece.min.x;
	f->res.y = f->map.min.y - f->piece.min.y;
	ft_printf("%d %d\n", f->res.y, f->res.x);
	fprintf(ID, "minY=%d minX=%d \n", f->piece.min.y, f->piece.min.x);
	fprintf(ID, "==> %d %d <==\n", f->res.y, f->res.x);
	fclose(ID);
}
void place2(t_filler *f)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "\nPLACE2\n");
	f->res.x = f->map.min.x; //- f->piece.min.x;
	f->res.y = f->map.min.y;// - f->piece.min.y;
	ft_printf("%d %d\n", f->res.y, f->res.x);
	fprintf(ID, "minY=%d minX=%d \n", f->piece.min.y, f->piece.min.x);
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
				if (lol == 1)
				{
					print_tab(&f.piece);
					place(&f);
				}
				else if (lol != 1)
				{
					ID = fopen("debugi.txt", "a");
					fprintf(ID, "lolno%d\n", lol);
					fclose(ID);
					print_tab(&f.piece);
					place(&f);
				}
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
