/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:17:43 by minsukan          #+#    #+#             */
/*   Updated: 2022/07/24 12:53:53 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_mark_write(t_list *flag, int *ref)
{
	if (flag->plus == 1 && flag->negative == 0)
	{
		write(1, "+", 1);
		(*ref)++;
	}
	if (flag->negative == 1)
	{
		write(1, "-", 1);
		(*ref)++;
	}
}

void	ft_default_write(t_list *flag, int *ref)
{
	if (flag->zero == 1)
		ft_mark_write(flag, ref);
	ft_width(flag->zero, flag->width, ref);
	if (flag->plus == 1 && flag->zero == 0)
		ft_mark_write(flag, ref);
	if (flag->negative == 1 && flag->zero == 0 && flag->plus == 0)
	{
		write(1, "-", 1);
		(*ref)++;
	}
	if (flag->space == 1 && flag->negative == 0 && flag->type != 's')
	{
		write(1, " ", 1);
		(*ref)++;
	}
	if (flag->sharp == 1)
		ft_sharp_write(flag->type, ref);
	ft_precision(flag->precision, ref);
	ft_putstr(flag, ref);
}

void	ft_left_write(t_list *flag, int *ref)
{
	if (flag->space == 1 && flag->negative == 0)
	{
		write(1, " ", 1);
		(*ref)++;
	}
	if (flag->sharp == 1)
		ft_sharp_write(flag->type, ref);
	if (flag->negative == 1)
	{
		write(1, "-", 1);
		(*ref)++;
	}
	ft_precision(flag->precision, ref);
	ft_putstr(flag, ref);
	ft_width(flag->zero, flag->width, ref);
}

void	ft_putstr(t_list *flag, int *ref)
{
	int	i;

	i = 0;
	while (i < flag->len)
	{
		write(1, &flag->print[i], 1);
		i++;
		(*ref)++;
	}
}

void	ft_sharp_write(char c, int *ref)
{
	(*ref) += 2;
	if (c == 'X')
		write(1, "0X", 2);
	else
		write(1, "0x", 2);
}
