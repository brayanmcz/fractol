/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:08:26 by bcastro           #+#    #+#             */
/*   Updated: 2018/11/20 23:40:02 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*char_dst;
	const char	*char_src;

	i = 0;
	char_dst = (char*)dest;
	char_src = (char*)src;
	if (char_dst > char_src)
		while ((int)n-- > 0)
			char_dst[n] = char_src[n];
	else
		while (n > i)
		{
			char_dst[i] = char_src[i];
			i++;
		}
	return ((void*)dest);
}
