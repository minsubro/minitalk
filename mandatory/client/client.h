/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsukan <minsukan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:38:08 by minsukan          #+#    #+#             */
/*   Updated: 2022/09/05 16:17:21 by minsukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "../ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <signal.h>

void	ft_error(void);
int		ft_atoi(char *str);
void	get_sig2(int signo);

#endif