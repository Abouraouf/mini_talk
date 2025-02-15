/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabourao <eabourao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 08:59:50 by eabourao          #+#    #+#             */
/*   Updated: 2025/02/14 15:20:14 by eabourao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	int	l;
	int	i;
	int	h;

	i = 7;
	h = ft_atoi(av[1]);
	if (ac != 3 || ft_print_error(h))
		return (1);
	l = 0;
	while (av[2][l])
	{
		i = 7;
		while (i >= 0)
		{
			if ((av[2][l] >> i) & 1)
				kill(h, SIGUSR1);
			else
				kill(h, SIGUSR2);
			i--;
			usleep(500);
			usleep(500);
		}
		l++;
	}
	return (0);
}
