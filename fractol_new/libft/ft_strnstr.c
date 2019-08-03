/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 17:34:58 by bcastro           #+#    #+#             */
/*   Updated: 2018/11/20 23:41:39 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t start;
	size_t end;

	end = 0;
	i = 0;
	start = 0;
	while (s2[end] != '\0')
		end++;
	if (end == 0)
		return ((char *)s1);
	while (s1[i] && i < len)
	{
		while (s1[i + start] == s2[start] && (i + start) < len)
		{
			if (start == end - 1)
				return ((char *)s1 + i);
			start++;
		}
		start = 0;
		i++;
	}
	return (0);
}
