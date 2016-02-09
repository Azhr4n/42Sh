/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:25:30 by brandazz          #+#    #+#             */
/*   Updated: 2013/11/21 16:29:12 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*buffer;

	buffer = (void *)malloc(size);
	if (buffer == NULL)
	{
		return (NULL);
	}
	ft_bzero(buffer, size);
	return (buffer);
}
