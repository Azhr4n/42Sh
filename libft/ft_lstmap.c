/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 14:48:32 by brandazz          #+#    #+#             */
/*   Updated: 2013/11/25 11:06:21 by brandazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*ptr;

	new_lst = f(lst);
	lst = lst->next;
	ptr = new_lst;
	while (lst)
	{
		ptr->next = f(lst);
		lst = lst->next;
		ptr = ptr->next;
	}
	return (new_lst);
}
