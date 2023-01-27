/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:15:28 by johnysavard       #+#    #+#             */
/*   Updated: 2023/01/27 16:32:37 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		ft_printf_s(char *s);
int		ft_printf_nb(uintptr_t n, int is_unsigned);
int		ft_printf_u(unsigned int n);
int		ft_printf_ptr(uintptr_t ptr);
int		ft_printf_hexa(unsigned int nb, const char type);
int		ft_ptr_len(unsigned long long nb);
int		ft_hexa_len(unsigned int nb);
int		ft_nb_len(long long nb);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(long long n, int fd);
void	ft_putnbr_u_fd(uintptr_t n, int fd);
#endif
