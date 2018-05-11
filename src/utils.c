/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 18:01:30 by vkuksa            #+#    #+#             */
/*   Updated: 2018/03/25 18:01:32 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	free_double_string(char **sl)
{
	int	i;

	i = -1;
	while (sl[++i])
		free(sl[i]);
	free(sl);
	sl = NULL;
}

void	default_env(t_env *env)
{
	env->objcount = 0;
	env->obj = NULL;
	env->lightcount = 0;
	env->light = NULL;
	env->ambient.intensity = 0.2;
	env->ambient.col.bgra[0] = 0xff * env->ambient.intensity;
	env->ambient.col.bgra[1] = 0xff * env->ambient.intensity;
	env->ambient.col.bgra[2] = 0xff * env->ambient.intensity;
	env->cam.pos = vec_new(0, 0, 0);
	env->cam.rot = vec_new(0, 0, 0);
	env->cam.dir = vec_new(0, 0, -1);
	env->cam.updir = vec_new(0, -1, 0);
	env->cam.ldir = vec_norm(vec_cross(env->cam.dir, env->cam.updir));
	env->total_light = 0.2;
	env->refl_depth = 5;
}

void	put_error(char *str)
{
	perror(str);
	exit(1);
}

void	obj_cpy(t_obj src, t_obj *dst)
{
	dst->r = src.r;
	dst->col.c = src.col.c;
	dst->get_t = src.get_t;
	dst->get_col = src.get_col;
	dst->pos = vec_cpy(src.pos);
	dst->v = vec_cpy(src.v);
	dst->rf_rate = src.rf_rate;
}

void	light_cpy(t_light src, t_light *dst)
{
	dst->intensity = src.intensity;
	dst->col.c = src.col.c;
	dst->pos = vec_cpy(src.pos);
}
