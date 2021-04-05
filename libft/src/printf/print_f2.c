/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 12:55:33 by mbui              #+#    #+#             */
/*   Updated: 2021/04/05 10:38:34 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** last_num of str_flt = (unsigned long long)n % 10 + 48
*/

static int	roundup2(char *str_flt, int i)
{
	if (str_flt[i] == '.')
		i--;
	return (i);
}

char	*roundup(long double n, char *str_flt, int i)
{
	int		boolean;

	boolean = 0;
	n *= 10;
	while (((unsigned long long)n % 10 + 48) >= '5' && !boolean && str_flt[i])
	{
		i = roundup2(str_flt, i);
		if (str_flt[i] == '9')
			str_flt[i] = '0';
		if (i == 0 && str_flt[i] == '0')
		{
			str_flt = ft_strjoin_free("1", str_flt, 2);
			if (!str_flt)
				return (NULL);
			boolean = 1;
		}
		else
		{
			str_flt[i]++;
			boolean = 1;
		}
		i--;
	}
	return (str_flt);
}

char	*get_int(long double n, t_print *p)
{
	char	*str_int;
	char	*str_intdot;

	str_int = ft_itoa_base(n, 10, 'x');
	if (!str_int)
		return (NULL);
	str_intdot = NULL;
	if (p->pres != 0 || p->flg.hash != 0)
	{
		str_intdot = ft_strjoin_free(str_int, ".", 1);
		if (!str_intdot)
			return (NULL);
	}
	if (!str_intdot)
		return (str_int);
	return (str_intdot);
}
