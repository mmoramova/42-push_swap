/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:19:51 by mmoramov          #+#    #+#             */
/*   Updated: 2023/04/22 21:06:30 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_size(t_piece *lst)
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

int	ft_lst_value_min(t_stack *a)
{
	int	value;
	t_piece	*current;

	current = a -> first;
	value = current -> index;
	while (current)
	{
		if(current -> index < value)
			value = current -> index;
		current = current -> next;
	}
	return(value);
}

int	ft_lst_value_max(t_stack *a)
{
	int	value;
	t_piece	*current;

	current = a -> first;
	value = current -> index;

	while (current)
	{
		if(current -> index > value)
			value = current -> index;
		current = current -> next;
	}
	return(value);
}

int	ft_lst_value_numopmin(t_stack *a)
{
	int		value;
	int		numop;
	t_piece	*current;

	current = a -> first;
	value = current -> index;
	numop = current -> numop;
	while (current)
	{
		if(current -> numop < numop)
		{
			value = current -> index;
			numop = current -> numop;
		}
		current = current -> next;
	}
	return(value);
}

void	ft_lst_fill_numop(t_stack *a, t_stack *b, int i)
{
	t_piece *ap;

	ap = a -> first;
	while (ap)
	{
		ap->numop = ft_moves_count(a,b,ap -> index, i) + 1;
		ap = ap -> next;
	}
}
