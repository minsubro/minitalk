/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:21:40 by minsukan          #+#    #+#             */
/*   Updated: 2022/09/03 21:09:58 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_check(char **format, t_list *new, int first)
{
	while (*(*format))
	{
		if (**format == '0' && first == 0)
		{
			new->zero = 1;
			(*format)++;
		}
		if (**format >= '0' && **format <= '9')
			new->width = ft_atoi2(format, new);
		if (**format == '.')
			new->precision = ft_atoi2(format, new);
		if (**format == '-')
			new->left = 1;
		if (**format == '#')
			new->sharp = 1;
		if (**format == ' ')
			new->space = 1;
		if (**format == '+')
			new->plus = 1;
		if (type_check(*(*format), new))
			break ;
		(*format)++;
		first = 1;
	}
}

int	type_check(char c, t_list *new)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || \
			c == 'u' || c == 'x' || c == 'X' || c == '%')
		new->type = ft_find(c);
	return (new->type);
}

char	ft_find(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || \
			c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (c);
	else
		return (0);
}
