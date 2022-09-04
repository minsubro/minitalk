/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:43:12 by minsukan          #+#    #+#             */
/*   Updated: 2022/08/03 17:25:07 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_check(char **format)
{
	t_list	*new;

	new = ft_create_lst();
	if (!new)
		return (NULL);
	flag_check(format, new, 0);
	return (new);
}

char	*make_str(t_list *flag, va_list *ap)
{
	if (flag->type == 'd' || flag->type == 'i')
		return (type_di(flag, va_arg(*ap, int)));
	else if (flag->type == 'u')
		return (type_u(flag, va_arg(*ap, unsigned int)));
	else if (flag->type == 'c')
		return (type_c(va_arg(*ap, int)));
	else if (flag->type == '%')
		return (type_percent());
	else if (flag->type == 'x' || flag->type == 'X')
		return (type_x(flag, va_arg(*ap, unsigned int)));
	else if (flag->type == 'p')
		return (type_p(flag, va_arg(*ap, unsigned long long)));
	else if (flag->type == 's')
		return (type_s(va_arg(*ap, char *)));
	return (NULL);
}

int	ft_write(t_list *flag, int *ref)
{
	long long	sum;

	sum = 0;
	ft_flag_setting(flag);
	sum += flag->len + *ref;
	if (flag->precision >= 0)
		sum += flag->precision;
	if (flag->width >= 0)
		sum += flag->width;
	if (sum >= 2147483647)
		return (-1);
	if (flag->left == 1)
		ft_left_write(flag, ref);
	else
		ft_default_write(flag, ref);
	return (0);
}

int	ft_make_type(va_list *ap, char **str, int *ref)
{
	t_list	*flag;

	flag = ft_check(str);
	if (!flag)
		return (-1);
	flag->print = make_str(flag, ap);
	if (!(flag->print))
	{
		ft_lst_free(&flag);
		return (-1);
	}
	if (ft_write(flag, ref) == -1)
	{
		ft_lst_free(&flag);
		return (-1);
	}
	ft_lst_free(&flag);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*str;
	int			ref;

	str = (char *)format;
	va_start(ap, format);
	ref = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (ft_make_type(&ap, &str, &ref) == -1)
				return (-1);
		}
		else
		{
			write(1, str, 1);
			ref++;
		}
		str++;
	}
	va_end(ap);
	return (ref);
}
