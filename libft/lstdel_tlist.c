/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdel_tlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:21:46 by mbui              #+#    #+#             */
/*   Updated: 2020/01/16 11:28:43 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*lstdel_tlist(t_list **head)
{
	t_list	*curr;
	t_list	*next;

	curr = *head;
	while (curr != NULL)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	return (*head = NULL);
}
