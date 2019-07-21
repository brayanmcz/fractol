/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:43:49 by bcastro           #+#    #+#             */
/*   Updated: 2018/11/20 23:41:07 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s1_copy;
	size_t	len;

	len = ft_strlen(s1);
	s1_copy = (char *)malloc(len + 1);
	if (!s1_copy)
		return (NULL);
	while (*s1 != '\0')
		*s1_copy++ = *s1++;
	*s1_copy = '\0';
	while (len-- > 0)
		s1_copy--;
	return (s1_copy);
}
