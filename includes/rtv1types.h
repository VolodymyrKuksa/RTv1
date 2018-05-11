/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 10:04:01 by vkuksa            #+#    #+#             */
/*   Updated: 2018/03/15 10:04:03 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1TYPES_H
# define RTV1TYPES_H

# include "libvec.h"
# include "SDL.h"

typedef union		u_rgb
{
	unsigned int	c;
	unsigned char	bgra[4];
}					t_rgb;

typedef struct		s_cam
{
	t_vec			pos;
	t_vec			dir;
	t_vec			updir;
	t_vec			rot;
	t_vec			ldir;
}					t_cam;

typedef struct		s_ray
{
	t_vec			start;
	t_vec			dir;
	double			*t;
	t_rgb			col;
	int				id;
	t_vec			end;
	t_vec			n;
	t_vec			rv;
}					t_ray;

typedef struct		s_obj
{
	t_vec			pos;
	t_vec			v;
	t_rgb			col;
	double			r;
	double			(*get_col)(t_ray*, t_rgb*, int, void *);
	double			(*get_t)(t_ray*, struct s_obj);
}					t_obj;

typedef struct		s_light
{
	t_vec			pos;
	double			intensity;
	t_rgb			col;
}					t_light;

typedef struct		s_env
{
	SDL_Window		*wnd;
	int				*pixels;
	SDL_Renderer	*rend;
	t_cam			cam;
	int				objcount;
	t_obj			*obj;
	int				lightcount;
	t_light			*light;
	t_light			ambient;
	double			total_light;
}					t_env;

typedef struct		s_thread_data
{
	t_env			env;
	int				*pixels;
	int				start_row;
}					t_thread_data;

#endif
