/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 16:22:46 by bcastro           #+#    #+#             */
/*   Updated: 2018/11/20 23:40:04 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *unsigned_b;
	unsigned char unsigned_c;

	unsigned_b = b;
	unsigned_c = (unsigned char)c;
	while (len-- > 0)
		*unsigned_b++ = unsigned_c;
	return (b);
}
