/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:34:59 by brandazz          #+#    #+#             */
/*   Updated: 2013/11/27 17:10:19 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_whitespace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	char	*new_s;
	char	*ptr;

	new_s = ft_strnew(ft_strlen(s));
	if (new_s == NULL)
	{
		return (NULL);
	}
	while (ft_whitespace(*s))
	{
		s++;
	}
	ptr = new_s;
	while (*s)
	{
		*ptr++ = *s++;
	}
	ptr--;
	while (ptr != new_s && ft_whitespace(*ptr))
	{
		ptr--;
	}
	if (ptr != new_s)
		*(ptr + 1) = 0;
	return (new_s);
}
