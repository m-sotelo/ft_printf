/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:43:20 by msotelo-          #+#    #+#             */
/*   Updated: 2021/10/27 19:11:56 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
char	*ft_subitoa(int i, long n, int sign, char *res);
char	*ft_itoa_len(long n);
int		print_char(char c, int res);
int		print_string(char *str, int res);
int		print_decimal(int i, int res);
int		ft_choose_print(va_list args, char c, int res);
int		ft_printf(const char *str, ...);
int		print_u_decimal(unsigned int i, int res);
int		print_h(unsigned long i, int res, char *type, int cast);
int		print_pointer(void *str, int res, char *type);
#endif
