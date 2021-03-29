/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 01:08:15 by mbui              #+#    #+#             */
/*   Updated: 2021/03/19 01:08:19 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int find_possible_sp1bis(t_filler *f)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "FD_POS_SP_1BIS\n");
	fclose(ID);
	int i;
	int j;
	int	ret;

	ret = 0;
	j = 0;
	while (j < f->map.height)
	{
		i = f->map.width - 1;
		while (i > 0)
		{
			// if ((f->map.tab[j][i] == f->me.let) &&
			// 		(f->map.tab[j][i + 1] == '.' || f->map.tab[j + 1][i] == '.' ||
			// 		 f->map.tab[j][i - 1] == '.' || f->map.tab[j - 1][i] == '.' ||
			// 		 f->map.tab[j + 1][i + 1] == '.' || f->map.tab[j - 1][i + 1] == '.' ||
			// 		 f->map.tab[j - 1][i - 1] == '.' || f->map.tab[j + 1][i - 1] == '.'))
			// {
				ret = check_place(f, j, i);
				if (ret == 1)
				{
					ID = fopen("debugi.txt", "a");
					fprintf(ID, "PLACE: MAP MIN [j]=%d [i]=%d\n", j, i);
					fclose(ID);
					assign_pt(&f->res, i, j);
					place(f);
					return (1);
				}
			// }
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
	int	ret;

	ret = 0;
	j = 0;
	while (j < f->map.height)
	{
		i = 0;
		while (i < f->map.width)
		{
			// if ((f->map.tab[j][i] == f->me.let) &&
			// 		(f->map.tab[j][i + 1] == '.' || f->map.tab[j + 1][i] == '.' ||
			// 		 f->map.tab[j][i - 1] == '.' || f->map.tab[j - 1][i] == '.' ||
			// 		 f->map.tab[j + 1][i + 1] == '.' || f->map.tab[j - 1][i + 1] == '.' ||
			// 		 f->map.tab[j - 1][i - 1] == '.' || f->map.tab[j + 1][i - 1] == '.'))
			// {
				ret = check_place(f, j, i);
				if (ret == 1)
				{
					ID = fopen("debugi.txt", "a");
					fprintf(ID, "PLACE: MAP MIN [j]=%d [i]=%d\n", j, i);
					fclose(ID);
					assign_pt(&f->res, i, j);
					place(f);
					return (1);
				}
			// }
			i++;
		}
		j++;
	}
	// if (find_possible_sp1bis(f) == 1)
	// 	return (1);
	return(-1);
}

int find_possible_sp2bis(t_filler *f)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "FD_POS_SP_2BIS\n");
	fclose(ID);
	int i;
	int j;
	int	ret;

	ret = 0;
	j = f->map.height - 1;
	while (j > 0)
	{
		i = 0;
		while (i < f->map.width)
		{
			// if ((f->map.tab[j][i] == f->me.let) &&
			// 		(f->map.tab[j][i + 1] == '.' || f->map.tab[j + 1][i] == '.' ||
			// 		 f->map.tab[j][i - 1] == '.' || f->map.tab[j - 1][i] == '.' ||
			// 		 f->map.tab[j + 1][i + 1] == '.' || f->map.tab[j - 1][i + 1] == '.' ||
			// 		 f->map.tab[j - 1][i - 1] == '.' || f->map.tab[j + 1][i - 1] == '.'))
			// {
				ret = check_place(f, j, i);
				if (ret == 1)
				{
					ID = fopen("debugi.txt", "a");
					fprintf(ID, "PLACE: MAP MIN [j]=%d [i]=%d\n", j, i);
					fclose(ID);
					assign_pt(&f->res, i, j);
					place(f);
					return (1);
				}
			// }
			i++;
		}
		j--;
	}
    ID = fopen("debugi.txt", "a");
		fprintf(ID, "STOPBIS\n");
		fclose(ID);
      //  exit(1);
	return(-1);
}

int find_possible_sp2(t_filler *f)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "FD_POS_SP_2\n");
	fclose(ID);
	int i;
	int j;
	int	ret;

	ret = 0;
	j = f->map.height - 1;
	while (j > 0)
	{
		i = f->map.width - 1;
		while (i > 0)
		{
			// if ((f->map.tab[j][i] == f->me.let) &&
			// 		(f->map.tab[j][i + 1] == '.' || f->map.tab[j + 1][i] == '.' ||
			// 		 f->map.tab[j][i - 1] == '.' || f->map.tab[j - 1][i] == '.' ||
			// 		 f->map.tab[j + 1][i + 1] == '.' || f->map.tab[j - 1][i + 1] == '.' ||
			// 		 f->map.tab[j - 1][i - 1] == '.' || f->map.tab[j + 1][i - 1] == '.'))
			// {
				ret = check_place(f, j, i);
				if (ret == 1)
				{
					ID = fopen("debugi.txt", "a");
					fprintf(ID, "PLACE: MAP MIN [j]=%d [i]=%d\n", j, i);
					fclose(ID);
					assign_pt(&f->res, i, j);
					place(f);
					return (1);
				}
			// }
			i--;
		}
		j--;
	}
	if (find_possible_sp2bis(f) == 1)
		return (1);
	return(-1);
}

int find_possible_sp3(t_filler *f)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "FD_POS_SP_3\n");
	fprintf(ID, "GOING_RIGHT\n");
	fclose(ID);
	int i;
	int j;
	int	ret;

	ret = 0;
	i = f->map.width - 1;
	while (i > 0)
	{
	    j = f->map.height - 1;
	    while (j > 0)
		{
			// if ((f->map.tab[j][i] == f->me.let) &&
			// 		(f->map.tab[j][i + 1] == '.' || f->map.tab[j + 1][i] == '.' ||
			// 		 f->map.tab[j][i - 1] == '.' || f->map.tab[j - 1][i] == '.' ||
			// 		 f->map.tab[j + 1][i + 1] == '.' || f->map.tab[j - 1][i + 1] == '.' ||
			// 		 f->map.tab[j - 1][i - 1] == '.' || f->map.tab[j + 1][i - 1] == '.'))
			// {
				ret = check_place(f, j, i);
				if (ret == 1)
				{
					ID = fopen("debugi.txt", "a");
					fprintf(ID, "PLACE: MAP MIN [j]=%d [i]=%d\n", j, i);
					fclose(ID);
					assign_pt(&f->res, i, j);
					place(f);
					return (1);
				}
			// }
		j--;
		}
			i--;
	}
	// if (find_possible_sp2bis(f) == 1)
	// 	return (1);
	return(-1);
}

int find_possible_sp4(t_filler *f)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "FD_POS_SP_4\n");
	fprintf(ID, "GOING_LEFT??\n");
	fclose(ID);
	int i;
	int j;
	int	ret;

	ret = 0;
	i = 0;
	while (i < f->map.width)
	{
	    j = 0;
	    while (j < f->map.height)
		{
			// if ((f->map.tab[j][i] == f->me.let) &&
			// 		(f->map.tab[j][i + 1] == '.' || f->map.tab[j + 1][i] == '.' ||
			// 		 f->map.tab[j][i - 1] == '.' || f->map.tab[j - 1][i] == '.' ||
			// 		 f->map.tab[j + 1][i + 1] == '.' || f->map.tab[j - 1][i + 1] == '.' ||
			// 		 f->map.tab[j - 1][i - 1] == '.' || f->map.tab[j + 1][i - 1] == '.'))
			// {
				ret = check_place(f, j, i);
				if (ret == 1)
				{
					ID = fopen("debugi.txt", "a");
					fprintf(ID, "PLACE: MAP MIN [j]=%d [i]=%d\n", j, i);
					fclose(ID);
					assign_pt(&f->res, i, j);
					place(f);
					return (1);
				}
			// }
		j++;
		}
			i++;
	}
	// if (find_possible_sp2bis(f) == 1)
	// 	return (1);
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
	fprintf(ID, "GOING DOWNkk\n");
	fclose(ID);
		if (find_possible_sp3(f) == -1)
        {
		    if (find_possible_sp1(f) == -1)
            {
            ID = fopen("debugi.txt", "a");
	        fprintf(ID, "EXIT\n");
	        fclose(ID);
            assign_pt(&f->res, 0, 0);
			place(f);
            exit(1);
            //exit useful ?
            }
        }
	}
	else if (f->me.init.y >= f->opp.init.y)
	{
		ID = fopen("debugi.txt", "a");
	fprintf(ID, "GOING UP\n");
	fclose(ID);
	find_possible_sp1(f);
	}
}
