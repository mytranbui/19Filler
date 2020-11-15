/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 14:59:34 by mbui              #+#    #+#             */
/*   Updated: 2020/10/16 16:09:42 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libftprintf.h"

t_print		*init_flags(t_print *p)
{
	p->width = 0;
	p->pres = -1;
	p->flg.plus = 0;
	p->flg.minus = 0;
	p->flg.space = 0;
	p->flg.zero = 0;
	p->flg.hash = 0;
	p->flg.h = 0;
	p->flg.l = 0;
	p->flg.maj_l = 0;
	return (p);
}

t_print		*init_print(const char *format, t_print *p)
{
	if (!(p = (t_print*)ft_memalloc(sizeof(t_print))))
		return (NULL);
	p->fmt = format;
	p->ret = 0;
	return (p);
}

static int	ft_printf2(va_list ap, t_print *p, int i)
{
	va_end(ap);
	i = p->ret;
	free_print(&p, 1);
	return (i);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	t_print	*p;
	int		i;

	i = 0;
	p = NULL;
	va_start(ap, format);
	p = init_print(format, p);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			p = init_flags(p);
			i = parse(ap, p, i);
			conversion(ap, p);
		}
		else if (format[i] == '%' && !format[i + 1])
			return (i);
		else
			i += ft_putstr_len_percent(&format[i], p);
		i++;
	}
	return (ft_printf2(ap, p, i));
}
