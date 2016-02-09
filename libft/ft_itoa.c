/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 09:27:11 by brandazz          #+#    #+#             */
/*   Updated: 2013/11/28 12:00:50 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t			ft_nb_digits(int n)
{
	size_t	nb_digits;

	if (n != 0)
	{
		nb_digits = 0;
		while (n != 0)
		{
			n /= 10;
			nb_digits++;
		}
		return (nb_digits);
	}
	return (1);
}

static unsigned int		ft_ten_power(int power)
{
	unsigned int	n;

	n = 1;
	if (power == 0)
	{
		return (n);
	}
	while (power > 0)
	{
		n *= 10;
		power--;
	}
	return (n);
}

static int				ft_abs_digit(int n)
{
	n %= 10;
	if (n < 0)
	{
		return (-n);
	}
	return (n);
}

static void				ft_get_digits(char *str, int n, size_t nb_digits)
{
	size_t	i;
	int		ten_power;
	int		tmp;

	if (n == 0)
	{
		str[0] = '0';
		return ;
	}
	i = 0;
	if (n < 0)
	{
		str[0] = '-';
		i++;
	}
	while (--nb_digits > 0)
	{
		ten_power = ft_ten_power(nb_digits);
		tmp = ft_abs_digit(n / ten_power);
		tmp %= 10;
		str[i++] = tmp + '0';
	}
	str[i] = ft_abs_digit((n % 10)) + '0';
}

char					*ft_itoa(int n)
{
	size_t	nb_digits;
	size_t	size;
	char	*str;

	nb_digits = ft_nb_digits(n);
	size = nb_digits;
	if (n < 0)
	{
		size++;
	}
	str = ft_strnew(size);
	if (str == NULL)
	{
		return (NULL);
	}
	ft_get_digits(str, n, nb_digits);
	return (str);
}
