/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 19:51:14 by vkuksa            #+#    #+#             */
/*   Updated: 2018/03/25 19:51:16 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include "parser.h"

void	parse_func(t_obj *obj, char *name)
{
	if (ft_strequ(name, "sphere:"))
	{
		obj->get_col = &col_sphere;
		obj->get_t = &t_sphere;
	}
	if (ft_strequ(name, "cylinder:"))
	{
		obj->get_col = &col_cylinder;
		obj->get_t = &t_cylinder;
	}
	if (ft_strequ(name, "cone:"))
	{
		obj->get_col = &col_cone;
		obj->get_t = &t_cone;
	}
	if (ft_strequ(name, "plane:"))
	{
		obj->get_col = &col_plane;
		obj->get_t = &t_plane;
	}
}

void	parse_obj(t_obj *obj, char **sl)
{
	t_vec	rot;

	parse_func(obj, sl[0]);
	if (!sl[1])
		parse_error(NOT_ENOUGH_DATA);
	parse_error(get_vec_data(&obj->pos, sl[1]));
	if (!sl[2])
		parse_error(NOT_ENOUGH_DATA);
	parse_error(get_vec_data(&rot, sl[2]));
	obj->v = vec_rot_xyz(vec_new(0, 1, 0), rot);
	if (!sl[3])
		parse_error(NOT_ENOUGH_DATA);
	parse_error(get_col_data(&obj->col, sl[3]));
	if (!sl[4] && !ft_strequ(sl[0], "plane:"))
		parse_error(NOT_ENOUGH_DATA);
	if (ft_strequ(sl[0], "sphere:") || ft_strequ(sl[0], "cylinder:") ||
	ft_strequ(sl[0], "cone:"))
	{
		parse_error(get_double(&obj->r, sl[4]));
		obj->r = obj->r > 999999 ? 999999 : obj->r;
	}
	if (ft_strequ(sl[0], "cone:"))
		obj->r = tan(DTR(obj->r));
}

void	obj_push_back(t_env *env, char **sl)
{
	t_obj	obj;
	t_obj	*tmp;
	int		i;

	parse_obj(&obj, sl);
	tmp = env->obj;
	if (!(env->obj = (t_obj*)malloc(sizeof(t_obj) * (env->objcount + 1))))
		put_error("Object memory allocation fail");
	i = -1;
	while (++i < env->objcount)
		obj_cpy(tmp[i], &env->obj[i]);
	obj_cpy(obj, &env->obj[i]);
	env->objcount += 1;
	free(tmp);
}
