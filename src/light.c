/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 14:50:23 by vkuksa            #+#    #+#             */
/*   Updated: 2018/03/19 14:50:25 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

unsigned int	col_add(t_rgb c1, double i1, t_rgb c2, double i2)
{
	t_rgb			res;
	unsigned int	tmp;

	tmp = (unsigned)(c1.bgra[0] * i1 + c2.bgra[0] * i2);
	res.bgra[0] = (unsigned char)(tmp > 0xff ? 0xff : tmp);
	tmp = (unsigned)(c1.bgra[1] * i1 + c2.bgra[1] * i2);
	res.bgra[1] = (unsigned char)(tmp > 0xff ? 0xff : tmp);
	tmp = (unsigned)(c1.bgra[2] * i1 + c2.bgra[2] * i2);
	res.bgra[2] = (unsigned char)(tmp > 0xff ? 0xff : tmp);
	return (res.c);
}

/*
**	in_shadow:
**	if in shadow -> return -1
**	else -> return dist
*/

double			in_shadow(t_ray sr, t_vec dest, t_env env)
{
	int		i;
	double	dist;

	dist = vec_magn(vec_sub(dest, sr.start));
	i = -1;
	while (++i < env.objcount)
		sr.t[i] = env.obj[i].get_t(&sr, env.obj[i]);
	sr.id = find_closest(sr, env);
	if (sr.id < 0 || sr.t[sr.id] > dist)
		return (dist);
	return (-1);
}

unsigned int	add_shhine(t_rgb res, t_ray r, t_light light, double tl)
{
	double	ll;

	ll = vec_dot(r.rv, vec_norm(vec_sub(light.pos, r.end)));
	if (ll > 0.95)
	{
		ll = (ll - 0.95) / 0.05;
		ll = ll * ll;
		res.c = col_add(res, 1, light.col, ll / tl);
	}
	return (res.c);
}

unsigned int	get_color(t_ray r, int id, t_env *env)
{
	t_ray	sr;
	t_rgb	res;
	int		i;
	double	l;

	if (!(sr.t = (double*)malloc(sizeof(double) * env->objcount)))
		put_error("Ray memory allocation fail");
	res.c = 0;
	i = -1;
	while (++i < env->lightcount)
	{
		sr.dir = vec_norm(vec_sub(env->light[i].pos, r.end));
		sr.start = vec_add(r.end, vec_scale(sr.dir, 0.0001));
		l = vec_dot(r.n, sr.dir);
		if (l > 0 && in_shadow(sr, env->light[i].pos, *env) > 0)
		{
			res.c = col_add(res, 1, env->obj[id].col,
				l * env->light[i].intensity / env->total_light);
			res.c = add_shhine(res, r, env->light[i], env->total_light);
		}
	}
	res.c = col_add(res, 1, env->obj[id].col,
		env->ambient.intensity / env->total_light);
	free(sr.t);
	return (res.c);
}
