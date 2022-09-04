/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 21:50:10 by minsukan          #+#    #+#             */
/*   Updated: 2022/07/21 16:35:58 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(long long n)
{
	int	cnt;

	cnt = 1;
	if (n < 0)
	{
		n = -n;
		cnt++;
	}
	while (n >= 10)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

static char	*ft_put(char *str, long long n, int len)
{
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n >= 10)
	{
		str[len] = (n % 10) + 48;
		n /= 10;
		len--;
	}
	str[len] = n % 10 + 48;
	return (str);
}

char	*ft_itoa(long long n)
{
	long long	len;
	char		*str;

	len = ft_count(n);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = 0;
	return (ft_put(str, n, len - 1));
}
