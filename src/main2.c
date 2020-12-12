/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:22:10 by mbui              #+#    #+#             */
/*   Updated: 2020/11/22 19:11:47 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int	debug(int i)//, char *line)
{
	char	*line;
	FILE	*ID;
	
	ID = fopen("debug.txt","a");
	get_next_line(0, &line);
	fprintf(ID,"line[%d]=%s\n",i, line);
	if (!line)
	{
		fprintf(ID,"ENDNULL");
		return (-1);
	}
	if (line && !ft_strncmp(line, "== X fin: ", 10))
	{
		fprintf(ID,"ENDOK");
			return (-1);
	}
	ft_strdel(&line);
    fclose(ID);
	return (1);
}

int	get_player(t_filler *filler)
{
	char 	*line;
	FILE *ID = fopen("player.txt","a");

	get_next_line(0, &line);
	fprintf(ID,"line=%s\n", line);
	if (line && !ft_strncmp(line, "$$$ exec p", 10) &&
	(line[10] == '1' || line[10] == '2'))
	{
		filler->me = (line[10] == '1') ? 'O' : 'X';
		filler->opp = (line[10] == '1') ? 'X' : 'O';
		ft_strdel(&line);
		fprintf(ID,"f.me=%c\n", filler->me);
		fprintf(ID,"f.opp=%c\n", filler->opp);
		return (1);
	}
	return (-1);
}

void	find_pt(t_filler *filler)
{
	int	i;
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

void	init_object(t_object *object)
{
	if (object->tab)
		free_tab(object->tab, object->height - 1);
	object->tab = NULL;
	object->height = 0;
	object->width = 0;
}

int		fill_object(t_object *object, unsigned int start)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	FILE *ID = fopen("fillobject.txt","a");
	if (object->tab)
		free_tab(object->tab, object->height-1);
	if (!(object->tab = (char **)ft_memalloc(sizeof(char *) * object->height)))
		return (-1);
	while (i < object->height && get_next_line(0, &line) > -1 && line)
	{
		if (!(object->tab[i] = ft_strsub(line, start, object->width)))
			return (-1);
		fprintf(ID,"[%03d]=%s\n", i,object->tab[i]);
		ft_strdel(&line);
		i++;
	}
	return (1);
}


void	get_map(t_filler *filler, char *line)
{
	if (line && !ft_strncmp(line, "Plateau ", 8))
	{	
		//init_object(&filler->map);
		FILE *ID = fopen("map.txt","a");
		fprintf(ID,"f.map.height=%d\n", filler->map.height);
		fprintf(ID,"f.map.width=%d\n", filler->map.width);
		filler->map.height = ft_atoi(ft_strchr(line, ' '));
		filler->map.width = ft_atoi(ft_strrchr(line, ' '));
		ft_strdel(&line);
		get_next_line(0, &line);// skip line lol
		ft_strdel(&line);
		// if (filler->map.tab)
		// 	free_tab(filler->map.tab, filler->map.height - 1);
		if (!(fill_object(&filler->map, 4)))
			return ;
		find_pt(filler);
		fprintf(ID,"f.map.height=%d\n", filler->map.height);
		fprintf(ID,"f.map.width=%d\n", filler->map.width);
		fprintf(ID,"f.map.pt.x=%d f.map.pt.y=%d\n", filler->map.pt.x, filler->map.pt.y);
		//return (1);
	}
//	return (-1);
}

void	get_piece(t_filler *filler, char *line)
{
	if (line && !ft_strncmp(line, "Piece ", 6))
	{	
		FILE *ID = fopen("piece.txt","a");
		//init_object(&filler->piece);
		fprintf(ID,"lolf.piece.height=%d\n", filler->piece.height);
		fprintf(ID,"lolf.piece.width=%d\n", filler->piece.width);
		filler->piece.height = ft_atoi(ft_strchr(line, ' '));
		filler->piece.width = ft_atoi(ft_strrchr(line, ' '));
		ft_strdel(&line);
		// if (filler->piece.tab)
		// {
		// fprintf(ID,"FREE\n");
		// 	free_tab(filler->piece.tab, filler->piece.height - 1);
		// }
		// if (!filler->piece.tab)
		// fprintf(ID,"not freed\n");
		if (!(fill_object(&filler->piece, 0)))
			return ;
		if (filler->score == 0)
		{
			fprintf(ID,"SCORE\n");
			ft_printf("%d %d\n", 0, 0);
			filler->score = 1;
		}
		// if (filler->score == 1)
		// {
		// 	fprintf(ID,"SCORE\n");
		// 	ft_printf("%d %d\n", 12, 14);
		// 	filler->score = 2;
		// }
		fprintf(ID,"f.piece.height=%d\n", filler->piece.height);
		fprintf(ID,"f.piece.width=%d\n", filler->piece.width);
		//return (1);
	}
//	return (-1);
}

void	debug2(void)
{
	char	*line;
	int		i;
	FILE	*ID;
	
	i = 0;
	ID = fopen("debugi.txt","a");
	//get_next_line(0, &line);
	 while (get_next_line(0, &line) > -1 && line)
	{
		fprintf(ID,"line[%d]=%s\n",i, line);
	 	i++;
		ft_strdel(&line);
	}
    fclose(ID);
}

int	main(void)
{
	t_filler	f;
	int			i;
	char		*line;
	//int			ret;
	int score;
	
	score = 0;
	i = 0;
	line = NULL;
	ft_bzero(&f, sizeof(t_filler));
	if (!(get_player(&f)))
		return (-1);
	FILE *ID = fopen("debugi.txt","a");
	while (get_next_line(0, &line) > -1 && line)
	{
		 if (line && !ft_strncmp(line, "Plateau ", 8))
		 get_map(&f, line);
		 if (line && !ft_strncmp(line, "Piece ", 6))
		 get_piece(&f, line);
	// 	ft_putnbr(0);
	// ft_putchar(' ');
	// ft_putnbr(0);
	// ft_putchar('\n');
		//ft_printf("%d %d\n", 8, 2);
		// if (score == 0)
		// {
		// 	fprintf(ID,"SCORE\n");
		// 	ft_printf("%d %d\n", 0, 0);
		// 	score = 1;
		// } 
		// if (score == 1)
		// {
		// 	fprintf(ID,"SCORE\n");
		// 	ft_printf("%d %d\n", 12, 14);
		// 	score = 2;
		// }
		fprintf(ID,"line[%d]=%s\n",i, line);
		ft_strdel(&line);
		i++;
	}
	// get_next_line(0, &line);
	// get_map(&f, line);
	// ft_strdel(&line);
	// get_next_line(0, &line);
	// get_piece(&f, line);
	// ft_putnbr(12);
	// ft_putchar(' ');
	// ft_putnbr(15);
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
