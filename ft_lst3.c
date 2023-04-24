/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 21:05:35 by mmoramov          #+#    #+#             */
/*   Updated: 2023/04/24 17:46:40 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_free(t_piece **a_lst, t_piece **b_lst)
{
	t_piece	*tmp;

	if (*a_lst == NULL && *b_lst == NULL)
		return ;
	tmp = *a_lst;
	while (*a_lst != NULL)
	{
		tmp = (*a_lst)-> next;
		free(*a_lst);
		*a_lst = tmp;
	}
	tmp = *b_lst;
	while (*b_lst != NULL)
	{
		tmp = (*b_lst)-> next;
		free(*b_lst);
		*b_lst = tmp;
	}
}

void	ft_lst_del_piece(t_piece *lst)
{
	t_piece	*a;
	t_piece	*current;

	a = lst;
	current = lst;
	while (a)
	{
		current = a;
		a = current -> next;
		free (current);
	}
}
