/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 15:23:06 by bcastro           #+#    #+#             */
/*   Updated: 2018/11/20 23:41:49 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int start;
	int end;

	end = 0;
	i = 0;
	start = 0;
	while (s2[end] != '\0')
		end++;
	if (end == 0)
		return ((char *)s1);
	while (s1[i])
	{
		while (s1[i + start] == s2[start])
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
