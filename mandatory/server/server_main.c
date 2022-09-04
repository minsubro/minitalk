/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:10:54 by minsukan          #+#    #+#             */
/*   Updated: 2022/09/04 16:26:58 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sever.h"

int	get_sig1(char *c)
{ㅣ
	
}

int main()
{
	char	*str;
	char	c;
	int cnt;

	ft_printf("%d\n", getpid());
	while (1)
	{
		signal(10, get_sig1(&c));
		
	}
	
}