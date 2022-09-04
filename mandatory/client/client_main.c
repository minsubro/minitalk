/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:30:26 by minsukan          #+#    #+#             */
/*   Updated: 2022/09/03 19:57:38 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	ft_error(void)
{
	write(2, "error\n", 6);
	exit(1);
}

void	send_sig1(int pid)
{
	if(kill(pid, 10))
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
	while (str[i])
	{
		j = 1;
		while (j <= 8)
		{
			if (str[i] & j)
				send_sig1(pid);
			else
				send_sig2(pid);
			j++;
		}
		i++;
	}
}

int main(int ac, char **av)
{
	int		pid;
	char	*str;
	
	if (ac != 3)
		ft_error();
	pid = ft_atoi(av[1]);
	str = av[2];
	//printf("%d\n%s", pid, str);
	send_sig(pid, str);
}