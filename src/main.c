/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:22:10 by mbui              #+#    #+#             */
/*   Updated: 2021/03/11 16:24:24 by mbui             ###   ########.fr       */
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

int check_sp_pc(t_filler *f, t_star **head, int j, int i)
{
	FILE *ID = fopen("debugi.txt", "a");
	t_star	*curr;
	int nb;

	curr = *head;
	nb = curr->nb - 1;
	fprintf(ID, "CHECK_SP_PC BF nb=%d\n",nb);
	fprintf(ID, "TRY j=[%d] i=[%d]\n" ,j ,i);
	fclose(ID);
	if (curr->gap.y != 0 || curr->gap.x != 0)
	{
		ID = fopen("debugi.txt", "a");
		fprintf(ID, "SKIP\n");
		fclose(ID);
		curr = curr->next;
	}
	while (curr->next != NULL && nb > 0)
	{
		// ID = fopen("debugi.txt", "a");
		// fprintf(ID, "===j=%d i=%d====\n", j,i);
		// fprintf(ID, "GAP.y=%d GAP.x=%d\n", curr->gap.y, curr->gap.x);
		i += curr->gap.x;
		j += curr->gap.y;
		// fprintf(ID, "===j=%d i=%d====\n", j,i);
		// fclose(ID);
		if (f->map.tab[j][i] == '.')
		{
			nb--;
			ID = fopen("debugi.txt", "a");
			fprintf(ID, "IF[j=%d][i=%d][%c]nb=%d\n",j,i, f->map.tab[j][i],nb);
			fclose(ID);
		}
		curr = curr->next;
	}
	if (nb == 0)
	{
		ID = fopen("debugi.txt", "a");
		fprintf(ID, "CHECK_SP_PC OK\n");
		fclose(ID);
		return (1);
	}
	else
	{
		ID = fopen("debugi.txt", "a");
		fprintf(ID, "CHECK_SP_PC NO nb=%d\n",nb);
		fclose(ID);
		return (-1);
	}
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

int find_possible_sp1bis(t_filler *f)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "FD_POS_SP_1BIS\n");
	fclose(ID);
	int i;
	int j;

	j = 0;
	while (j < f->map.height)
	{
		i = f->map.width - 1;
		while (i > 0)
		{
			if ((f->map.tab[j][i] == f->me.let) &&
					(f->map.tab[j][i + 1] == '.' || f->map.tab[j + 1][i] == '.' ||
					 f->map.tab[j][i - 1] == '.' || f->map.tab[j - 1][i] == '.' ||
					 f->map.tab[j + 1][i + 1] == '.' || f->map.tab[j - 1][i + 1] == '.' ||
					 f->map.tab[j - 1][i - 1] == '.' || f->map.tab[j + 1][i - 1] == '.'))
			{
				if (check_sp_pc(f, &f->s, j, i) == 1)
				{
					ID = fopen("debugi.txt", "a");
					fprintf(ID, "PLACE: MAP MIN [j]=%d [i]=%d\n", j, i);
					fclose(ID);
					assign_pt(&f->map.min, i, j);
					place(f);
					return (1);
				}
			}
			i--;
		}
		j++;
	}
	return(-1);
}

int find_possible_sp1(t_filler *f)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "FD_POS_SP_1\n");
	fclose(ID);
	int i;
	int j;

	j = 0;
	while (j < f->map.height)
	{
		i = 0;
		while (i < f->map.width)
		{
			if ((f->map.tab[j][i] == f->me.let) &&
					(f->map.tab[j][i + 1] == '.' || f->map.tab[j + 1][i] == '.' ||
					 f->map.tab[j][i - 1] == '.' || f->map.tab[j - 1][i] == '.' ||
					 f->map.tab[j + 1][i + 1] == '.' || f->map.tab[j - 1][i + 1] == '.' ||
					 f->map.tab[j - 1][i - 1] == '.' || f->map.tab[j + 1][i - 1] == '.'))
			{
				if (check_sp_pc(f, &f->s, j, i) == 1)
				{
					ID = fopen("debugi.txt", "a");
					fprintf(ID, "PLACE: MAP MIN [j]=%d [i]=%d\n", j, i);
					fclose(ID);
					assign_pt(&f->map.min, i, j);
					place(f);
					return (1);
				}
			}
			i++;
		}
		j++;
	}
	if (find_possible_sp1bis(f) == 1)
		return (1);
	return(-1);
}

int find_possible_sp2bis(t_filler *f)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "FD_POS_SP_2BIS\n");
	fclose(ID);
	int i;
	int j;

	j = f->map.height - 1;
	while (j > 0)
	{
		i = 0;
		while (i < f->map.width)
		{
			if ((f->map.tab[j][i] == f->me.let) &&
					(f->map.tab[j][i + 1] == '.' || f->map.tab[j + 1][i] == '.' ||
					 f->map.tab[j][i - 1] == '.' || f->map.tab[j - 1][i] == '.' ||
					 f->map.tab[j + 1][i + 1] == '.' || f->map.tab[j - 1][i + 1] == '.' ||
					 f->map.tab[j - 1][i - 1] == '.' || f->map.tab[j + 1][i - 1] == '.'))
			{
				if (check_sp_pc(f, &f->s, j, i) == 1)
				{
					ID = fopen("debugi.txt", "a");
					fprintf(ID, "PLACE: MAP MIN [j]=%d [i]=%d\n", j, i);
					fclose(ID);
					assign_pt(&f->map.min, i, j);
					place(f);
					return (1);
				}
			}
			i++;
		}
		j--;
	}
	return(-1);
}

int find_possible_sp2(t_filler *f)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "FD_POS_SP_2\n");
	fclose(ID);
	int i;
	int j;

	j = f->map.height - 1;
	while (j > 0)
	{
		i = f->map.width - 1;
		while (i > 0)
		{
			if ((f->map.tab[j][i] == f->me.let) &&
					(f->map.tab[j][i + 1] == '.' || f->map.tab[j + 1][i] == '.' ||
					 f->map.tab[j][i - 1] == '.' || f->map.tab[j - 1][i] == '.' ||
					 f->map.tab[j + 1][i + 1] == '.' || f->map.tab[j - 1][i + 1] == '.' ||
					 f->map.tab[j - 1][i - 1] == '.' || f->map.tab[j + 1][i - 1] == '.'))
			{
				if (check_sp_pc(f, &f->s, j, i) == 1)
				{
					ID = fopen("debugi.txt", "a");
					fprintf(ID, "PLACE: MAP MIN [j]=%d [i]=%d\n", j, i);
					fclose(ID);
					assign_pt(&f->map.min, i, j);
					place(f);
					return (1);
				}
			}
			i--;
		}
		j--;
	}
	if (find_possible_sp2bis(f) == 1)
		return (1);
	return(-1);
}

void	which_algo(t_filler *f)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "WHICH_ALGO\n");
	fclose(ID);
	if (f->me.init.y < f->opp.init.y)
	{
		ID = fopen("debugi.txt", "a");
	fprintf(ID, "GOING DOWN\n");
	fclose(ID);
		find_possible_sp2(f);
	}
	else if (f->me.init.y >= f->opp.init.y)
	{
		ID = fopen("debugi.txt", "a");
	fprintf(ID, "GOING UP\n");
	fclose(ID);
		find_possible_sp1(f);
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
				assign_pt(&f->map.min, i, j);
				ID = fopen("debugi.txt", "a");
				fprintf(ID, "map.minY=%d map.minX=%d\n", f->map.min.y, f->map.min.x);
				fclose(ID);
				kk = check_sp_pc(f, &f->s, j, i);
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
	//doesn't go there ever
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

int	check_place2(t_filler *f, int j, int i)
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
				assign_pt(&f->map.min, i, j);
				ID = fopen("debugi.txt", "a");
				fprintf(ID, "map.minY=%d map.minX=%d\n", f->map.min.y, f->map.min.x);
				fclose(ID);
				kk = check_sp_pc(f, &f->s, j, i);
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
	//doesn't go there ever
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
			//ft_strdel(&line);
		}
		else if (line && !ft_strncmp(line, "Piece ", 6))
		{
			ID = fopen("debugi.txt", "a");
			fprintf(ID, "PIECE%d\n", k);
			fclose(ID);
			k++;
			get_piece(&f, line);
			which_algo(&f);
			// if ((lol = (check_place(&f, f.me.init.y, f.me.init.x))))
			// {
			// 	ID = fopen("debugi.txt", "a");
			// 	fprintf(ID, "lol%d\n", lol);
			// 	fclose(ID);
			// 	if (lol == 1)
			// 	{
			// 		print_tab(&f.piece);
			// 		place(&f);
			// 	}
			// 	else if (lol != 1)
			// 	{
			// 		ID = fopen("debugi.txt", "a");
			// 		fprintf(ID, "lolno%d\n", lol);
			// 		fclose(ID);
			// 		print_tab(&f.piece);
			// 		place(&f);
			// 	}
		// }m
		}
		ID = fopen("debugi.txt", "a");
		fprintf(ID, "MAIN WHILE END line%d [%s]\n", i, line);
		fclose(ID);
		//if (line)
		//ft_strdel(&line);
		i++;
	}
	return (0);
}
