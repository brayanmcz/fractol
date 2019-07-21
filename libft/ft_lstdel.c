/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 00:16:07 by bcastro           #+#    #+#             */
/*   Updated: 2018/11/20 23:39:03 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*c;
	t_list	*n;

	c = *alst;
	while (c)
	{
		n = c->next;
		del((c->content), (c->content_size));
		free(c);
		c = n;
	}
	*alst = NULL;
}
