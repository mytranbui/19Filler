/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:15:20 by mbui              #+#    #+#             */
/*   Updated: 2021/04/02 13:42:28 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	new = ft_lstnew(f(lst)->content, f(lst)->content_size);
	if (new != NULL)
	{
		tmp = new;
		lst = lst->next;
		while (lst)
		{
			tmp->next = ft_lstnew(f(lst)->content, f(lst)->content_size);
			if (!tmp->next)
				return (NULL);
			tmp = tmp->next;
			lst = lst->next;
		}
		free(tmp);
	}
	return (new);
}
