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

void	get_player(t_filler *filler)
{
	char 	*line;

	get_next_line(0, &line);
	filler->me = (line[10] == '1') ? 'O' : 'X';
	filler->opp = (line[10] == '1') ? 'X' : 'O';
	ft_strdel(&line);
}

void	debug(void)
{
	char	*line;
	int		i;
	FILE	*ID;
	
	i = 0;
	ID = fopen("debug.txt","a");
	get_next_line(0, &line);
	while (line[i])
	{
		fprintf(ID,"line[%d]=%c\n",i, line[i]);
	 	i++;
	}
    fclose(ID);
	ft_strdel(&line);
}

int	main(void)
{
	t_filler	f;
	int			i;
	int			j;
	//char		*line;
	//int			ret;
	int			count_lines;
	
	i = 0;
	j = 0;
	count_lines = 0;
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
	get_player(&f);
	FILE *ID = fopen("debug.txt","a");
	fprintf(ID,"f.me=%c\n", f.me);
	fprintf(ID,"f.opp=%c\n", f.opp);
	debug();
	// get_next_line(0, &line);
	// while (line[j])
	// {
	// 	fprintf(ID,"line[%d]=%c\n",j, line[j]);
	//  	j++;
	// }
    // fclose(ID);
	return (0);
}
