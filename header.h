/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabourao <eabourao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:18:24 by eabourao          #+#    #+#             */
/*   Updated: 2025/02/13 20:27:48 by eabourao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define _POSIX_C_SOURCE 200809L
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_atoi(const char *str);
int		ft_printf(const char *str, ...);
int		ft_putchar_fd(char c, int fd);
int		ft_putnbr(int n);
int		ft_putstr_fd(char *s, int fd);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);
int		ft_unsigned(unsigned int n);
char	*ft_strdup(const char *s1);
int		ft_printhex(unsigned int n, char format);
int		ft_printptr(unsigned long n);


#endif