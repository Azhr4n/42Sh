/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:40:07 by brandazz          #+#    #+#             */
/*   Updated: 2013/11/21 14:42:38 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	len;

	len = ft_strlen(s2);
	if (len == 0)
	{
		return ((char *)s1);
	}
	while (*s1)
	{
		if (ft_memcmp(s1, s2, len) == 0)
		{
			return ((char *)s1);
		}
		s1++;
	}
	return (NULL);
}
