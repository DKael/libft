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

static t_list	*m(t_list *l, t_list *n, void *(*f)(void *), void (*d)(void *));
static t_list	*ft_lstnew1(void *content);
static void		ft_lstclear1(t_list **lst, void (*del)(void*));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	void	*f_content;

	if (lst != 0)
	{
		f_content = f(lst->content);
		new_lst = ft_lstnew1(f_content);
		if (new_lst == 0)
		{
			del(f_content);
			return (0);
		}
		lst = lst->next;
		return (m(lst, new_lst, f, del));
	}
	return (0);
}

static t_list	*m(t_list *l, t_list *n, void *(*f)(void *), void (*d)(void *))
{
	void	*f_content;
	t_list	*new_iter;

	new_iter = n;
	while (l != 0)
	{
		f_content = f(l->content);
		new_iter->next = ft_lstnew1(f_content);
		if (new_iter->next == 0)
		{
			d(f_content);
			ft_lstclear1(&n, d);
			return (0);
		}
		new_iter = new_iter->next;
		l = l->next;
	}
	return (n);
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
