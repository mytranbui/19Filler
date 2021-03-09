/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 18:55:26 by mbui              #+#    #+#             */
/*   Updated: 2021/03/09 14:02:04 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int get_player(t_filler *f)
{
	FILE *ID = fopen("debugi.txt", "a");
	char *line;

	f->me.init.x = -1;
	f->me.init.y = -1;
	f->opp.init.x = -1;
	f->opp.init.y = -1;
	get_next_line(0, &line);
	fprintf(ID, "~~get_player~~\n");
	if (line && !ft_strncmp(line, "$$$ exec p", 10) &&
			(line[10] == '1' || line[10] == '2'))
	{
		f->me.let = (line[10] == '1') ? 'O' : 'X';
		f->opp.let = (line[10] == '1') ? 'X' : 'O';
		ft_strdel(&line);
		fprintf(ID, "ME=%c\n", f->me.let);
		fprintf(ID, "OP=%c\n", f->opp.let);
		fclose(ID);
		return (1);
	}
	fclose(ID);
	return (-1);
}

void init_object(t_object *o)
{
	//if (o->tab)
	//	free_tab(o->tab, o->height - 1);
	o->tab = NULL;
	o->height = 0;
	o->width = 0;
	init_point(&o->min);
}

void fill_object(t_object *o, unsigned int start)
{
	int i;
	char *line;

	i = 0;
	line = NULL;
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "~fill_object~\n");
	fclose(ID);
	//if (o->tab)
	//free_tab(o->tab, o->height-1);
	if (!(o->tab = (char **)ft_memalloc(sizeof(char *) * o->height)))
		return;
	while (i < o->height && get_next_line(0, &line) > 0)
	{
		if (!(o->tab[i] = ft_strsub(line, start, o->width)))
			return;
		ID = fopen("debugi.txt", "a");
		fprintf(ID, "%03d %s\n", i, o->tab[i]);
		fclose(ID);
		ft_strdel(&line);
		i++;
	}
	ID = fopen("debugi.txt", "a");
	fprintf(ID, "~fill_object~END\n");
	fclose(ID);
	//return (object);
}

void get_map(t_filler *f, char *line)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "~get_map~\n");
	fclose(ID);
	if (line && !ft_strncmp(line, "Plateau ", 8))
	{
		//init_object(&f->map);
		ID = fopen("debugi.txt", "a");
		f->map.height = ft_atoi(ft_strchr(line, ' '));
		f->map.width = ft_atoi(ft_strrchr(line, ' '));
		ft_strdel(&line);
		get_next_line(0, &line); // skip line lol
		ft_strdel(&line);
		// if (f->map.tab)
		// 	free_tab(f->map.tab, f->map.height - 1);
		fill_object(&f->map, 4);
		if (f->me.init.x == -1 && f->me.init.y == -1 && f->opp.init.x == -1 && f->opp.init.y == -1)
			find_start(f);
		fprintf(ID, "M.height =	%d\n", f->map.height);
		fprintf(ID, "M.width  =	%d\n", f->map.width);
		fclose(ID);
		//return (1);
	}
	//	return (-1);
}

t_star *find_stars(t_object *o)
{
	FILE *ID = fopen("debugi.txt", "a");
	int i;
	int j;
	t_star	*head;
	t_star	*new;
	t_point	tmp;
	int kk=0;

	if (!(head = (t_star*)ft_memalloc(sizeof(t_star))))
		return (NULL);
	init_point(&head->gap);
	head->nb = 0;
	new = head;
	init_point(&tmp);
	j = 0;
	while (j < o->height)
	{
		i = 0;
		while (i < o->width)
		{
			if (o->tab[j][i] == '*')
			{
				if (!(new->next = (t_star*)ft_memalloc(sizeof(t_star))))
					return (lstdel_star(&head));
				head->nb++;
				if (head->nb == 1)
				{
					assign_point(&tmp, i, j);
					assign_point(&o->min, i, j);
					ID = fopen("debugi.txt", "a");
					fprintf(ID, "TMP.y=%d TMP.x=%d\n", tmp.y, tmp.x);
					fprintf(ID, "o->min.y=%d o->min.x=%d\n", o->min.y, o->min.x);
					fclose(ID);
					assign_point(&new->gap, tmp.x, tmp.y);
				}
				else
				{
					assign_point(&new->gap, i - tmp.x, j - tmp.y);
					ID = fopen("debugi.txt", "a");
					fprintf(ID,"%d(gap.x) = %d(i) - %d(tmp.x)\n",new->gap.x, i, tmp.x);
					fprintf(ID,"%d(gap.y) = %d(j) - %d(tmp.y)\n",new->gap.y, j, tmp.y);
					fclose(ID);
				}
				assign_point(&tmp, i, j);
				ID = fopen("debugi.txt", "a");
				fprintf(ID, "[%d]GAP.y=%d GAP.x=%d\n",kk++, new->gap.y, new->gap.x);
				fclose(ID);
				new = new->next;
			}
			i++;
		}
		j++;
	}
	ID = fopen("debugi.txt", "a");
	fprintf(ID, "~find_star~END\n");
	fclose(ID);
	new->next = NULL;
	return (head);
}

// t_star	store_stars(t_object *o)
// {
// 	t_star	*head;
// 	t_star	*new;

// 	if (!(head = (t_star*)ft_memalloc(sizeof(t_star))))
// 		return (NULL);
// 	head->gap.x = 0;
// 	head->gap.y = 0;
// 	head->nb = 0;
// 	new = head;
// 	new->next = NULL;
// 	return (head);
// }

void get_piece(t_filler *f, char *line)
{
	FILE *ID = fopen("debugi.txt", "a");
	//t_star	*head;

	if (line && !ft_strncmp(line, "Piece ", 6))
	{
		//init_object(&f->piece);
		fprintf(ID, "~get_piece~\n");
		fclose(ID);
		f->piece.height = ft_atoi(ft_strchr(line, ' '));
		f->piece.width = ft_atoi(ft_strrchr(line, ' '));
		fill_object(&f->piece, 0);
		ID = fopen("debugi.txt", "a");
		fprintf(ID, "P.height =	%d\n", f->piece.height);
		fprintf(ID, "P.width  =	%d\n", f->piece.width);
		fclose(ID);
		f->s = find_stars(&f->piece);
		//head = find_stars(&f->piece);
		//f->s = head;
		printlst(f->s);
		ID = fopen("debugi.txt", "a");
		fprintf(ID, "STAR.x=%d\n", f->piece.min.x);
		fprintf(ID, "STAR.y=%d\n", f->piece.min.y);
		fclose(ID);
	}
	ID = fopen("debugi.txt", "a");
	fprintf(ID, "~get_piece~END\n");
	fclose(ID);
	//	return (-1);
}
