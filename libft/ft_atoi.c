/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:04:21 by brandazz          #+#    #+#             */
/*   Updated: 2014/03/26 14:33:16 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_whitespace(char c)
{
	static char		*charset = " \t\n\f\v\r";
	int				i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int			ft_atoi(const char *str)
{
	char	*ptr;
	int		rep;
	int		neg;

	ptr = (char *)str;
	while (ft_whitespace(*ptr) && *ptr)
	{
		ptr++;
	}
	neg = (*ptr == '-') ? -1 : 1;
	if (*ptr == '+' || *ptr == '-')
	{
		ptr++;
	}
	rep = 0;
	while (*ptr && (*ptr >= '0' && *ptr <= '9'))
	{
		rep *= 10;
		rep += (*ptr - '0');
		ptr++;
	}
	return (rep * neg);
}
