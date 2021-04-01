/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:22:10 by mbui              #+#    #+#             */
/*   Updated: 2021/03/29 10:22:57 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void	init_filler(t_filler *f)
{
	assign_pt(&f->me.init, -1, -1);
	assign_pt(&f->opp.init, -1, -1);
	f->nb_piece = 0;
}

int		main(void)
{
	t_filler	f;
	char		*line;
	int	i;
	int k;

	k = 0;
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "\n\n----------MAIN START----------\n");
	fclose(ID);
	i = 0;
	line = NULL;
	init_filler(&f);
	if (!(get_player(&f)))
		return (-1);
	ID = fopen("debugi.txt", "a");
	fprintf(ID, "ME=%c & OP=%c\n", f.me.let, f.opp.let);
	fclose(ID);
	while (get_next_line(0, &line) > 0)
	{
		ID = fopen("debugi.txt", "a");
		fprintf(ID, "MAIN WHILE START line [%s]\n", line);
		fclose(ID);
		if (line && !ft_strncmp(line, "Plateau ", 8))
		{
			get_map(&f, line);
			ID = fopen("debugi.txt", "a");
			fprintf(ID, "MAP : H=%d & W=%d\n", f.map.height, f.map.width);
			fclose(ID);
		}
		else if (line && !ft_strncmp(line, "Piece ", 6))
		{
			get_piece(&f, line);
			ID = fopen("debugi.txt", "a");
			fprintf(ID, "PIECE%d : H=%d & W=%d\n", k++, f.piece.height, f.piece.width);
		fprintf(ID, "INITme: x = %d  y = %d\n", f.me.init.x, f.me.init.y);
		fprintf(ID, "INITop: x = %d  y = %d\n", f.opp.init.x, f.opp.init.y);
		fclose(ID);
			which_algo(&f);
		}
		ID = fopen("debugi.txt", "a");
		fprintf(ID, "MAIN WHILE END line%d [%s]\n", i++, line);
		fclose(ID);
		if (line)
			ft_strdel(&line);
	}
	return (0);
}