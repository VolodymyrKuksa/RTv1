/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 18:20:42 by vkuksa            #+#    #+#             */
/*   Updated: 2018/03/18 18:20:43 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec		vec_cone_n(t_ray r, t_vec pt, double t, t_obj cone)
{
	t_vec	n;
	double	m;

	m = vec_dot(r.dir, cone.v) * t
		+ vec_dot(vec_sub(r.start, cone.pos), cone.v);
	n = vec_scale(vec_scale(cone.v, m), (1 + cone.r * cone.r));
	n = vec_norm(vec_sub(vec_sub(pt, cone.pos), n));
	if (vec_dot(r.dir, n) > 0.0001)
		n = vec_scale(n, -1);
	return (n);
}

double		t_cone(t_ray *r, t_obj cone)
{
	t_vec	x;
	double	a;
	double	b;
	double	c;
	double	d;

	x = vec_sub(r->start, cone.pos);
	a = vec_dot(r->dir, cone.v);
	a = vec_dot(r->dir, r->dir) - (1 + cone.r * cone.r) * a * a;
	b = 2.0 * (vec_dot(r->dir, x) - (1 + cone.r * cone.r)
		* vec_dot(r->dir, cone.v) * vec_dot(x, cone.v));
	c = vec_dot(x, cone.v);
	c = vec_dot(x, x) - (1 + cone.r * cone.r) * c * c;
	d = b * b - 4 * a * c;
	return (d < 0 ? -1 : get_t(a, b, d));
}

double		col_cone(t_ray *r, t_rgb *col, int id, void *env)
{
	double	t;
	t_obj	cone;
	t_vec	pt;

	cone = ((t_env*)env)->obj[id];
	t = t_cone(r, cone);
	if (t > 0)
	{
		pt = vec_add(r->start, vec_scale(r->dir, t));
		comp_ray(r, vec_cone_n(*r, pt, t, cone), t);
		col->c = get_color(*r, id, (t_env*)env);
	}
	return (t);
}
