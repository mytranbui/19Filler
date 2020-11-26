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

int		get_player(t_filler *filler)
{
	 FILE	*ID;


	ID = fopen("play.txt","a");
	 fprintf(ID,"LOL");
	char 	*line;

	get_next_line(0, &line);
	if (line && !ft_strncmp(line, "$$$ exec p", 10) &&
	(line[10] == '1' || line[10] == '2'))
	{
	 	fprintf(ID,"LOL");
		filler->me = (line[10] == '1') ? 'O' : 'X';
		filler->opp = (line[10] == '1') ? 'X' : 'O';
		ft_strdel(&line);
		FILE *ID = fopen("LOL.txt","a");
	fprintf(ID,"f.me=%c\n", filler->me);
	fprintf(ID,"f.opp=%c\n", filler->opp);
		return (1);
	}
	return (-1);
}

// void	get_mapsize(t_filler *filler)
// {

// }

void	debug(int i)
{
	char	*line;
	// int		i;
	FILE	*ID;
	
	// i = 0;
	ID = fopen("debug.txt","a");
	get_next_line(0, &line);
	fprintf(ID,"line[%d]=%s\n",i, line);
	// while (line[i])
	// {
	// 	fprintf(ID,"line[%d]=%c\n",i, line[i]);
	//  	i++;
	// }
	ft_strdel(&line);
    fclose(ID);
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
	//int			ret;
	
	i = 0;
	line = NULL;
	ft_bzero(&f, sizeof(t_filler));
	if (get_player(&f))
	{
		FILE *ID = fopen("LOL2.txt","a");
		fprintf(ID,"f.me=%c\n", f.me);
		fprintf(ID,"f.opp=%c\n", f.opp);
	}
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
	//f.me = (line[10] == '1') ? 'O' : 'X';
	//f.opp = (line[10] == '1') ? 'X' : 'O';
	// FILE *ID = fopen("debug.txt","a");
	// fprintf(ID,"f.me=%c\n", f.me);
	// fprintf(ID,"f.opp=%c\n", f.opp);
	// // if (!ft_strncmp(line, "Plateau ", 8))
	// // line = NULL;
	// while (!line)
	//  // while (get_next_line(0, &line) > -1)
	// {
	// 	debug(i);
	// 	// if (!ft_strncmp(line, "(null)", ft_strlen(line) - 6))
	// 	// 	return (-1);
	// 	i++;
	// }
	// get_next_line(0, &line);
	// while (line[j])
	// {
	// 	fprintf(ID,"line[%d]=%c\n",j, line[j]);
	//  	j++;
	// }
    // fclose(ID);
	return (0);
}
