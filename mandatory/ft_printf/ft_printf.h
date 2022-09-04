/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:16:19 by minsukan          #+#    #+#             */
/*   Updated: 2022/09/03 21:09:17 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char		type;
	int			width;
	int			left;
	int			pre_flag;
	int			precision;
	int			zero;
	int			plus;
	int			space;
	int			sharp;
	int			len;
	int			negative;
	char		*print;
}				t_list;

char	*type_di(t_list *flag, long long num);
char	*type_c(int c);
char	*type_u(t_list *flag, unsigned int num);
char	*type_x(t_list *flag, unsigned int num);
char	*type_s(char *s);
int		ft_cnt(unsigned long long num);
int		ft_strlen(char *s);
void	ft_putstr(t_list *flag, int *ref);
void	ft_lst_free(t_list **lst);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc2(size_t count, size_t size); ///
char	*ft_itoa(long long n);
int		ft_atoi2(char **str, t_list *flag);
char	*ft_strdup(char *s1);
void	to_hex(char *str, char *base, unsigned int num);
void	to_hex_adr(char *str, unsigned long long num);
t_list	*ft_create_lst(void);
t_list	*ft_check(char **format);
char	*type_percent(void);
char	*type_p(t_list *flag, unsigned long long num);
char	ft_find(char c);
int		type_check(char c, t_list *new);
void	flag_check(char **format, t_list *new, int first);
char	*make_str(t_list *flag, va_list *ap);
int		ft_write(t_list *flag, int *ref);
void	ft_mark_write(t_list *flag, int *ref);
void	ft_left_write(t_list *flag, int *ref);
void	ft_default_write(t_list *flag, int *ref);
void	ft_sharp_write(char c, int *ref);
void	ft_precision(int len, int *ref);
void	ft_width(int flag, int len, int *ref);
void	ft_flag_setting(t_list *flag);
void	ft_len_set(t_list *flag);
void	ft_width_set(t_list *flag);
int		ft_printf(const char *format, ...);

#endif