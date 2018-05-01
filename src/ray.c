/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 21:19:39 by vkuksa            #+#    #+#             */
/*   Updated: 2018/03/25 21:19:41 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		init_ray(t_ray *r, t_env env)
{
	if (!(r->t = (double*)malloc(sizeof(double) * env.objcount)))
		put_error("Ray memory allocation fail");
	if (!(r->col = (t_rgb*)malloc(sizeof(t_rgb) * env.objcount)))
		put_error("Ray memory allocation fail");
	r->start = vec_cpy(env.cam.pos);
}

double		get_t(double a, double b, double d)
{
	double	t1;
	double	t2;

	t1 = (-b - sqrt(d)) / (2 * a);
	t2 = (-b + sqrt(d)) / (2 * a);
	if ((t1 <= t2 && t1 >= 0) || (t1 >= 0 && t2 < 0))
		return (t1);
	if ((t2 <= t1 && t2 >= 0) || (t2 >= 0 && t1 < 0))
		return (t2);
	return (-1);
}

int			find_closest(t_ray r, t_env env)
{
	int		id;
	int		i;

	id = -1;
	i = -1;
	while (++i < env.objcount)
	{
		if (r.t[i] >= 0 && (id == -1 || r.t[i] < r.t[id]))
			id = i;
	}
	return (id);
}

void		trace_ray(t_ray *r, t_env env)
{
	int		i;

	i = -1;
	while (++i < env.objcount)
		r->t[i] = env.obj[i].get_col(*r, &r->col[i], i, &env);
	r->id = find_closest(*r, env);
}

void		comp_ray(t_ray *r, t_vec n, double t)
{
	if (r->id == -1)
		return ;
	r->n = vec_cpy(n);
	r->end = vec_add(r->start, vec_scale(r->dir, t));
	r->rv = vec_sub(r->dir, vec_scale(r->n, 2.0 * vec_dot(r->dir, r->n)));
}
