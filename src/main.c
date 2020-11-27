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
	//if (!ft_strncmp(line, "(null)", 6))
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

void	get_player(t_filler *filler)
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
	//	return (1);
	}
	//return (-1);
}

void	get_mapsize(t_filler *filler)
{
	char 	*line;
	char 	**size;

	get_next_line(0, &line);
	if (line && !ft_strncmp(line, "Plateau ", 8))
	{	
		if (!(size = ft_strsplit(line, ' ')))
			return ;
		filler->map.height = ft_atoi(size[1]);
		filler->map.width = ft_atoi(size[2]);
		free_tab(size, 3);
		ft_strdel(&line);
		FILE *ID = fopen("map.txt","a");
		fprintf(ID,"f.map.height=%d\n", filler->map.height);
		fprintf(ID,"f.map.width=%d\n", filler->map.width);
		//return (1);
	}
//	return (-1);
}

void	get_piece(t_filler *filler, char *line)
{
	//char 	*line;
	char 	**size;

	//get_next_line(0, &line);
	if (line && !ft_strncmp(line, "Piece ", 6))
	{	
		if (!(size = ft_strsplit(line, ' ')))
			return ;
		filler->map.height = ft_atoi(size[1]);
		filler->map.width = ft_atoi(size[2]);
		free_tab(size, 3);
		ft_strdel(&line);
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
	 while (get_next_line(0, &line) > -1)
	//while (line[i])
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
	int			ret;
	
	i = 0;
	line = NULL;
	ft_bzero(&f, sizeof(t_filler));
	get_player(&f);
	get_mapsize(&f);
	//ret = 1;
	while ((ret = debug(i)) == 1)
	//while (get_next_line(0, &line) > -1 && ret == 1)
	{
		//ret = debug(i);//, line);
		i++;
	}
	// while (!line)
	// {
	// 	debug(i);
	// 	i++;
	// }
	// while (!line)
	//  // while (get_next_line(0, &line) > -1)
	// {
	// 	debug(i);
	// 	// if (!ft_strncmp(line, "(null)", ft_strlen(line) - 6))
	// 	// 	return (-1);
	// 	i++;
	// }
	//if (!(f = (t_filler*)ft_memalloc(sizeof(t_filler))))
	//	return (-1);
	//init_filler(f);
	//fprintf("line[10]=%s\n", line[10]);
	// while ((ret = get_next_line(0, &line)) == 1)
	// 	{
	// 		ft_printf("line=%s\n", line);
	// 		ft_strdel(&line);
	// 		count_lines++;
	// 	}
	// 	free(line);
	// 	ft_printf("\n------\nRet: %d\nLines: %d\n", ret, count_lines);
	return (0);
}
