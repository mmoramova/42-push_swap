/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:42:43 by mmoramov          #+#    #+#             */
/*   Updated: 2023/04/14 18:20:48 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_piece	*ft_lst_new(int value)
{
	t_piece	*lst;

	lst = (t_piece *) malloc(sizeof(t_piece));
	if (!lst)
		return (NULL);
	lst -> value = value;
	lst -> index = 0; 
    lst -> numop = 0;
	lst -> next = NULL;
	return (lst);
}

t_piece	*ft_lst_last(t_piece *lst)
{
	while (lst && lst -> next)
		lst = lst -> next;
	return (lst);
}

t_piece	*ft_lst_beforelast(t_piece *lst)
{
	while (lst && lst -> next && lst -> next -> next)
		lst = lst -> next;
	return (lst);
}

void	ft_lst_add_front(t_piece **lst, t_piece *new)
{
	new -> next = *lst;
	*lst = new;
}

void	ft_lst_add_back(t_piece **lst, t_piece *new)
{
	if (*lst)
		ft_lst_last(*lst)-> next = new;
	else
		*lst = new;
}