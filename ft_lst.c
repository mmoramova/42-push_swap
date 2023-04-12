/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:42:43 by mmoramov          #+#    #+#             */
/*   Updated: 2023/04/10 20:19:19 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_piece	*ft_lstpnew(int content)
{
	t_piece	*lst;

	lst = (t_piece *) malloc(sizeof(t_piece));
	if (!lst)
		return (NULL);
	lst -> value = content;
	lst -> index = 0; 
    lst -> numop = 0;
	lst -> next = NULL;
	return (lst);
}

int	ft_lstpsize(t_piece *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst -> next;
	}
	return (len);
}

void	ft_lstpadd_front(t_piece **lst, t_piece *new)
{
	new -> next = *lst;
	*lst = new;
}

t_piece	*ft_lstplast(t_piece *lst)
{
	while (lst && lst -> next)
		lst = lst -> next;
	return (lst);
}

t_piece	*ft_lstpbflast(t_piece *lst)
{
	while (lst && lst -> next && lst -> next -> next)
		lst = lst -> next;
	return (lst);
}

void	ft_lstpadd_back(t_piece **lst, t_piece *new)
{
	if (*lst)
		ft_lstplast(*lst)-> next = new;
	else
		*lst = new;
}

/*
void	ft_lstpiter(t_piece *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst -> index);
		lst = lst -> next;
	}
}

t_piece	*ft_lstpmap(t_piece *lst, void *(*f)(void *), void (*del)(void *))
{
	t_piece	*new;
	t_piece	*current;
	void	*temp;

	new = NULL;
	while (lst)
	{
		temp = f(lst -> index);
		current = ft_lstpnew(temp);
		if (!current)
		{
			ft_lstpclear(&new, del);
			del(temp);
			return (NULL);
		}
		ft_lstpadd_back(&new, current);
		lst = lst -> next;
	}
	return (new);
}*/

int ft_lst_value_min(t_stack *a_stack)
{
    int value;
    t_piece *current;

    current = a_stack->first;
    value = current->index;

    while (current)
    {
        if(current->index < value)
            value = current->index;
        current = current->next;
    }
    return(value);
}

int ft_lst_value_max(t_stack *a_stack)
{
    int value;
    t_piece *current;

    current = a_stack->first;
    value = current->index;

    while (current)
    {
        if(current->index > value)
            value = current->index;
        current = current->next;
    }
    return(value);
}

int ft_lst_value_numopmin(t_stack *a_stack)
{
    int value;
    int numop;
    t_piece *current;

    current = a_stack->first;
    value = current->index;
    numop = current->numop;

  while (current)
    {
        if(current->numop < numop)
        {
            value = current->index;
            numop = current->numop;
        }
        current = current->next;
    }
    return(value);
}