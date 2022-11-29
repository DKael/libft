/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 21:49:36 by hyungdki          #+#    #+#             */
/*   Updated: 2022/11/28 21:49:37 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*do_map(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*free_node(t_list **lst, void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*delete;
	t_list	*new_temp;

	if (lst != 0)
	{
		new_temp = (t_list *)f((void *) lst);
		if (new_temp == 0)
			return (0);
		new_temp->next = lst->next;
		delete = lst;
		lst = new_temp;
		del(delete->content);
		free(delete);
		if (lst->next != 0)
			return (do_map(lst, f, del));
		return (lst);
	}
	return (0);
}

t_list	*do_map(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr_node;
	t_list	*delete;
	t_list	*new_temp;

	ptr_node = lst;
	while (ptr_node->next != 0)
	{
		new_temp = (t_list *)f((void *)(ptr_node->next));
		if (new_temp == 0)
			return (free_node(&lst, del));
		delete = ptr_node->next;
		new_temp->next = ptr_node->next->next;
		ptr_node->next = new_temp;
		ptr_node = ptr_node->next;
		delete = ptr_node;
		del(delete->content);
		free(delete);                                  
	}
	return (lst);
}

t_list	*free_node(t_list **lst, void (*del)(void *))
{
	t_list	*delete;
	t_list	*next_node;

	if ((*lst) != 0)
	{
		next_node = (*lst);
		while (next_node->next != 0)
		{
			delete = next_node;
			next_node = next_node->next;
			del(delete->content);
			free(delete);
		}
		free(next_node);
	}
	return (0);
}