/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:53:40 by brandazz          #+#    #+#             */
/*   Updated: 2013/11/29 09:56:06 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	len;

	len = ft_strlen(s2);
	if (len == 0)
	{
		return ((char *)s1);
	}
	if (len <= n)
	{
		while (*s1 && n > 0)
		{
			if (ft_memcmp(s1, s2, len) == 0 && n >= len)
			{
				return ((char *)s1);
			}
			s1++;
			n--;
		}
	}
	return (NULL);
}
