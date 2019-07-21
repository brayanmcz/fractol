/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:49:11 by bcastro           #+#    #+#             */
/*   Updated: 2018/11/20 23:39:33 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *unsigned_s;
	unsigned char unsigned_c;

	unsigned_s = (unsigned char *)s;
	unsigned_c = (unsigned char)c;
	while (n-- != 0)
		if (*unsigned_s++ == unsigned_c)
			return ((void*)unsigned_s - 1);
	return (NULL);
}
