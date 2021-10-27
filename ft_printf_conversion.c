/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:43:20 by msotelo-          #+#    #+#             */
/*   Updated: 2021/10/27 19:03:45 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	*ft_subitoa(int i, long n, int sign, char *res)
{
	int		j;

	j = i;
	if (!res)
		return (NULL);
	if (sign == -1)
		res[0] = '-';
	while (n > 9)
	{
		res[i] = ((n % 10) + '0');
		n = n / 10;
		i--;
	}
	res[i] = (n + '0');
	res[j + 1] = '\0';
	return (res);
}

char	*ft_itoa_len(long n)
{
	int		i;
	long	j;
	int		sign;
	char	*res;

	sign = 1;
	i = 0;
	j = n;
	if (n < 0)
	{
		sign = -1;
		j = n * -1;
		n = n * -1;
		i++;
	}
	while (j >= 10)
	{
		j = j / 10;
		i++;
	}
	res = (char *)malloc(sizeof (char) * (i + 1));
	res = ft_subitoa(i, n, sign, res);
	return (res);
}
