/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 09:30:23 by brandazz          #+#    #+#             */
/*   Updated: 2013/11/25 16:35:00 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	char			*new_s;
	unsigned int	i;

	len = ft_strlen(s);
	new_s = ft_strnew(len);
	if (new_s == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (len > 0)
	{
		new_s[i] = f(i, s[i]);
		i++;
		len--;
	}
	return (new_s);
}
