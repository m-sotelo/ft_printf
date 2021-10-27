/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:22:20 by msotelo-          #+#    #+#             */
/*   Updated: 2021/10/27 19:12:13 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_string(char *str, int res)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		res = res + 6;
		return (res);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
		res++;
	}
	return (res);
}

int	print_decimal(int i, int res)
{
	char	*output;
	int		j;

	j = 0;
	output = NULL;
	if (i == -2147483648)
	{
		write (1, "-2147483648", 11);
		res = res + 11;
		return (res);
	}
	output = ft_itoa_len(i);
	while (output[j] != '\0')
	{
		write(1, &output[j], 1);
		res++;
		j++;
	}
	free(output);
	return (res);
}

int	print_u_decimal(unsigned int i, int res)
{
	char	*output;
	int		j;
	long	k;

	k = i;
	j = 0;
	output = NULL;
	output = ft_itoa_len(k);
	while (output[j] != '\0')
	{
		write(1, &output[j], 1);
		res++;
		j++;
	}
	free(output);
	return (res);
}

int	print_h(unsigned long i, int res, char *type, int cast)
{
	char			*aux;
	char			*output;
	unsigned long	k;
	int				x;

	k = 0;
	x = 0;
	output = (char *)malloc(sizeof(char) * 16);
	aux = type;
	if (cast == 1)
		i = (unsigned int)i;
	while ((i / 16) > 0)
	{
		k = i % 16;
		i = i / 16;
		output[x++] = aux[k];
		res++;
	}
	output[x] = aux[i];
	x++;
	while (x-- > 0)
		write(1, &output[x], 1);
	free(output);
	res++;
	return (res);
}

int	print_pointer(void *str, int res, char *type)
{
	unsigned long	i;

	i = (unsigned long)str;
	if (!str)
	{
		write(1, "0x0", 3);
		res = res + 3;
		return (res);
	}
	write(1, "0x", 2);
	res = res + 2;
	res = print_h(i, res, type, 0);
	return (res);
}
