/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:30:26 by minsukan          #+#    #+#             */
/*   Updated: 2022/09/06 19:14:44 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	send_sig1(int pid)
{
	if (kill(pid, 10))
		ft_error();
}

void	send_sig2(int pid)
{
	if (kill(pid, 12))
		ft_error();
}

void	send_sig(int pid, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (1)
	{
		j = 128;
		while (j > 0)
		{
			if (str[i] & j)
				send_sig1(pid);
			else
				send_sig2(pid);
			usleep(1000);
			j >>= 1;
		}
		if (str[i] == 0)
			break ;
		i++;
	}
}

void	send_my_pid(int pid, int mypid)
{
	long long	i;

	i = 2147483648;
	while (i > 0)
	{
		if (mypid & i)
			send_sig1(pid);
		else
			send_sig2(pid);
		usleep(1000);
		i >>= 1;
	}
}

int	main(int ac, char **av)
{	
	int		pid;
	int		my_pid;
	char	*str;

	my_pid = getpid();
	signal(12, get_sig2);
	if (ac != 3)
		ft_error();
	pid = ft_atoi(av[1]);
	str = av[2];
	send_sig(pid, str);
	send_my_pid(pid, my_pid);
	pause();
}
