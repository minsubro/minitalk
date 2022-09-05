/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:29:47 by minsukan          #+#    #+#             */
/*   Updated: 2022/09/05 16:25:05 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

int	ft_atoi(char *str)
{
	long long	ref;
	int			i;

	i = 0;
	ref = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			ft_error();
		str++;
	}
	while (str[i])
	{
		if (ref > INT_MAX || ref < INT_MIN)
			ft_error();
		ref = ref * 10 + (str[i] - '0');
		i++;
	}
	if (i == 0)
		ft_error();
	return (ref);
}

void	ft_error(void)
{
	write(2, "error\n", 6);
	exit(1);
}

void	get_sig2(int signo)
{
	(void)signo;
	ft_printf("Successful sending of message\n");
	exit(0);
}
