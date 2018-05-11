/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:16:03 by vkuksa            #+#    #+#             */
/*   Updated: 2018/03/12 15:16:53 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "rtv1types.h"

# define WNDW		1080
# define WNDW_H		540
# define WNDH		720
# define WNDH_H		360
# define FOV		60.0
# define FOV_H		30
# define PPD		935

# define ABS(x)		(x) > 0 ? (x) : -(x)
# define DROUND(d)	ABS(d) < 0.00001 ? 0 : (d)

double			t_sphere(t_ray *r, t_obj sphere);
double			col_sphere(t_ray *r, t_rgb *col, int id, void *env);

double			t_cylinder(t_ray *r, t_obj cylinder);
double			col_cylinder(t_ray *r, t_rgb *col, int id, void *env);

double			t_plane(t_ray *r, t_obj plane);
double			col_plane(t_ray *r, t_rgb *col, int id, void *env);

double			t_cone(t_ray *r, t_obj ccone);
double			col_cone(t_ray *r, t_rgb *col, int id, void *env);

double			get_t(double a, double b, double d);
unsigned int	get_color(t_ray r, int id, t_env *env);
unsigned int	col_add(t_rgb c1, double i1, t_rgb c2, double i2);

unsigned int	trace_ray(t_ray *r, t_env env);
unsigned int	refl_col(t_ray r, t_env env, int depth);
void			init_ray(t_ray *r, t_env env);
int				find_closest(t_ray r, t_env env);
void			comp_ray(t_ray *r, t_vec n, double t);

void			put_error(char *str);
void			free_double_string(char **sl);

#endif
