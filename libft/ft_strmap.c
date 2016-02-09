/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 09:02:08 by brandazz          #+#    #+#             */
/*   Updated: 2013/11/25 16:34:35 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	char	*new_s;
	size_t	i;

	len = ft_strlen(s);
	new_s = ft_strnew(len);
	if (new_s == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		new_s[i] = f(s[i]);
		i++;
	}
	return (new_s);
}
