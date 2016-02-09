/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:54:20 by brandazz          #+#    #+#             */
/*   Updated: 2013/11/21 13:01:44 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char	*ucs1;
	unsigned char	*ucs2;

	if (s2 < s1)
	{
		ucs1 = (unsigned char *)s1 + n - 1;
		ucs2 = (unsigned char *)s2 + n - 1;
		while (n > 0)
		{
			*ucs1-- = *ucs2--;
			n--;
		}
		return (s1);
	}
	return (ft_memcpy(s1, s2, n));
}
