/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:31:17 by brandazz          #+#    #+#             */
/*   Updated: 2013/11/20 11:33:56 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(s);
	ptr = (char *)s;
	ptr += len;
	len++;
	while (len > 0)
	{
		if (*ptr == (char)c)
		{
			return (ptr);
		}
		ptr--;
		len--;
	}
	return (NULL);
}
