/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 10:35:42 by brandazz          #+#    #+#             */
/*   Updated: 2014/03/17 20:13:26 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "libft.h"

static char		*my_realloc(char *old, size_t old_size, size_t new_size)
{
	char	*new;

	new = (char *)malloc(sizeof(*new) * new_size);
	if (!new)
		return (NULL);
	ft_memcpy(new, old, old_size);
	free(old);
	return (new);
}

static int		get_next_char(int const fd, char *c)
{
	static char		buff[BUFF_SIZE + 1];
	static char		*head = NULL;
	static ssize_t	ret;

	if (head == NULL || (++head - buff) >= ret)
	{
		head = buff;
		ft_bzero(buff, BUFF_SIZE);
		ret = read(fd, buff, BUFF_SIZE);
		if (ret < 0)
			ft_bzero(buff, BUFF_SIZE);
	}
	*c = *head;
	return (ret);
}

static int		enlarge_line(char **line, size_t line_size, char **ptr)
{
	*line = my_realloc(*line, line_size, line_size + BUFF_SIZE + 1);
	if (!*line)
	{
		free(*line);
		return (-1);
	}
	*ptr = *line + line_size;
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	char		c;
	char		*ptr;
	size_t		line_size;
	ssize_t		ret;

	*line = (char *)malloc(sizeof(**line) * (BUFF_SIZE + 1));
	if (*line == NULL)
		return (-1);
	ptr = *line;
	line_size = 0;
	while ((ret = get_next_char(fd, &c)) > 0 && c != '\n')
	{
		*ptr = c;
		ptr++;
		line_size++;
		if (line_size % (BUFF_SIZE + 1) == 0)
		{
			if (enlarge_line(line, line_size, &ptr) < 0)
				return (-1);
		}
	}
	*ptr = 0;
	if (ret >= 0 && line_size > 0)
		return (1);
	return (ret);
}
