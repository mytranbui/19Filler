/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:22:40 by mbui              #+#    #+#             */
/*   Updated: 2020/11/06 18:30:50 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libftprintf.h"

/*
** For diouxX
** h	>>	short (unsigned) int
** hh	>>	(unsigned) char
** l	>>	long (unsigned) int
** ll	>>	long long (unsigned) int
** For f
** l	>>	no diff with printf but with scanf it's a double
** L	>>	long (unsigned) double
*/

intmax_t	convert_arg_di(va_list ap, t_print *p)
{
	intmax_t	arg;

	arg = 0;
	if (p->type == 'd' || p->type == 'i')
	{
		if (p->flg.h == 1)
			arg = (short int)va_arg(ap, int);
		else if (p->flg.h == 2)
			arg = (char)va_arg(ap, int);
		else if (p->flg.l == 1)
			arg = (long int)va_arg(ap, long int);
		else if (p->flg.l == 2)
			arg = (long long int)va_arg(ap, long long int);
		else
			arg = (int)va_arg(ap, int);
	}
	return (arg);
}

long double	convert_arg_f(va_list ap, t_print *p)
{
	long double	arg;

	arg = 0;
	if (p->type == 'f')
	{
		if (p->flg.maj_l == 1)
			arg = (long double)va_arg(ap, long double);
		else
			arg = (double)va_arg(ap, double);
	}
	return (arg);
}

uintmax_t	convert_arg_oux(va_list ap, t_print *p)
{
	uintmax_t	arg;

	arg = 0;
	if (p->type == 'o' || p->type == 'u' || p->type == 'x' || p->type == 'X')
	{
		if (p->flg.h == 1)
			arg = (unsigned short int)va_arg(ap, unsigned int);
		else if (p->flg.h == 2)
			arg = (unsigned char)va_arg(ap, unsigned int);
		else if (p->flg.l == 1)
			arg = (unsigned long int)va_arg(ap, unsigned long int);
		else if (p->flg.l == 2)
			arg = (unsigned long long int)va_arg(ap, unsigned long long int);
		else
			arg = va_arg(ap, unsigned int);
	}
	return (arg);
}

void		print_(t_print *p)
{
	padding_ze_sp(0, p);
}

void		conversion(va_list ap, t_print *p)
{
	if (p->type == 'c')
		print_c(ap, p);
	else if (p->type == 's')
		print_s(ap, p);
	else if (p->type == 'p')
		print_p(ap, p);
	else if (p->type == 'd' || p->type == 'i')
		print_di(convert_arg_di(ap, p), p);
	else if (p->type == 'o')
		print_o(convert_arg_oux(ap, p), p);
	else if (p->type == 'u')
		print_u(convert_arg_oux(ap, p), p);
	else if (p->type == 'x' || p->type == 'X')
		print_x(convert_arg_oux(ap, p), p);
	else if (p->type == 'f')
		print_f(convert_arg_f(ap, p), p);
	else if (p->type == '%')
		print_percent(p);
	else
		print_(p);
}
