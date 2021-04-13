/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:41:38 by mbui              #+#    #+#             */
/*   Updated: 2021/04/02 15:08:31 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*get_flt2(long double n, char *str_int, char *str_dec)
{
	char	*str_flt;

	str_flt = ft_strjoin_free(str_int, str_dec, 3);
	if (!str_flt)
		return (NULL);
	str_flt = roundup(n, str_flt, ft_strlen(str_flt) - 1);
	return (str_flt);
}

static char	*get_flt(long double n, t_print *p)
{
	char	*str_int;
	char	*str_dec;
	int		dec;
	int		i;

	i = 0;
	if (p->pres == -1)
		p->pres = 6;
	str_int = get_int(n, p);
	if (!str_int)
		return (NULL);
	str_dec = ft_strnew(p->pres + 1);
	if (!str_dec)
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
	return (get_flt2(n, str_int, str_dec));
}

static void	print_f3(long double arg, int len, int bigger_len, t_print *p)
{
	char	*str_flt;

	str_flt = get_flt(ft_ldabs(arg), p);
	if (!str_flt)
		return ;
	putsign(arg, p);
	padding_zero(len, p);
	print_result(str_flt, 0, p);
	padding_space(bigger_len, p);
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

void	print_f(long double arg, t_print *p)
{
	int		len;
	int		bigger_len;
	char	*str_flt;

	str_flt = get_flt(ft_ldabs(arg), p);
	if (!str_flt)
		return ;
	len = ft_strlen(str_flt);
	bigger_len = ft_max(len, p->pres);
	if (arg < 0 || (p->flg.plus && arg >= 0))
	{
		len++;
		bigger_len++;
	}
	if (p->flg.plus == 0 && arg >= 0)
		len++;
	if (p->flg.space && p->flg.plus == 0 && arg >= 0)
		bigger_len++;
	print_f2(arg, len, bigger_len, p);
	if (!p->flg.minus)
		print_result(str_flt, 0, p);
	else
		print_f3(arg, len, bigger_len, p);
	ft_strdel(&str_flt);
}
