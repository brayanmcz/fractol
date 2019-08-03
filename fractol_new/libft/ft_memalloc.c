/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:58:59 by bcastro           #+#    #+#             */
/*   Updated: 2018/11/20 23:57:40 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char		*allocated;
	char		*temp_allocated;

	if (size > 0)
	{
		allocated = malloc(size);
		if (!allocated)
			return (NULL);
		temp_allocated = allocated;
		while (size-- > 0)
			*temp_allocated++ = 0;
		return ((void *)allocated);
	}
	else
		return (NULL);
}
