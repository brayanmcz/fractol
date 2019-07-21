/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 01:15:58 by bcastro           #+#    #+#             */
/*   Updated: 2018/11/20 23:39:17 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*i;

	if (!lst || !(i = ft_lstnew(NULL, 0)))
		return (NULL);
	i = f(lst);
	head = i;
	while (lst->next)
	{
		lst = lst->next;
		i->next = f(lst);
		i = i->next;
	}
	return (head);
}
