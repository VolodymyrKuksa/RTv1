/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 18:20:02 by vkuksa            #+#    #+#             */
/*   Updated: 2018/03/18 18:20:04 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libvec.h"

t_vec		vec_sphere_n(t_ray r, double d, t_vec cent)
{
	t_vec	n;

	n = vec_add(r.start, vec_scale(r.dir, d));
	n = vec_norm(vec_sub(n, cent));
	if (vec_dot(r.dir, n) > 0.0001)
		n = vec_scale(n, -1);
	return (n);
}

double		t_sphere(t_ray *r, t_obj sphere)
{
	double	a;
	double	b;
	double	c;
	double	d;

	a = vec_dot(r->dir, r->dir);
	b = 2 * vec_dot(r->dir, vec_sub(r->start, sphere.pos));
	c = vec_dot(vec_sub(r->start, sphere.pos),
		vec_sub(r->start, sphere.pos)) - sphere.r * sphere.r;
	d = b * b - 4 * a * c;
	d = DROUND(d);
	return (d < 0 ? -1 : get_t(a, b, d));
}

double		col_sphere(t_ray r, t_rgb *col, int id, void *env)
{
	double	t;
	t_obj	sphere;

	sphere = ((t_env*)env)->obj[id];
	t = t_sphere(&r, sphere);
	if (t > 0)
	{
		comp_ray(&r, vec_sphere_n(r, t, sphere.pos), t);
		col->c = get_color(r, id, (t_env*)env);
	}
	return (t);
}
