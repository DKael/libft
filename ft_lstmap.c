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

static t_list	*ft_lstnew1(void *content);
static void		ft_lstclear1(t_list **lst, void (*del)(void*));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_iter;

	if (lst != 0)
	{
		new_lst = ft_lstnew1(f(lst->content));
		if (new_lst == 0)
			return (0);
		new_iter = new_lst;
		lst = lst->next;
		while (lst != 0)
		{
			new_iter->next = ft_lstnew1(f(lst->content));
			if (new_iter->next == 0)
			{
				ft_lstclear1(&new_lst, del);
				return (0);
			}
			new_iter = new_iter->next;
			lst = lst->next;
		}
		return (new_lst);
	}
	return (0);
}

static t_list	*ft_lstnew1(void *content)
{
	t_list	*result;

	result = (t_list *)malloc(sizeof(t_list));
	if (result == 0)
		return (0);
	result->content = content;
	result->next = 0;
	return (result);
}

static void	ft_lstclear1(t_list **lst, void (*del)(void*))
{
	t_list	*delete;
	t_list	*next_node;

	if ((*lst) != 0)
	{
		next_node = (*lst);
		while (next_node != 0)
		{
			delete = next_node;
			next_node = next_node->next;
			del(delete->content);
			free(delete);
		}
		free(next_node);
		*lst = 0;
	}
}
