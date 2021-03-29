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
	assign_pt(&f->res, 0, 0);
}

int main(void)
{
	t_filler f;
	char *line;
	int	i;
	int k;

	k = 0;
	FILE *ID = fopen("debugi.txt", "a");
	fprintf(ID, "\n\n----------MAIN START----------\n");
	fclose(ID);
	line = NULL;
	i = 0;
	//ft_bzero(&f, sizeof(t_filler));
	init_filler(&f);
	if (!(get_player(&f)))
		return (-1);
	while (get_next_line(0, &line) > 0)
	{
		ID = fopen("debugi.txt", "a");
		fprintf(ID, "MAIN WHILE START line [%s]\n", line);
		fclose(ID);
		if (line && !ft_strncmp(line, "Plateau ", 8))
		{
			init_object(&f.map); // necessary ?
			get_map(&f, line);
			//ft_strdel(&line);
		}
		else if (line && !ft_strncmp(line, "Piece ", 6))
		{
			init_object(&f.piece); // needed?
			ID = fopen("debugi.txt", "a");
			fprintf(ID, "PIECE%d\n", k++);
			fclose(ID);
			get_piece(&f, line);
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

//free all utils
