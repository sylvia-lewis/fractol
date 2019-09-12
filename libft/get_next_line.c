/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylewis <sylewis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:16:20 by sylewis           #+#    #+#             */
/*   Updated: 2019/05/06 19:09:59 by sylewis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_list_push_back(t_gnl **begin_list, t_gnl *elem)
{
	t_gnl			*tmp;

	tmp = *begin_list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = elem;
	elem->next = NULL;
}

t_gnl				*ft_create_link(int fd)
{
	t_gnl			*tmp;

	if (!(tmp = (t_gnl*)malloc(sizeof(*tmp))))
		return (NULL);
	tmp->fd = fd;
	tmp->tmp = ft_strnew(0);
	tmp->line = NULL;
	tmp->next = NULL;
	return (tmp);
}

t_gnl				*ft_get_fd(t_gnl *begin_list, int fd)
{
	t_gnl			*tmp;
	t_gnl			*tmp2;

	tmp = begin_list;
	tmp2 = NULL;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		if (tmp->next == NULL)
		{
			tmp2 = ft_create_link(fd);
			ft_list_push_back(&tmp, tmp2);
			return (tmp2);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

int					ft_line_end(char *remain, char **line)
{
	char			*pt;

	pt = NULL;
	if (!remain)
		return (0);
	pt = ft_strchr(remain, '\n');
	if (pt != NULL)
	{
		*pt = '\0';
		*line = ft_strdup(remain);
		ft_strncpy(remain, &pt[1], ft_strlen(&pt[1]) + 1);
		return (1);
	}
	else if (remain[0] != '\0')
	{
		*line = ft_strdup(remain);
		ft_strclr(remain);
		return (1);
	}
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	int				ret;
	static t_gnl	*remain;
	t_gnl			*tmp;
	char			buf[BUFF_SIZE + 1];

	if (fd < 0 || line == NULL)
		return (-1);
	if (remain == NULL)
		remain = ft_create_link(fd);
	tmp = ft_get_fd(remain, fd);
	while (!(ft_strchr(tmp->tmp, '\n')))
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		if (ret == 0)
			return (ft_line_end(tmp->line, line));
		buf[ret] = '\0';
		tmp->line = ft_strjoin(tmp->tmp, buf);
		free(tmp->tmp);
		tmp->tmp = tmp->line;
	}
	return (ft_line_end(tmp->line, line));
}
