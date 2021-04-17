/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:22:10 by mbui              #+#    #+#             */
/*   Updated: 2021/04/10 17:11:22 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void	init_filler(t_filler *f)
{
	assign_pt(&f->me.init, -1, -1);
	assign_pt(&f->opp.init, -1, -1);
	f->nb_piece = 0;
}

int	main(void)
{
	t_filler	f;
	char		*line;

	line = NULL;
	init_filler(&f);
	if (!(get_player(&f)))
		return (-1);
	while (get_next_line(0, &line) > 0)
	{
		if (line && !ft_strncmp(line, "Plateau ", 8))
			get_map(&f, line);
		else if (line && !ft_strncmp(line, "Piece ", 6))
		{
			get_piece(&f, line);
			which_algo(&f);
		}
		if (line)
			ft_strdel(&line);
	}
	return (0);
}
