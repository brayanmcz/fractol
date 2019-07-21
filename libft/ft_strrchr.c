/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 12:44:03 by bcastro           #+#    #+#             */
/*   Updated: 2018/11/20 23:41:41 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *begin;

	begin = (char *)s;
	while (*s)
		s++;
	if (c == '\0')
		return ((char*)s);
	s--;
	while (*s != c && *s && (s != begin))
		s--;
	if (*s == c)
		return ((char*)s);
	else
		return (NULL);
}
