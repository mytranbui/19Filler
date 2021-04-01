/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 01:08:15 by mbui              #+#    #+#             */
/*   Updated: 2021/04/01 17:13:51 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"


int possible_sp_ne2(t_filler *f)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "GOING_RIGHTUPFilcolrl\n");
	fclose(ID);
	int i;
	int j;

	i = f->map.width - 1;
	while (i > 0)
	{
		j = 0;
		while (j < f->map.height)
		{
			if (check_place(f, j, i) == 1)
			{
				f->nb_piece++;
				place_and_free(f, j, i);
				if (f->nb_piece + f->me.init.y > f->map.height)
					return (-1);
				return (1);
			}
			j++;
		}
		i--;
	}
	return(-1);
}

int possible_sp_ne(t_filler *f)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "GOING_UPRIGHTfillinerl\n");
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
				f->nb_piece++;
				place_and_free(f, j, i);
				if (f->nb_piece + f->me.init.y > f->map.height)
					return (-1);
				return (1);
			}
			i--;
		}
		j++;
	}
	return(-1);
}

int possible_sp_so2(t_filler *f)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "GOING_LEFTDOWNfillcollr\n");
	fclose(ID);
	int i;
	int j;

	i = 0;
	while (i < f->map.width)
	{
		j = f->map.height - 1;
		while (j > 0)
		{
			if (check_place(f, j, i) == 1)
			{
				f->nb_piece++;
				place_and_free(f, j, i);
				if (f->nb_piece + f->me.init.y > f->map.height)
					return (-1);
				return (1);
			}
			j--;
		}
		i++;
	}
	return(-1);
}

int possible_sp_so(t_filler *f)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "GOING_LEFTDOWNfillinelr\n");
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
				f->nb_piece++;
				place_and_free(f, j, i);
				if (f->nb_piece + f->me.init.y > f->map.height)
					return (-1);
				return (1);
			}
			i++;
		}
		j--;
	}
	return(-1);
}

int possible_sp_se2(t_filler *f)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "GOING_RIGHTDOWNfillinelr\n");
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
				f->nb_piece++;
				place_and_free(f, j, i);
				if (f->nb_piece + f->me.init.y > f->map.height)
					return (-1);
				return (1);
			}
			i--;
		}
		j--;
	}
	return(-1);
}

int possible_sp_se(t_filler *f)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "FD_POS_SP_3\n");
	fprintf(ID, "GOING_RIGHTDOWNfilcollr\n");
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
				f->nb_piece++;
				place_and_free(f, j, i);
				// 		if (f->nb_piece + f->me.init.y > f->map.height)
				// 		{
				// 			ID = fopen("debugi.txt", "a");
				// fprintf(ID, "overpiece2\n");
				// fclose(ID);
				// 			return (-1);
				// 		}
				return (1);
			}
			j--;
		}
		i--;
	}
	ID = fopen("debugi.txt", "a");
	fprintf(ID, "-222222\n");
	fclose(ID);
	return(-1);
}

int possible_sp_no2(t_filler *f)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "GOING_LEFTUPfillinelr\n");
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
				f->nb_piece++;
				place_and_free(f, j, i);
				if (f->nb_piece + f->me.init.y > f->map.height)
					return (-1);
				return (1);
			}
			i++;
		}
		j++;
	}
	return(-1);
}

int possible_sp_no(t_filler *f)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "GOING_UPLEFTfilcollr\n");
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
				f->nb_piece++;
				place_and_free(f, j, i);
				// 		if (f->nb_piece + f->me.init.y > f->map.height)
				// 		{
				// 			ID = fopen("debugi.txt", "a");
				// fprintf(ID, "overpiece\n");
				// fclose(ID);
				// 			return (-1);
				// 		}
				return (1);
			}
			j++;
		}
		i++;
	}
	ID = fopen("debugi.txt", "a");
	fprintf(ID, "-1111111\n");
	fclose(ID);
	return(-1);
}

void	which_algo(t_filler *f)
{
	if (f->me.init.y < f->opp.init.y)
	{
		if (f->me.init.x < f->opp.init.x)
		{
			if (possible_sp_se(f) == -1)
				if (possible_sp_no(f) == -1)
					exit(EXIT_SUCCESS);
		}
		else if (f->me.init.x >= f->opp.init.x)
		{
			if (possible_sp_ne(f) == -1)
				if (possible_sp_so(f) == -1)
					exit(EXIT_SUCCESS);
		}
	}
	else if (f->me.init.y >= f->opp.init.y)
	{
		if (f->me.init.x < f->opp.init.x)
		{
			if (possible_sp_so(f) == -1)
				if (possible_sp_ne(f) == -1)
					exit(EXIT_SUCCESS);
		}
		else if (f->me.init.x >= f->opp.init.x)
		{
			if (possible_sp_no(f) == -1)
				if (possible_sp_se(f) == -1)
					exit(EXIT_SUCCESS);
		}
	}
}