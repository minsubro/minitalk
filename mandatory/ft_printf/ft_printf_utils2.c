/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:51:45 by minsukan          #+#    #+#             */
/*   Updated: 2022/09/03 21:09:09 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi2(char **str, t_list *flag)
{
	long long	ref;

	if (*(*str) == '.')
	{
		(*str)++;
		flag->pre_flag = 1;
	}
	ref = 0;
	while (*(*str) >= '0' && *(*str) <= '9')
	{
		ref = ref * 10 + (*(*str) - 48);
		(*str)++;
	}
	return (ref);
}
