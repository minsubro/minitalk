/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:08:46 by minsukan          #+#    #+#             */
/*   Updated: 2022/07/24 14:28:09 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*type_s(char *s)
{
	if (s == NULL)
		return (ft_strdup("(null)"));
	else
		return (ft_strdup(s));
}

char	*type_u(t_list *flag, unsigned int num)
{
	if (flag->pre_flag == 1 && flag->precision == 0 && num == 0)
		return (ft_strdup(""));
	else
		return (ft_itoa(num));
}
