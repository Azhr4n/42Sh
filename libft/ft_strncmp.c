/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:46:30 by brandazz          #+#    #+#             */
/*   Updated: 2013/12/02 14:26:50 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	ret;

	if (n == 0)
	{
		return (0);
	}
	n--;
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && n > 0)
	{
		i++;
		n--;
	}
	ret = s1[i] - s2[i];
	ret = (ret < 0) ? -1 : ret;
	ret = (ret > 0) ? 1 : ret;
	return (ret);
}
