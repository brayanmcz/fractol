/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:30:37 by bcastro           #+#    #+#             */
/*   Updated: 2018/11/21 00:02:13 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*temp_str;
	char	*str;
	int		i;

	str = NULL;
	i = 0;
	if (s && f)
	{
		temp_str = ft_strnew(ft_strlen(s));
		if (!temp_str)
			return (NULL);
		str = temp_str;
		while (*s != '\0')
			*temp_str++ = (*f)(i++, *s++);
	}
	return (str);
}
