/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:41:38 by mbui              #+#    #+#             */
/*   Updated: 2020/11/10 16:44:44 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libftprintf.h"

/*
** last_num of str_flt = (unsigned long long)n % 10 + 48
*/

static char	*roundup(long double n, char *str_flt, int i)
{
	int		boolean;

	boolean = 0;
	n *= 10;
	while (((unsigned long long)n % 10 + 48) >= '5' && !boolean && str_flt[i])
	{
		(str_flt[i] == '.') ? i-- : i;
		if (str_flt[i] == '9')
		{
			str_flt[i] = '0';
			if (i == 0)
			{
				if (!(str_flt = ft_strjoin_free("1", str_flt, 2)))
					return (NULL);
				boolean = 1;
			}
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

static char	*get_int(long double n, t_print *p)
{
	char	*str_int;
	char	*str_intdot;

	if (!(str_int = ft_itoa_base(n, 10, 'x')))
		return (NULL);
	str_intdot = NULL;
	if (p->pres != 0 || p->flg.hash != 0)
		if (!(str_intdot = ft_strjoin_free(str_int, ".", 1)))
			return (NULL);
	return (!str_intdot ? str_int : str_intdot);
}

static char	*get_flt(long double n, t_print *p)
{
	char	*str_int;
	char	*str_dec;
	char	*str_flt;
	int		dec;
	int		i;

	i = 0;
	(p->pres == -1) ? p->pres = 6 : p->pres;
	if (!(str_int = get_int(n, p)))
		return (NULL);
	if (!(str_dec = ft_strnew(p->pres + 1)))
		return (0);
	while (p->pres > 0)
	{
		n *= 10;
		dec = (unsigned long long)n;
		n -= dec;
		str_dec[i] = dec % 10 + 48;
		i++;
		p->pres--;
	}
	if (!(str_flt = ft_strjoin_free(str_int, str_dec, 3)))
		return (NULL);
	str_flt = roundup(n, str_flt, ft_strlen(str_flt) - 1);
	return (str_flt);
}

static void	print_f2(long double arg, int len, int bigger_len, t_print *p)
{
	if (p->flg.space && !p->flg.plus && arg >= 0)
	{
		ft_putchar(' ');
		p->ret++;
	}
	if (!p->flg.minus)
	{
		if (p->flg.zero)
			putsign(arg, p);
		padding_ze_sp(bigger_len, p);
		if (!p->flg.zero)
			putsign(arg, p);
		padding_zero(len, p);
	}
}

void		print_f(long double arg, t_print *p)
{
	int		len;
	int		bigger_len;
	char	*str_flt;

	str_flt = get_flt(ft_ldabs(arg), p);
	len = ft_strlen(str_flt);
	bigger_len = ft_max(len, p->pres);
	(arg < 0 || (p->flg.plus && arg >= 0)) ? len++ && bigger_len++ : len;
	(p->flg.plus == 0 && arg >= 0) ? len++ : len;
	(p->flg.space && p->flg.plus == 0 && arg >= 0) ? bigger_len++ : bigger_len;
	print_f2(arg, len, bigger_len, p);
	if (!p->flg.minus)
		print_result(str_flt, 0, p);
	else
	{
		putsign(arg, p);
		padding_zero(len, p);
		print_result(str_flt, 0, p);
		padding_space(bigger_len, p);
	}
	ft_strdel(&str_flt);
}
