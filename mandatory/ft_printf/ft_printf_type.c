/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:04:47 by minsukan          #+#    #+#             */
/*   Updated: 2022/07/24 13:00:28 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*type_di(t_list *flag, long long num)
{
	if (flag->pre_flag == 1 && flag->precision == 0 && num == 0)
		return (ft_strdup(""));
	if (num < 0)
	{
		num = -num;
		flag->negative = 1;
	}
	return (ft_itoa(num));
}

char	*type_c(int c)
{
	char	*s;

	s = ft_calloc2(1, 2);
	if (!s)
		return (NULL);
	s[0] = c;
	return ((char *)s);
}

char	*type_percent(void)
{
	unsigned char	*s;

	s = ft_calloc2(1, 2);
	s[0] = '%';
	return ((char *)s);
}

char	*type_x(t_list *flag, unsigned int num)
{
	int				cnt;
	char			*hex;

	if (flag->pre_flag == 1 && flag->precision == 0 && num == 0)
		return (ft_strdup(""));
	if (num == 0)
		flag->sharp = 0;
	cnt = ft_cnt(num);
	hex = (char *)ft_calloc2(cnt + 1, 1);
	if (flag->type == 'x')
		to_hex(hex + cnt - 1, "0123456789abcdef", num);
	else
		to_hex(hex + cnt - 1, "0123456789ABCDEF", num);
	return (hex);
}

char	*type_p(t_list *flag, unsigned long long num)
{
	char				*adress;
	int					cnt;

	flag->sharp = 1;
	cnt = ft_cnt(num);
	adress = (char *)ft_calloc2(cnt + 1, 1);
	if (!adress)
		return (NULL);
	to_hex_adr(adress + cnt - 1, num);
	return (adress);
}
