/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 16:44:54 by vkuksa            #+#    #+#             */
/*   Updated: 2018/03/25 16:44:55 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

enum	e_nberr
{
	ALL_GOOD,
	NB_TOO_BIG,
	NOT_ENOUGH_DATA,
	WRONG_CHARACTER,
	WRONG_COL_FORMAT,
	NO_OBJ_DATA,
	NO_LIGHT_DATA,
	USAGE
};

int		is_valid_vec(char *str);
int		is_valid_nb(char *str);
int		is_valid_hex(char *str);

int		get_double(double *res, char *str);
int		get_vec_data(t_vec *res, char *str);
int		get_col_data(t_rgb *res, char *str);
void	parse_error(int errnb);
void	parse_input(t_env *env, char *filename);

void	default_env(t_env *env);

void	parse_rf_depth(t_env *env, char **sl);
void	parse_cam(t_cam *cam, char **sl);
void	parse_ambient(t_env *env, char **sl);
void	parse_light(t_light *light, char **sl);
void	light_push_back(t_env *env, char **sl);
void	parse_obj(t_obj *obj, char **sl);
void	obj_push_back(t_env *env, char **sl);

void	obj_cpy(t_obj src, t_obj *dst);
void	light_cpy(t_light src, t_light *dst);

#endif
