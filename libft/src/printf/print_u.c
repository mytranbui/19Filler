/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 21:01:57 by mbui              #+#    #+#             */
/*   Updated: 2021/04/02 16:47:32 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** %u: undefined behavior with// '+', ' ', '#' ('#' has no effect)
*/

static void	print_u_if(char *s, t_print *p, int pres)
{
	if (*s == '0' && !pres)
		p->width++;
}

void	print_u(uintmax_t arg, t_print *p)
{
	char	*s;
	int		len;
	int		bigger_len;
	int		tmp_pres;

	s = ft_utoa_base(arg, 10, 'x');
	if (!s)
		free_print(&p, 2);
	len = ft_strlen(s);
	tmp_pres = p->pres;
	bigger_len = ft_max(len, p->pres);
	print_u_if(s, p, tmp_pres);
	if (!p->flg.minus)
	{
		padding_ze_sp(bigger_len, p);
		padding_zero(len, p);
		print_result(s, tmp_pres, p);
	}
	else
	{
		padding_zero(len, p);
		print_result(s, tmp_pres, p);
		padding_space(bigger_len, p);
	}
	ft_strdel(&s);
}
