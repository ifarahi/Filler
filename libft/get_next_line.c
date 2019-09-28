/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifarahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 23:07:18 by ifarahi           #+#    #+#             */
/*   Updated: 2019/09/28 23:07:19 by ifarahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_findln(int fd, char **buf, char **line)
{
	char		*new_line;
	char		*tmp;

	while ((new_line = ft_strchr(buf[fd], '\n')))
	{
		tmp = buf[fd];
		*new_line = '\0';
		*line = ft_strsub(buf[fd], 0, new_line - buf[fd]);
		buf[fd] = ft_strdup(new_line + 1);
		free(tmp);
		return (1);
	}
	while (*buf[fd])
	{
		*line = ft_strnew(ft_strlen(buf[fd]));
		ft_strcpy(*line, buf[fd]);
		buf[fd] = ft_memalloc(BUFF_SIZE + 1);
		return (1);
	}
	return (0);
}

static	int	ft_read(int fd, char **buffer)
{
	char		*temp;
	int			i;

	temp = ft_strnew(BUFF_SIZE);
	while ((i = read(fd, temp, BUFF_SIZE)) > 0)
	{
		if (!buffer[fd])
		{
			buffer[fd] = ft_strnew(ft_strlen(temp));
			ft_strcpy(buffer[fd], temp);
		}
		else
			buffer[fd] = ft_strjoin(buffer[fd], temp);
		if (ft_strchr(buffer[fd], '\n'))
			break ;
		ft_memset(temp, 0, BUFF_SIZE);
	}
	free(temp);
	return (i);
}

int			get_next_line(const int fd, char **line)
{
	static	char	*buf[4086];

	if (!line || fd < 0 || BUFF_SIZE < 0 || (ft_read(fd, &buf[fd]) < 0) ||
fd > 4086)
		return (-1);
	if (ft_findln(fd, &buf[fd], line) == 1)
		return (1);
	return (0);
}
