/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 11:23:40 by brandazz          #+#    #+#             */
/*   Updated: 2014/02/24 11:24:21 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		count_char(const char *str, char c)
{
	int		i;

	i = 0;
	while (*str)
	{
		if (*str == c)
			i++;
		str++;
	}
	return (i);
}
