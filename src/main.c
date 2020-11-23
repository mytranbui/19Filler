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

int	main(void)
{
	ft_printf("MBUI");
	//t_filler	f;
	int			i;
	char		*line;
	//int			ret;
	int			count_lines;
	
	i = 0;
	count_lines = 0;
	get_next_line(0, &line);
	ft_printf("line[10]=%s\n", line[10]);
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
