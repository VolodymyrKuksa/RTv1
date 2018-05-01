/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 16:40:06 by vkuksa            #+#    #+#             */
/*   Updated: 2018/03/25 16:40:08 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include "parser.h"
#include "get_next_line.h"
#include <fcntl.h>

int		g_nbline = 0;

void	parse_error(int errnb)
{
	if (errnb == ALL_GOOD)
		return ;
	if (errnb == USAGE)
		ft_putendl("Usage: ./RTv1 [fileaname]");
	if (errnb == NO_OBJ_DATA)
		ft_putendl("No objects in the file!");
	if (errnb == NO_LIGHT_DATA)
		ft_putendl("Total light intensity equals 0 -> nothing can be seen!");
	if (errnb >= NO_OBJ_DATA)
		exit(0);
	ft_putstr("ERROR: (line ");
	ft_putnbr(g_nbline);
	if (errnb == NB_TOO_BIG)
		ft_putendl(") Wrong number format!");
	if (errnb == NOT_ENOUGH_DATA)
		ft_putendl(") Not enough data!");
	if (errnb == WRONG_CHARACTER)
		ft_putendl(") Wrong character!");
	if (errnb == WRONG_COL_FORMAT)
		ft_putendl(") Wrong color format!");
	exit(0);
}

void	parse_line(t_env *env, char **sl)
{
	if (ft_strequ(sl[0], "cam:"))
		parse_cam(&env->cam, sl);
	if (ft_strequ(sl[0], "ambient:"))
		parse_ambient(env, sl);
	if (ft_strequ(sl[0], "light:"))
		light_push_back(env, sl);
	if (ft_strequ(sl[0], "sphere:") || ft_strequ(sl[0], "cylinder:") ||
		ft_strequ(sl[0], "cone:") || ft_strequ(sl[0], "plane:"))
		obj_push_back(env, sl);
}

void	parse_input(t_env *env, char *filename)
{
	int		fd;
	char	*line;
	char	**sl;
	int		gnlret;

	default_env(env);
	if ((fd = open(filename, O_RDONLY)) < 0)
		put_error("Cannot open the file");
	while ((gnlret = get_next_line(fd, &line)))
	{
		if (gnlret < 0)
			put_error("Reading error");
		if (!(sl = ft_strsplit(line, ' ')))
			put_error("Memory allocation error");
		g_nbline++;
		parse_line(env, sl);
		free_double_string(sl);
		free(line);
	}
	close(fd);
	if (env->objcount == 0)
		parse_error(NO_OBJ_DATA);
	if (env->total_light == 0)
		parse_error(NO_LIGHT_DATA);
	env->total_light = env->total_light < 1.0 ? 1.0 : env->total_light;
}
