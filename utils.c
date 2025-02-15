/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabourao <eabourao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:22:26 by eabourao          #+#    #+#             */
/*   Updated: 2025/02/14 15:23:37 by eabourao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	*ft_ws(const char *str)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	return ((char *)str);
}

int	ft_atoi(const char *str)
{
	long			n;
	long			max;
	int				s;
	char			*string;

	s = 1;
	n = 0;
	max = 0;
	string = ft_ws(str);
	if (*string == '-' || *string == '+')
		if (*string++ == '-')
			s *= -1;
	while (*string >= '0' && *string <= '9')
	{
		n = n * 10 + (*string - '0');
		if (n < max)
		{
			if (s == -1)
				return (0);
			return (-1);
		}
		string++;
		max = n;
	}
	return ((int)n * s);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		n *= -1;
		write (fd, "-", 1);
		ft_putnbr_fd (n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		n += 48;
		write(fd, &n, 1);
	}
}

int	ft_print_error(pid_t pid)
{
	if (pid < 1 || kill(pid, 0) == -1)
		return (write(1, "Invalid Pid\n", 12), 1);
	return (0);
}
