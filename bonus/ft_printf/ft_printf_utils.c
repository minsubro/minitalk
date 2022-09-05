/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:14:31 by minsukan          #+#    #+#             */
/*   Updated: 2022/07/23 12:42:38 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_cnt(unsigned long long num)
{
	int	cnt;

	cnt = 1;
	while (num >= 16)
	{
		num /= 16;
		cnt ++;
	}
	return (cnt);
}

void	to_hex_adr(char *str, unsigned long long num)
{
	const char	*base = "0123456789abcdef";

	while (num >= 16)
	{
		*str = base[num % 16];
		num /= 16;
		str--;
	}
	*str = base[num % 16];
}

void	to_hex(char *str, char *base, unsigned int num)
{
	while (num >= 16)
	{
		*str = base[num % 16];
		num /= 16;
		str--;
	}
	*str = base[num % 16];
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	int		len;
	int		i;
	char	*temp;

	len = ft_strlen(s1);
	temp = (char *)ft_calloc2(len + 1, 1);
	i = 0;
	if (temp == NULL)
		return (NULL);
	while (s1[i])
	{
		temp[i] = s1[i];
		i++;
	}
	temp[i] = 0;
	return (temp);
}
