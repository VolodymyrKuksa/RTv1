/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:20:33 by vkuksa            #+#    #+#             */
/*   Updated: 2017/12/05 10:20:35 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 100000

int						get_next_line(const int fd, char **line);

typedef struct			s_fd_list
{
	int					fd;
	char				read[BUFF_SIZE + 1];
	char				*ls;
	struct s_fd_list	*next;
}						t_fd_list;

#endif
