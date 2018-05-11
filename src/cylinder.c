/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 18:20:14 by vkuksa            #+#    #+#             */
/*   Updated: 2018/03/18 18:20:15 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libvec.h"

t_vec		vec_cylinder_n(t_ray r, double t, t_obj cylinder)
{
	double	m;
	t_vec	n;
	t_vec	p;

	m = vec_dot(r.dir, cylinder.v) * t
		+ vec_dot(vec_sub(r.start, cylinder.pos), cylinder.v);
	p = vec_add(r.start, vec_scale(r.dir, t));
	n = vec_norm(vec_sub(vec_sub(p, cylinder.pos), vec_scale(cylinder.v, m)));
	if (vec_dot(r.dir, n) > 0.0001)
		n = vec_scale(n, -1);
	return (n);
}

double		t_cylinder(t_ray *r, t_obj cylinder)
{
	t_vec	x;
	double	a;
	double	b;
	double	c;
	double	d;

	x = vec_sub(r->start, cylinder.pos);
	a = vec_dot(r->dir, cylinder.v);
	a = vec_dot(r->dir, r->dir) - a * a;
	b = 2 * (vec_dot(r->dir, x) - vec_dot(r->dir, cylinder.v)
		* vec_dot(x, cylinder.v));
	c = vec_dot(x, cylinder.v);
	c = vec_dot(x, x) - c * c - cylinder.r * cylinder.r;
	d = b * b - 4 * a * c;
	d = DROUND(d);
	return (d = d < 0 ? -1 : get_t(a, b, d));
}

double		col_cylinder(t_ray *r, t_rgb *col, int id, void *env)
{
	double	d;
	t_obj	cylinder;

	cylinder = ((t_env*)env)->obj[id];
	d = t_cylinder(r, cylinder);
	if (d > 0)
	{
		comp_ray(r, vec_cylinder_n(*r, d, cylinder), d);
		col->c = get_color(*r, id, (t_env*)env);
	}
	return (d);
}
