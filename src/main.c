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

int get_player(t_filler *filler)
{
	char *line;
	FILE *ID = fopen("debugi.txt", "a");

	get_next_line(0, &line);
	fprintf(ID, "~get_player~\n");
	fprintf(ID, "line=%s\n", line);
	if (line && !ft_strncmp(line, "$$$ exec p", 10) &&
		(line[10] == '1' || line[10] == '2'))
	{
		filler->me = (line[10] == '1') ? 'O' : 'X';
		filler->opp = (line[10] == '1') ? 'X' : 'O';
		ft_strdel(&line);
		fprintf(ID, "f.me=%c\n", filler->me);
		fprintf(ID, "f.opp=%c\n", filler->opp);
		fclose(ID);
		return (1);
	}
	fclose(ID);
	return (-1);
}

void find_pt(t_filler *filler)
{
	int i;
	int j;

	j = 0;
	while (j < filler->map.height)
	{
		i = 0;
		while (i < filler->map.width)
		{
			if (filler->map.tab[j][i] == filler->me)
			{
				filler->map.pt.x = i;
				filler->map.pt.y = j;
			}
			i++;
		}
		j++;
	}
}

void init_object(t_object *object)
{
	if (object->tab)
		free_tab(object->tab, object->height - 1);
	object->tab = NULL;
	object->height = 0;
	object->width = 0;
}

void fill_object(t_object *object, unsigned int start)
{
	int i;
	char *line;

	i = 0;
	line = NULL;
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "~fill_object~\n");
	fclose(ID);
	//if (object->tab)
	//free_tab(object->tab, object->height-1);
	if (!(object->tab = (char **)ft_memalloc(sizeof(char *) * object->height)))
		return;
	//fprintf(ID, "~hello~\n");
	while (i < object->height && get_next_line(0, &line) > 0)
	{
		if (!(object->tab[i] = ft_strsub(line, start, object->width)))
			return;
		ID = fopen("debugi.txt", "a");
		fprintf(ID, "%03d %s\n", i, object->tab[i]);
		//fprintf(ID,"line[%d]=%s\n",i, line);
		fclose(ID);
		ft_strdel(&line);
		i++;
	}
	ID = fopen("debugi.txt", "a");
	//fprintf(ID,"line[%d]=%s\n",i, line);
	fprintf(ID, "~fill_object~END\n");
	fclose(ID);
	//return (object);
}

void get_map(t_filler *filler, char *line)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "~get_map~\n");
	fclose(ID);
	if (line && !ft_strncmp(line, "Plateau ", 8))
	{
		//init_object(&filler->map);
		ID = fopen("debugi.txt", "a");
		// fprintf(ID,"f.map.height=%d\n", filler->map.height);
		// fprintf(ID,"f.map.width=%d\n", filler->map.width);
		filler->map.height = ft_atoi(ft_strchr(line, ' '));
		filler->map.width = ft_atoi(ft_strrchr(line, ' '));
		ft_strdel(&line);
		get_next_line(0, &line); // skip line lol
		ft_strdel(&line);
		// if (filler->map.tab)
		// 	free_tab(filler->map.tab, filler->map.height - 1);
		fill_object(&filler->map, 4);
		find_pt(filler);
		fprintf(ID, "f.map.height=%d\n", filler->map.height);
		fprintf(ID, "f.map.width=%d\n", filler->map.width);
		fprintf(ID, "f.map.pt.x=%d\n", filler->map.pt.x);
		fprintf(ID, "f.map.pt.y=%d\n", filler->map.pt.y);
		fclose(ID);
		//return (1);
	}
	//	return (-1);
}

void find_stars(t_object *object)
{
	FILE *ID = fopen("debugi.txt", "a");
	int i;
	int j;
	int tmp[2];

	tmp[0] = 0;
	tmp[1] = 0;
	j = 0;
	while (j < object->height)
	{
		i = 0;
		while (i < object->width)
		{
			if (object->tab[j][i] == '*')
			{
				ID = fopen("debugi.txt", "a");
				fprintf(ID, "huh\n");
				fclose(ID);
				if (tmp[0] == 0)
				{
					object->pt.x = i;
					tmp[0] = 1;
					ID = fopen("debugi.txt", "a");
					fprintf(ID, "LOL\n");
					fclose(ID);
				}
				if (tmp[1] == 0)
				{
					object->pt.y = j;
					tmp[1] = 1;
					ID = fopen("debugi.txt", "a");
					fprintf(ID, "HOH\n");
					fclose(ID);
				}
			}
			i++;
		}
		j++;
	}
}

void get_piece(t_filler *filler, char *line)
{
	FILE *ID = fopen("debugi.txt", "a");
	if (line && !ft_strncmp(line, "Piece ", 6))
	{
		//init_object(&filler->piece);
		fprintf(ID, "~get_piece~\n");
		fclose(ID);
		filler->piece.height = ft_atoi(ft_strchr(line, ' '));
		filler->piece.width = ft_atoi(ft_strrchr(line, ' '));
		fill_object(&filler->piece, 0);
		ID = fopen("debugi.txt", "a");
		fprintf(ID, "f.piece.height=%d\n", filler->piece.height);
		fprintf(ID, "f.piece.width=%d\n", filler->piece.width);
		fclose(ID);
		find_stars(&filler->piece);
		ID = fopen("debugi.txt", "a");
		fprintf(ID, "f.piece.pt.x=%d\n", filler->piece.pt.x);
		fprintf(ID, "f.piece.pt.y=%d\n", filler->piece.pt.y);
		fclose(ID);
	}
	ID = fopen("debugi.txt", "a");
	fprintf(ID, "~get_piece~END\n");
	fclose(ID);
	//	return (-1);
}

void debug2(void)
{
	char *line;
	int i;
	FILE *ID;

	i = 0;
	ID = fopen("debugi.txt", "a");
	//get_next_line(0, &line);
	while (get_next_line(0, &line) > -1 && line)
	{
		fprintf(ID, "line[%d]=%s\n", i, line);
		i++;
		ft_strdel(&line);
	}
	fclose(ID);
}

void place(t_filler *filler)
{
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "\nPLACE\n");
	filler->res.x = filler->map.pt.x - filler->piece.pt.x;
	filler->res.y = filler->map.pt.y - filler->piece.pt.y;
	ft_printf("%d %d\n", filler->res.y, filler->res.x);
	fprintf(ID, "%d %d\n", filler->res.y, filler->res.x);
	fclose(ID);
}

int main(void)
{
	t_filler f;
	int i;
	char *line;
	//int			ret;
	int score;
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "\nhello\n");
	fclose(ID);
	score = 0;
	i = 0;
	line = NULL;
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
			ID = fopen("debugi.txt", "a");
			fprintf(ID, "MAP\n");
			fclose(ID);
			get_map(&f, line);
			ID = fopen("debugi.txt", "a");
			fprintf(ID, "OUT OF MAP\n");
			fclose(ID);
		}
		else if (line && !ft_strncmp(line, "Piece ", 6))
		{
			ID = fopen("debugi.txt", "a");
			fprintf(ID, "PIECE\n");
			fclose(ID);
			get_piece(&f, line);
			ID = fopen("debugi.txt", "a");
			fprintf(ID, "out of piece\n");
			//ft_printf("%d %d\n", 0, 0);
			//fprintf(ID, "%d %d\n", 0, 0);
			fclose(ID);
			place(&f);
		}
		ID = fopen("debugi.txt", "a");
		fprintf(ID, "MAIN WHILE END line%d [%s]\n", i, line);
		fclose(ID);
		//if (line)
		//ft_strdel(&line);
		i++;
	}
	// get_next_line(0, &line);
	// ID = fopen("debugi.txt","a");
	// fprintf(ID,"0line=%s\n", line);
	// fclose(ID);
	// get_map(&f, line);
	// ID = fopen("debugi.txt","a");
	// fprintf(ID,"1line=%s\n", line);
	// fclose(ID);
	// //ft_strdel(&line);
	// get_next_line(0, &line);
	// ID = fopen("debugi.txt","a");
	// fprintf(ID,"2line=%s\n", line);
	// fclose(ID);
	// get_piece(&f, line);
	// ID = fopen("debugi.txt","a");
	// fprintf(ID,"3line=%s\n", line);
	// fclose(ID);
	// get_next_line(0, &line);
	// ID = fopen("debugi.txt","a");
	// fprintf(ID,"4cline=%s\n", line);
	// fclose(ID);
	// ft_putnbr(8);
	// ft_putchar(' ');
	// ft_putnbr(2);
	// ft_putchar('\n');
	// ft_strdel(&line);
	/*while ((ret = debug(i)) == 1)
	{
		fprintf(ID,"line[%d]=%s\n",i, line);
		ft_strdel(&line);
		i++;
	}*/
	return (0);
}
