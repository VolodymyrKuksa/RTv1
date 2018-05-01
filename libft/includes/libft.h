/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuksa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:35:27 by vkuksa            #+#    #+#             */
/*   Updated: 2017/11/10 15:12:31 by vkuksa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** arr - pointer to a 2d array that represents
** a matrix of i rows and j columns
*/

typedef struct		s_matrix
{
	int		i;
	int		j;
	double	**arr;
}					t_matrix;

t_matrix			ft_mat_scalar_add(t_matrix m, double nb);
t_matrix			ft_mat_scalar_div(t_matrix m, double nb);
t_matrix			ft_mat_scalar_mult(t_matrix m, double nb);
t_matrix			*ft_new_matrix(int i, int j);
t_matrix			*ft_mat_mult(t_matrix *a, t_matrix *b, int fr);
void				ft_clear_matrix(t_matrix **m);

double				ft_atod(char *s);
char				*ft_itoa_base(int value, int base);
int					ft_atoi_base(const char *str, int str_base);
void				ft_sort_str_tab(char **tab);
void				ft_sort_int_tab(int *tab, unsigned int size);
void				ft_swap(int *a, int *b);
void				ft_brainfuck(char *bf);
void				print_list(t_list *bl);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr(int	n);
void				ft_putnbr_fd(int	n, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
char				*ft_itoa(int n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				**ft_strsplit(char const *s, char c);
int					ft_toupper(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_tolower(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_atoi(const char *str);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strdup(char *str);
char				*ft_strcpy(char *dst, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *h, const char *n, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *s1, const char *s2, size_t distance);

#endif
