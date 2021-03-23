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

// int debug(int i) //, char *line)
// {
// 	char *line;
// 	FILE *ID;

// 	ID = fopen("debugi.txt", "a");
// 	get_next_line(0, &line);
// 	fprintf(ID, "line[%d]=%s\n", i, line);
// 	if (!line)
// 	{
// 		fprintf(ID, "ENDNULL");
// 		fclose(ID);
// 		return (-1);
// 	}
// 	if (line && !ft_strncmp(line, "== X fin: ", 10))
// 	{
// 		fprintf(ID, "ENDOK");
// 		fclose(ID);
// 		return (-1);
// 	}
// 	ft_strdel(&line);
// 	fclose(ID);
// 	return (1);
// }

int check_sp_pc(t_filler *f, int j, int i)
{
	FILE *ID = fopen("debugi.txt", "a");
	int nb;
	int nb2;
	int i2;
	int j2;

	fprintf(ID, "CHECK_SP_PC\n");
	fprintf(ID, "TRY j=[%d] i=[%d]\n" ,j ,i);
	fclose(ID);
	nb = 0;
	nb2 = 0;
	j2 = 0;
	if (j + f->piece.height > f->map.height || i + f->piece.width > f->map.width)
	{
		ID = fopen("debugi.txt", "a");
		fprintf(ID, "STOPSTOP\n");
		fclose(ID);
		return (-1);
	}
	while (j2 < f->piece.height)
	{
		i2 = 0;
		while (i2 < f->piece.width)
		{
			if (f->piece.tab[j2][i2] == '*' &&
			f->map.tab[j + j2][i + i2] == '.')
				nb++;
			if (f->piece.tab[j2][i2] == '*' &&
			f->map.tab[j + j2][i + i2] == f->me.let)
				nb2++;
			i2++;
		}
		j2++;
	}
	ID = fopen("debugi.txt", "a");
		fprintf(ID, "nstar=%d =? nb=%d & nb2=%d\n",f->piece.nstar, nb, nb2);
		fclose(ID);
	if (nb == f->piece.nstar - 1 && nb2 == 1)
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
			fprintf(ID, "PIECE%d\n", k++);
			fclose(ID);
			get_piece(&f, line);
			which_algo(&f);
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
