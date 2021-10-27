/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 21:23:09 by msotelo-          #+#    #+#             */
/*   Updated: 2021/10/27 19:01:00 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_char(char c, int res)
{
	write(1, &c, 1);
	res++;
	return (res);
}

int	ft_choose_print(va_list args, char	c, int res)
{
	if (c == 'c')
		res = print_char(va_arg(args, int), res);
	else if (c == 's')
		res = print_string(va_arg(args, char *), res);
	else if (c == 'p')
		res = print_pointer(va_arg(args, void *), res, "0123456789abcdef");
	else if (c == 'd')
		res = print_decimal(va_arg(args, int), res);
	else if (c == 'i')
		res = print_decimal(va_arg(args, int), res);
	else if (c == 'u')
		res = print_u_decimal(va_arg(args, unsigned int), res);
	else if (c == 'x')
		res = print_h(va_arg(args, unsigned long), res, "0123456789abcdef", 1);
	else if (c == 'X')
		res = print_h(va_arg(args, unsigned long), res, "0123456789ABCDEF", 1);
	else if (c == '%')
	{
		write (1, "%", 1);
		res++;
	}
	return (res);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		res;
	va_list	args;

	i = 0;
	res = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			res = ft_choose_print(args, str[i + 1], res);
			i = i + 2;
		}
		else
		{
			write (1, &str[i], 1);
			res++;
			i++;
		}
	}
	va_end(args);
	return (res);
}

/*int	main()
{
	int	i;
	int	j;
	int	test;
//	char *str;
	
	i = 0;
	test = 42;
//	str = (char *)malloc(sizeof(char) * 57);
	i = ft_printf("[hola como estas %p ]", (void *)-1);
	j = printf("[hola como estas %p ]", (void *)-1);
	printf("\nesto es res:%i,%i",i,j);
//	free(str);
}*/
