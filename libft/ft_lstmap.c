/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifarahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 22:53:41 by ifarahi           #+#    #+#             */
/*   Updated: 2019/09/28 22:53:43 by ifarahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *mapped;
	t_list *temp;

	if (!(temp = ft_lstnew(f(lst)->content, f(lst)->content_size)))
		return (NULL);
	mapped = temp;
	while (lst->next != NULL)
	{
		lst = lst->next;
		temp->next = ft_lstnew(f(lst)->content, f(lst)->content_size);
		temp = temp->next;
	}
	return (mapped);
}
