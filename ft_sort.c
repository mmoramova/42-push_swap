/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:37:12 by mmoramov          #+#    #+#             */
/*   Updated: 2023/04/22 21:08:39 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_ra_rrb(t_stack *a, t_stack *b, int ra, int rrb)
{
	while(rrb-- > 0)
		ft_moves_rev_rotate(b, 2);
	while(ra-- > 0)
		ft_moves_rotate(a, 1);
}

void	ft_sort_rb_rra(t_stack *a, t_stack *b, int rb, int rra)
{
	while(rra-- > 0)
		ft_moves_rev_rotate(a, 1);
	while(rb-- > 0)
		ft_moves_rotate(b, 2);
}

void	ft_sort_ra_rb(t_stack *a, t_stack *b, int ra, int rb)
{
	if(ra > rb)
	{
		while(rb-- > 0)
		{
			ft_moves_rotate_both(a, b, 1);
			ra--;
		}
		while(ra-- > 0)
			ft_moves_rotate(a, 1);
	}
	else
	{
		while(ra-- > 0)
		{
			ft_moves_rotate_both(a, b, 1);
			rb--;
		}
		while(rb-- > 0)
			ft_moves_rotate(b, 2);
	}
}

void	ft_sort_rra_rrb(t_stack *a, t_stack *b, int rra, int rrb)
{
	if (rra > rrb)
	{
		while(rrb-- > 0)
		{
			ft_moves_rev_rotate_both(a, b, 1);
			rra--;
		}
		while(rra-- > 0)
			ft_moves_rev_rotate(a, 1);
	}
	else
	{
		while(rra-- > 0)
		{
			ft_moves_rev_rotate_both(a, b, 1);
			rrb--;
		}
		while(rrb-- > 0)
			ft_moves_rev_rotate(b, 2);
	}
}

void	ft_sort_three(t_stack *a, t_stack *b)
{
	t_piece	*first;

	first = a -> first;
	if (ft_check_issorted(a,b) == 0 && a->len == 3)
	{
		if(first -> index > first -> next -> index && first -> index > first -> next -> next -> index)
			ft_moves_rotate(a,1);
		else if (first -> next -> index > first -> next -> next -> index)
			ft_moves_rev_rotate(a,1);
		first = a -> first;
		if (first -> index > first -> next -> index)
			ft_moves_swap(a, 1);
	}
}
