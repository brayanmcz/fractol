/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 21:19:04 by bcastro           #+#    #+#             */
/*   Updated: 2018/11/20 23:41:53 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		len;
	char	*new;

	if (!s)
		return (0);
	i = -1;
	j = 0;
	len = ft_strlen(s);
	while ((s[len - 1] == ' ' || s[len - 1] == '\t' ||
				s[len - 1] == '\n') && len > 1)
		len--;
	while (s[++i] == ' ' || s[i] == '\t' || s[i] == '\n')
		len--;
	if (len < 0)
		len = 0;
	if (!(new = (char *)malloc(sizeof(char) * (len) + 1)))
		return (0);
	while (j < len)
		new[j++] = s[i++];
	new[j] = '\0';
	return (new);
}
