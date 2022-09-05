/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_memory_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 19:58:19 by minsukan          #+#    #+#             */
/*   Updated: 2022/07/23 12:41:25 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_create_lst(void)
{
	t_list	*new;

	new = (t_list *)ft_calloc2(sizeof(t_list), 1);
	if (!new)
		return (NULL);
	return (new);
}

void	*ft_calloc2(size_t count, size_t size)
{
	void	*temp;

	temp = (void *)malloc(count * size);
	if (!temp)
		return (NULL);
	ft_memset(temp, 0, count * size);
	return (temp);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*temp;

	i = 0;
	temp = (unsigned char *)b;
	while (i < len)
	{
		temp[i++] = (unsigned char)c;
	}
	return (b);
}

void	ft_lst_free(t_list **lst)
{
	free((*lst)->print);
	free((*lst));
}
