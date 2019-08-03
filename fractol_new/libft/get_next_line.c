/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastro <bcastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:03:38 by bcastro           #+#    #+#             */
/*   Updated: 2019/05/08 17:47:57 by bcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		insert_to_line(int fd, char **str, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	while (str[fd][i] != '\n' && str[fd][i] != '\0')
		i++;
	if (str[fd][i] == '\n')
	{
		*line = ft_strsub(str[fd], 0, i);
		tmp = ft_strdup(&str[fd][i + 1]);
		free(str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][i] == '\0')
	{
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int				get_next_line(int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	static char	*str[9999];
	int			len;

	if (fd < 0 || !line)
		return (-1);
	while ((len = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[len] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(len);
		tmp = ft_strjoin(str[fd], buff);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (len < 0)
		return (-1);
	else if (len == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	return (insert_to_line(fd, str, line));
}
