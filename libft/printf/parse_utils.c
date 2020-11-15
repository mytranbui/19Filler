/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 19:37:05 by mbui              #+#    #+#             */
/*   Updated: 2020/10/20 19:37:29 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libftprintf.h"

int		isflag(char c)
{
	return (c == '+' || c == '-' || c == ' ' || c == '#' || c == '0');
}

int		istype(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o'
			|| c == 'u' || c == 'x' || c == 'X' || c == 'f' || c == '%');
}

int		issize(char c)
{
	return (c == 'h' || c == 'l' || c == 'L');
}

int		validtype(t_print *p, int i)
{
	while (p->fmt[i])
	{
		if (istype(p->fmt[i]))
			return (1);
		i++;
	}
	return (0);
}
