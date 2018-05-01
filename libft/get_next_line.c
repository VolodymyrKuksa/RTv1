/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 13:04:56 by vkuksa            #+#    #+#             */
/*   Updated: 2018/01/28 15:36:56 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

t_fd_list	*new_fd_elem(int fd)
{
	t_fd_list	*new;

	if (!(new = (t_fd_list*)malloc(sizeof(t_fd_list))))
		return (NULL);
	new->fd = fd;
	new->read[0] = '\0';
	new->ls = new->read;
	new->next = NULL;
	return (new);
}

int			read_line(t_fd_list *ptr, char **line)
{
	int		nbread;
	char	*tmp;

	nbread = 1;
	ptr->ls = NULL;
	while (!ptr->ls && nbread)
	{
		nbread = read(ptr->fd, ptr->read, BUFF_SIZE);
		ptr->read[nbread] = '\0';
		if (nbread == -1)
			return (-1);
		if ((ptr->ls = ft_memchr(ptr->read, '\n', nbread)))
			*((ptr->ls)++) = '\0';
		tmp = *line;
		*line = ft_strjoin(*line, ptr->read);
		free(tmp);
		if (!(*line))
			return (-1);
	}
	if (!ft_strlen(*line) && !nbread)
	{
		free(*line);
		return (0);
	}
	return (1);
}

int			give_line(t_fd_list *ptr, char **line)
{
	char			*p;
	unsigned int	len;

	len = ft_strlen(ptr->ls);
	if (!((*line) = ft_strnew(len)))
		return (-1);
	p = ft_memccpy(*line, ptr->ls, '\n', len);
	if (!p)
		return (read_line(ptr, line));
	*(p - 1) = '\0';
	ptr->ls++;
	while (*(ptr->ls) && *(ptr->ls - 1) != '\n')
		ptr->ls++;
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_fd_list	*bl = NULL;
	t_fd_list			*ptr;

	if (read(fd, NULL, 0) != 0 || !line || BUFF_SIZE < 1)
		return (-1);
	*line = NULL;
	if (!bl && !(bl = new_fd_elem(fd)))
		return (-1);
	ptr = bl;
	while (ptr->next && ptr->fd != fd)
		ptr = ptr->next;
	if (ptr->fd != fd)
	{
		if (!(ptr->next = new_fd_elem(fd)))
			return (-1);
		ptr = ptr->next;
	}
	if (!(ptr->ls))
		return (0);
	return (give_line(ptr, line));
}
