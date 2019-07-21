/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 18:12:27 by bcastro           #+#    #+#             */
/*   Updated: 2018/11/20 23:41:24 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t end;

	i = 0;
	j = 0;
	if (size <= ft_strlen(dst))
		return (ft_strlen(src) + size);
	while (dst[i] && i < size)
		i++;
	end = i;
	while (src[j] && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (end < size)
		dst[i] = '\0';
	return (end + ft_strlen(src));
}
