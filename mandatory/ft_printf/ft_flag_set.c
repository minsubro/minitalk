/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:53:17 by minsukan          #+#    #+#             */
/*   Updated: 2022/07/24 12:58:48 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_len_set(t_list *flag)
{
	if (flag->type == 'c')
		flag->len = 1;
	else
		flag->len = ft_strlen(flag->print);
	if (flag->pre_flag == 1 && flag->type == 's')
	{
		if (flag->len >= flag->precision)
			flag->len = flag->precision;
		flag->precision = 0;
	}
}

void	ft_width_set(t_list *flag)
{
	flag->width -= flag->len;
	if (flag->sharp == 1)
		flag->width -= 2;
	if (flag->negative == 1 || flag->space == 1 || flag->plus == 1)
		flag->width -= 1;
}

void	ft_flag_setting(t_list *flag)
{
	if (flag->pre_flag == 1)
		flag->zero = 0;
	ft_len_set(flag);
	if (flag->type == '%')
		flag->space = 0;
	if (flag->plus == 1 && flag->precision > 0)
		flag->zero = 0;
	ft_width_set(flag);
	flag->precision -= flag->len;
	if (flag->precision >= 0 && flag->pre_flag == 1)
		flag->width -= flag->precision;
}

void	ft_precision(int len, int *ref)
{
	int	i;

	i = 0;
	while (i < len)
	{
		write(1, "0", 1);
		i++;
		(*ref)++;
	}
}

void	ft_width(int flag, int len, int *ref)
{
	int		i;
	char	s;

	i = 0;
	if (flag)
		s = '0';
	else
		s = ' ';
	while (i < len)
	{
		write(1, &s, 1);
		i++;
		(*ref)++;
	}
}
