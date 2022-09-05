/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:10:54 by minsukan          #+#    #+#             */
/*   Updated: 2022/09/05 17:09:53 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>

int	g_c;

void	get_sig1(int signo)
{
	(void)signo;
	g_c += 1;
}

void	get_sig2(int signo)
{
	(void)signo;
	g_c += 0;
}

int	get_client_pid(void)
{
	int	ref;
	int	i;

	i = 0;
	while (i < 32)
	{
		g_c <<= 1;
		pause();
		i++;
	}
	ref = g_c;
	g_c = 0;
	return (ref);
}

int	main(void)
{
	int	cnt;
	int	client_pid;

	cnt = 0;
	signal(10, get_sig1);
	signal(12, get_sig2);
	ft_printf("%d\n", getpid());
	while (1)
	{	
		g_c <<= 1;
		pause();
		cnt++;
		if (cnt == 8)
		{
			if (g_c == 0)
			{
				client_pid = get_client_pid();
				kill(client_pid, 12);
				ft_printf("\n");
			}
			ft_printf("%c", g_c);
			g_c = 0;
			cnt = 0;
		}
	}
}
