/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 14:20:00 by mbui              #+#    #+#             */
/*   Updated: 2021/04/05 14:53:19 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	get_line2(const int fd, char **stack, char **line)
{
	*line = ft_strdup(stack[fd]);
	if (!*line)
		return (-1);
	ft_strdel(&stack[fd]);
	return (1);
}

static int	get_line(const int fd, char **stack, char **line)
{
	char	*tmp;
	size_t	i;

	i = 0;
	while (stack[fd][i] != '\n' && stack[fd][i])
		i++;
	if (stack[fd][i] == '\n')
	{
		*line = ft_strndup(stack[fd], i);
		if (!*line)
			return (-1);
		tmp = ft_strsub(stack[fd], i + 1, ft_strlen(stack[fd]));
		if (!tmp)
			return (-1);
		free(stack[fd]);
		stack[fd] = tmp;
		if (stack[fd][0] == '\0')
			ft_strdel(&stack[fd]);
	}
	else
		get_line2(fd, stack, line);
	return (1);
}

static char	*read_file2(const int fd, char *buf, char **stack)
{
	char	*tmp;

	if (!stack[fd])
	{
		stack[fd] = ft_strdup(buf);
		if (!stack[fd])
			return (NULL);
	}
	else if (stack[fd])
	{
		tmp = stack[fd];
		stack[fd] = ft_strjoin(tmp, buf);
		if (!stack[fd])
			return (NULL);
		ft_strdel(&tmp);
	}
	return (stack[fd]);
}

static int	read_file(const int fd, char *buf, char **stack)
{
	int		ret;

	ret = read(fd, buf, BUFF_SIZE);
	while (ret > 0)
	{
		buf[ret] = '\0';
		stack[fd] = read_file2(fd, buf, stack);
		if (!stack[fd])
			return (-1);
		if (ft_strchr(stack[fd], '\n'))
			break ;
		ret = read(fd, buf, BUFF_SIZE);
	}
	return (ret);
}

int	get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*stack[OPEN_MAX];
	int			ret;

	if (!line || fd < 0 || fd > OPEN_MAX || read(fd, stack[fd], 0) < 0)
		return (-1);
	ret = read_file(fd, buf, stack);
	if (ret < 0)
		return (-1);
	else if (stack[fd])
		get_line(fd, stack, line);
	else if (ret == 0 && stack[fd] == NULL)
	{
		*line = NULL;
		return (0);
	}
	return (1);
}
