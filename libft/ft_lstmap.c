/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:15:20 by mbui              #+#    #+#             */
/*   Updated: 2019/04/27 12:00:05 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *tmp;

	if (!lst || !f)
		return (NULL);
	if ((new = ft_lstnew(f(lst)->content, f(lst)->content_size)) != NULL)
	{
		tmp = new;
		lst = lst->next;
		while (lst)
		{
			if (!(tmp->next = ft_lstnew(f(lst)->content, f(lst)->content_size)))
				return (NULL);
			tmp = tmp->next;
			lst = lst->next;
		}
		free(tmp);
	}
	return (new);
}
