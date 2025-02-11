/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_send.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabourao <eabourao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 08:59:50 by eabourao          #+#    #+#             */
/*   Updated: 2025/02/11 13:14:43 by eabourao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"

int main(int ac, char **av)
{
    int l;

    l = 0;
    if (ac < 3)
        return (1);
    int i = 7;
    int h = ft_atoi(av[1]);
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
		    usleep(2000);
        }
        l++;
    }
    
   
    return (0);
}