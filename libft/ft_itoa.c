/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:01:21 by bcastro           #+#    #+#             */
/*   Updated: 2018/11/20 23:38:19 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	ft_dtoc(int n)
{
	if (n >= 0 && n <= 9)
		return (n + '0');
	return (n);
}

static	int		ft_newstr_size(int n)
{
	size_t len;

	len = 0;
	if (n == -2147483648)
		return (12);
	if (n <= 0)
	{
		len = 2;
		n = n * -1;
	}
	else
		len = 1;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char		*ft_last_resort(char *str)
{
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str_num;
	int		len;

	len = ft_newstr_size(n);
	str_num = ft_strnew(len);
	if (!str_num)
		return (NULL);
	if (n == -2147483648)
		return (ft_last_resort(str_num));
	if (n < 0)
	{
		str_num[0] = '-';
		n = n * -1;
	}
	if (n == 0)
		str_num[0] = '0';
	while (n > 0)
	{
		str_num[--len - 1] = ft_dtoc(n % 10);
		n = n / 10;
	}
	return (str_num);
}
