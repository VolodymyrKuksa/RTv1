/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 10:37:10 by vkuksa            #+#    #+#             */
/*   Updated: 2018/05/02 20:56:21 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include "parser.h"
#include <pthread.h>

void		init_sdl(t_env *env)
{
	if (SDL_Init(SDL_INIT_VIDEO) >= 0)
		if ((env->wnd = SDL_CreateWindow("RTv1", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WNDW, WNDH, SDL_WINDOW_SHOWN)))
			if ((env->rend = SDL_CreateRenderer(env->wnd, -1,
			SDL_RENDERER_ACCELERATED)))
				return ;
	ft_putendl(SDL_GetError());
	exit(1);
}

void		*render_quater(void *data)
{
	t_ray			r;
	t_vec			ppc;
	int				i;
	int				j;
	t_thread_data	*td;

	td = (t_thread_data*)data;
	ppc = vec_add(td->env.cam.pos, vec_scale(td->env.cam.dir, PPD));
	init_ray(&r, td->env);
	i = td->start_row - 1;
	while (++i < (td->start_row + WNDH / 4))
	{
		j = -1;
		while (++j < WNDW)
		{
			r.dir = vec_sub(ppc, vec_scale(td->env.cam.ldir, (j - WNDW_H)));
			r.dir = vec_add(r.dir, vec_scale(td->env.cam.updir, (i - WNDH_H)));
			r.dir = vec_norm(vec_sub(r.dir, r.start));
			trace_ray(&r, td->env);
			(td->pixels)[i * WNDW + j] = (r.id != -1 ? r.col[r.id].c : 0);
		}
	}
	free(r.t);
	free(r.col);
	pthread_exit(0);
}

void		paralel_render(t_env env, int **pixels)
{
	int				i;
	pthread_t		tid[4];
	t_thread_data	td[4];

	i = -1;
	while (++i < 4)
	{
		td[i].env = env;
		td[i].pixels = *pixels;
		td[i].start_row = WNDH / 4 * i;
		pthread_create(&tid[i], NULL, render_quater, &td[i]);
	}
	while (--i >= 0)
		pthread_join(tid[i], NULL);
}

void		update_wnd(t_env env)
{
	int		i;
	int		j;
	t_rgb	col;

	i = -1;
	while (++i < WNDH)
	{
		j = -1;
		while (++j < WNDW)
		{
			col.c = env.pixels[i * WNDW + j];
			SDL_SetRenderDrawColor(env.rend, col.bgra[2], col.bgra[1],
				col.bgra[0], col.bgra[3]);
			SDL_RenderDrawPoint(env.rend, j, i);
		}
	}
	SDL_RenderPresent(env.rend);
}

int			main(int ac, char **av)
{
	SDL_Event	e;
	t_env		env;

	if (ac != 2)
		parse_error(USAGE);
	parse_input(&env, av[1]);
	printf("x: %f, y: %f, z: %f\n", env.cam.pos.x, env.cam.pos.y, env.cam.pos.z);
	ft_putendl("Loading...");
	env.pixels = malloc(sizeof(int) * WNDW * WNDH);
	paralel_render(env, &env.pixels);
	ft_putendl("Loaded!");
	init_sdl(&env);
	update_wnd(env);
	while (1)
		while (SDL_PollEvent(&e))
			if (e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && e.key.keysym.sym
				== SDLK_ESCAPE))
				exit(0);
	return (0);
}
