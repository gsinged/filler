/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 11:52:05 by gsinged           #+#    #+#             */
/*   Updated: 2019/11/29 11:52:07 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static int	fd_lf(const int fd, char **line, char **fd_b)
{
	char	*c;

	if ((c = ft_strchr(fd_b[fd], '\n')))
	{
		*line = ft_strsub(fd_b[fd], 0, (ft_strlen(fd_b[fd]) - ft_strlen(c)));
		c = ft_strsub(fd_b[fd], (ft_strlen(fd_b[fd]) - ft_strlen(c)) + 1, \
		ft_strlen(c));
		ft_strclr2star(&fd_b[fd]);
		ft_strdel(&fd_b[fd]);
		fd_b[fd] = c;
		return (1);
	}
	return (0);
}

static int	fd_ret0(const int fd, char **line, char **fd_b)
{
	if ((ft_strlen(fd_b[fd]) != 0))
	{
		*line = ft_strdup(fd_b[fd]);
		ft_strclr2star(&fd_b[fd]);
		ft_strdel(&fd_b[fd]);
		return (1);
	}
	return (0);
}

static int	fd_read(const int fd, char **line, char **fd_b)
{
	int		ret;
	char	*buf;
	char	*c;

	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		c = ft_strjoin(fd_b[fd], buf);
		ft_strclr2star(&fd_b[fd]);
		ft_strdel(&fd_b[fd]);
		fd_b[fd] = c;
		if (ft_strchr(buf, '\n'))
		{
			ft_strdel(&buf);
			return (fd_lf(fd, line, fd_b));
		}
	}
	ft_strdel(&buf);
	if (ret == 0)
		return (fd_ret0(fd, line, fd_b));
	return (-1);
}

int			get_next_line(const int fd, char **line)
{
	static char		*fd_b[10000];

	if (fd < 0 || BUFF_SIZE < 1 || fd > 10000 || !line)
		return (-1);
	if (!fd_b[fd])
	{
		if (!(fd_b[fd] = ft_strnew(0)))
			return (-1);
	}
	if (fd_lf(fd, line, fd_b))
		return (1);
	return (fd_read(fd, line, fd_b));
}
