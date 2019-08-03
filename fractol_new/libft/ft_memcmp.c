/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:26:46 by bcastro           #+#    #+#             */
/*   Updated: 2018/11/20 23:39:34 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *unsigned_s1;
	unsigned char *unsigned_s2;

	unsigned_s1 = (unsigned char *)s1;
	unsigned_s2 = (unsigned char *)s2;
	while (n-- != 0)
	{
		if (*unsigned_s1 != *unsigned_s2)
			return (*unsigned_s1 - *unsigned_s2);
		unsigned_s1++;
		unsigned_s2++;
	}
	return (0);
}
