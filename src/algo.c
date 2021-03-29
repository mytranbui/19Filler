/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 01:08:15 by mbui              #+#    #+#             */
/*   Updated: 2021/03/29 09:26:39 by mbui             ###   ########.fr       */
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

	j = 0;
	while (j < f->map.height)
	{
		i = f->map.width - 1;
		while (i > 0)
		{
			if (check_place(f, j, i) == 1)
			{
				place_and_free(f, j, i);
				return (1);
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
			if (check_place(f, j, i) == 1)
			{
				place_and_free(f, j, i);
				return (1);
			}
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

	j = f->map.height - 1;
	while (j > 0)
	{
		i = 0;
		while (i < f->map.width)
		{
			if (check_place(f, j, i) == 1)
			{
				place_and_free(f, j, i);
				return (1);
			}
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

	j = f->map.height - 1;
	while (j > 0)
	{
		i = f->map.width - 1;
		while (i > 0)
		{
			if (check_place(f, j, i) == 1)
			{
				place_and_free(f, j, i);
				return (1);
			}
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

	i = f->map.width - 1;
	while (i > 0)
	{
		j = f->map.height - 1;
		while (j > 0)
		{
			if (check_place(f, j, i) == 1)
			{
				place_and_free(f, j, i);
				return (1);
			}
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

	i = 0;
	while (i < f->map.width)
	{
		j = 0;
		while (j < f->map.height)
		{
			if (check_place(f, j, i) == 1)
			{
				place_and_free(f, j, i);
				return (1);
			}
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
				place_and_free(f, 0, 0);
				exit(1);
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
