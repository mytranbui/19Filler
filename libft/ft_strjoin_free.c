/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:43:22 by mbui              #+#    #+#             */
/*   Updated: 2020/11/10 16:14:30 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, int opt)
{
	char			*d;

	if (!(d = ft_strjoin(s1, s2)))
		return (NULL);
	if (opt == 1)
		ft_strdel(&s1);
	if (opt == 2)
		ft_strdel(&s2);
	if (opt == 3)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (d);
}
