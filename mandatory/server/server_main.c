/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:10:54 by minsukan          #+#    #+#             */
/*   Updated: 2022/09/04 18:36:28 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sever.h"

void	get_sig1(int i)
{
	ft_printf("sig1");
}

void	get_sig2(int i)
{
	ft_printf("sig2");
}

int main()
{
	//char	*str;
	//char	c;
	//int cnt;

	ft_printf("%d\n", getpid());
	while (1)
	{
		signal(10, 1);
		signal(12, 0);
		pause();
	}
	
}