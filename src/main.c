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

int		fill_object(t_object *object, unsigned int start)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	FILE *ID = fopen("fillobject.txt","a");
	if (!(object->tab = (char **)ft_memalloc(sizeof(char *) * object->height)))
		return (-1);
	while (i < object->height && get_next_line(0, &line) > -1 && line)
	{
		if (!(object->tab[i] = ft_strsub(line, start, object->width)))
			return (-1);
		fprintf(ID,"object->tab[%d]=%s\n", i,object->tab[i]);
		ft_strdel(&line);
		i++;
	}
	return (1);
}

void	get_map(t_filler *filler, char *line)
{
	char 	**size;

	if (line && !ft_strncmp(line, "Plateau ", 8))
	{	
		if (!(size = ft_strsplit(line, ' ')))
			return ;
		filler->map.height = ft_atoi(size[1]);
		filler->map.width = ft_atoi(size[2]);
		free_tab(size, 3);
		ft_strdel(&line);
		get_next_line(0, &line);// skip line lol
		ft_strdel(&line);
		if (!(fill_object(&filler->map, 4)))
			return ;
		FILE *ID = fopen("map.txt","a");
		fprintf(ID,"f.map.height=%d\n", filler->map.height);
		fprintf(ID,"f.map.width=%d\n", filler->map.width);
		//return (1);
	}
//	return (-1);
}

void	get_piece(t_filler *filler, char *line)
{
	char 	**size;

	if (line && !ft_strncmp(line, "Piece ", 6))
	{	
		if (!(size = ft_strsplit(line, ' ')))
			return ;
		filler->piece.height = ft_atoi(size[1]);
		filler->piece.width = ft_atoi(size[2]);
		free_tab(size, 3);
		ft_strdel(&line);
		if (!(fill_object(&filler->piece, 0)))
			return ;
		FILE *ID = fopen("map.txt","a");
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
		//if (!line)
		//	continue;
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
	
	i = 0;
	line = NULL;
	ft_bzero(&f, sizeof(t_filler));
	if (!(get_player(&f)))
		return (-1);
	//while ((ret = debug(i)) == 1)
	FILE *ID = fopen("debugi.txt","a");
	while (get_next_line(0, &line) > -1 && line)
	{
		get_map(&f, line);
		get_piece(&f, line);
		fprintf(ID,"line[%d]=%s\n",i, line);
		ft_strdel(&line);
		i++;
	}
	return (0);
}
