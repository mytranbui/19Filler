/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 01:08:15 by mbui              #+#    #+#             */
/*   Updated: 2021/04/08 18:19:16 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"


int possible_sp_ne2(t_filler *f)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "FD_POS_NE2\n");
	fprintf(ID, "GOING_RIGHTUPFilcolrl\n");
	fclose(ID);
	int i;
	int j;

	i = f->map.w - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < f->map.h)
		{
			if (check_place(f, j, i) == 1)
			{
				place(f, j, i);
				return (1);
			}
			// if (f->nb_piece + f->me.init.y > f->map.h)
			// 	{
			// 		ID = fopen("debugi.txt","a");
			// 		fprintf(ID, "OVERPIECE\n");
			// 		fclose(ID);
			// 		return (-1);
			// 		}
			if (touch_border_right(f) == 1)
				return (-1);
			j++;
		}
		i--;
	}
	return(-1);
}

int possible_sp_ne(t_filler *f)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "FD_POS_NE\n");
	fprintf(ID, "GOING_UPRIGHTfillinerl\n");
	fclose(ID);
	int i;
	int j;

	j = 0;
	while (j < f->map.h)
	{
		i = f->map.w - 1;
		while (i >= 0)
		{
			if (check_place(f, j, i) == 1)
			{
				place(f, j, i);
				return (1);
			}
			// if (f->nb_piece + f->me.init.y > f->map.h)
			// 	{
			// 		ID = fopen("debugi.txt","a");
			// 		fprintf(ID, "OVERPIECE\n");
			// 		fclose(ID);
			// 		return (-1);
			// 		}
			if (touch_border_right(f) == 1)
				return (-1);
			i--;
		}
		j++;
	}
	return(-1);
}

int possible_sp_so2(t_filler *f)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "FD_POS_SO2\n");
	fprintf(ID, "GOING_LEFTDOWNfillcollr\n");
	fclose(ID);
	int i;
	int j;

	i = 0;
	while (i < f->map.w)
	{
		j = f->map.h - 1;
		while (j >= 0)
		{
			if (check_place(f, j, i) == 1)
			{
				place(f, j, i);
				return (1);
			}
			// if (f->nb_piece + f->me.init.y > f->map.h)
			// 	{
			// 		ID = fopen("debugi.txt","a");
			// 		fprintf(ID, "OVERPIECE\n");
			// 		fclose(ID);
			// 		return (-1);
			// 		}
			if (touch_border_left(f) == 1)
				return (-1);
			j--;
		}
		i++;
	}
	return(-1);
}

int possible_sp_so(t_filler *f)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "FD_POS_SO\n");
	fprintf(ID, "GOING_LEFTDOWNfillinelr\n");
	fclose(ID);
	int i;
	int j;

	j = f->map.h - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < f->map.w)
		{
			if (check_place(f, j, i) == 1)
			{
				place(f, j, i);
				return (1);
			}
			// if (f->nb_piece + f->me.init.y > f->map.h)
			// 	{
			// 		ID = fopen("debugi.txt","a");
			// 		fprintf(ID, "OVERPIECE\n");
			// 		fclose(ID);
			// 		return (-1);
			// 		}
			if (touch_border_left(f) == 1)
				return (-1);
			i++;
		}
		j--;
	}
	return(-1);
}

int possible_sp_se2(t_filler *f)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "FD_POS_SE2\n");
	fprintf(ID, "GOING_RIGHTDOWNfillinelr\n");
	fclose(ID);
	int i;
	int j;

	j = f->map.h - 1;
	while (j >= 0)
	{
		i = f->map.w - 1;
		while (i >= 0)
		{
			if (check_place(f, j, i) == 1)
			{
				place(f, j, i);
				return (1);
			}
			// if (f->nb_piece + f->me.init.y > f->map.h)
			// 	{
			// 		ID = fopen("debugi.txt","a");
			// 		fprintf(ID, "OVERPIECE\n");
			// 		fclose(ID);
			// 		return (-1);
			// 		}
			if (touch_border_right(f) == 1)
				return (-1);
			i--;
		}
		j--;
	}
	return(-1);
}


int possible_sp_se(t_filler *f)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "FD_POS_SE\n");
	fprintf(ID, "GOING_RIGHTDOWNfilcollr\n");
	fclose(ID);
	int i;
	int j;

	i = f->map.w - 1;
	while (i >= 0)
	{
		j = f->map.h - 1;
		while (j >= 0)
		{
			if (check_place(f, j, i) == 1)
			{
				place(f, j, i);
				// 		if (f->nb_piece + f->me.init.y > f->map.h)
				// 		{
				// 			ID = fopen("debugi.txt", "a");
				// fprintf(ID, "overpiece2\n");
				// fclose(ID);
				// 			return (-1);
				// 		}
				return (1);
			}
			// if (f->nb_piece + f->me.init.y > f->map.h)
			// 		{
			// 			ID = fopen("debugi.txt","a");
			// 			fprintf(ID, "OVERPIECE\n");
			// 			fclose(ID);
			// 			return (-1);
			// 			}
			if (touch_border_right(f) == 1)
				return (-1);
			j--;
		}
		i--;
	}
	return(-1);
}

int possible_sp_no2(t_filler *f)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "FD_POS_NO2\n");
	fprintf(ID, "GOING_LEFTUPfillinelr\n");
	fclose(ID);
	int i;
	int j;

	j = 0;
	while (j < f->map.h)
	{
		i = 0;
		while (i < f->map.w)
		{
			if (check_place(f, j, i) == 1)
			{
				place(f, j, i);
				return (1);
			}
			// if (f->nb_piece + f->me.init.y > f->map.h)
			// 	{
			// 		ID = fopen("debugi.txt","a");
			// 		fprintf(ID, "OVERPIECE\n");
			// 		fclose(ID);
			// 		return (-1);
			// 		}
			if (touch_border_left(f) == 1)
				return (-1);
			i++;
		}
		j++;
	}
	return(-1);
}

int possible_sp_no(t_filler *f)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "FD_POS_NO\n");
	fprintf(ID, "GOING_UPLEFTfilcollr\n");
	fclose(ID);
	int i;
	int j;

	i = 0;
	while (i < f->map.w)
	{
		j = 0;
		while (j < f->map.h)
		{
			if (check_place(f, j, i) == 1)
			{
				place(f, j, i);
				return (1);
			}
			// if (f->nb_piece + f->me.init.y > f->map.h)
			// 	{
			// 		ID = fopen("debugi.txt","a");
			// 		fprintf(ID, "OVERPIECE\n");
			// 		fclose(ID);
			// 		return (-1);
			// 		}
			if (touch_border_left(f) == 1)
				return (-1);
			j++;
		}
		i++;
	}
	return(-1);
}

int possible_sp_last(t_filler *f)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "FD_POS_LAST\n");
	fclose(ID);
	int i;
	int j;

	i = f->map.w - 1;
	while (i >= 0)
	{
		j = f->map.h - 1;
		while (j >= 0)
		{
			if (check_place(f, j, i) == 1)
			{
				place(f, j, i);
				return (1);
			}
			j--;
		}
		i--;
	}
	return(-1);
}
