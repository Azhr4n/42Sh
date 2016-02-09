/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:01:03 by brandazz          #+#    #+#             */
/*   Updated: 2013/11/21 15:31:17 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	char	*dest;

	dest = s1;
	while (*s2 && n > 0)
	{
		*dest = *s2;
		dest++;
		s2++;
		n--;
	}
	while (n > 0)
	{
		*dest = 0;
		dest++;
		n--;
	}
	return (s1);
}
