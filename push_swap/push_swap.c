/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaufil <abeaufil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:48:09 by abeaufil          #+#    #+#             */
/*   Updated: 2024/12/18 13:51:54 by abeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_list	*ft_lstnew(int content)
{
	t_list	*new_lst;

	new_lst = malloc(sizeof(t_list));
	if (new_lst)
	{
		new_lst->content = content;
		new_lst->next = NULL;
	}
	return (new_lst);
}

int	ft_lstsize(t_list *lst)
{
	int		size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	while (*lst)
		lst = &(*lst)->next;
	*lst = new;
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!del || !lst || !*lst)
		return ;
	while (lst && *lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_elem;
	t_list	*new_lst;
	void	*content;

	if (!lst || !f)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		content = f(lst->content);
		new_elem = ft_lstnew(content);
		if (!new_elem)
		{
			if (del)
				ft_lstclear(&new_lst, del);
			free(content);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_elem);
		lst = lst->next;
	}
	return (new_lst);
}

int main(void)
{
	t_list *list;

	list = NULL;
	ft_lstadd_back(&list, ft_lstnew(1));
	ft_lstadd_back(&list, ft_lstnew(2));
	ft_lstadd_back(&list, ft_lstnew(3));
	ft_lstadd_back(&list, ft_lstnew(4));
	ft_lstadd_front(&list, ft_lstnew(5));
	ft_lstadd_front(&list, ft_lstnew(6));

	// list = list->next->next;
	while (list->next->next)
	{
		printf("%d\n", list->next->next->content);
		list = list->next;
	}
}


