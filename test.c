/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabourao <eabourao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:37:57 by eabourao          #+#    #+#             */
/*   Updated: 2025/02/11 13:11:55 by eabourao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"

void	handle_it(int sig)
{
	static char	c;
	static int	bit_count;

	if (sig == SIGUSR1)
		c = (c << 1) | 1;
	else if (sig == SIGUSR2)
		c = (c << 1) | 0;
	bit_count++;
	if (bit_count == 8)
	{
		write(1, &c, 1);
		c = 0;
		bit_count = 0;
	}
}



int	main()
{
	struct sigaction sa;
	sa.sa_handler = handle_it;
	sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    sigaction(SIGALRM, &sa, NULL);
	printf("%d\n", getpid());
	while (1)
		sleep(1);
}
