/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:25:39 by bcastro           #+#    #+#             */
/*   Updated: 2018/11/21 00:01:54 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*temp_str;
	char	*str;

	str = NULL;
	if (s && f)
	{
		temp_str = ft_strnew(ft_strlen(s));
		if (!temp_str)
			return (NULL);
		str = temp_str;
		while (*s != '\0')
			*temp_str++ = (*f)(*s++);
	}
	return (str);
}
