/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:37:12 by mmoramov          #+#    #+#             */
/*   Updated: 2023/04/15 17:01:36 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void ft_sort_ra_rrb(t_stack *a_stack, t_stack *b_stack, int ra, int rrb)
{
    while(rrb-- > 0)
		ft_moves_rev_rotate(b_stack, 2);
    while(ra-- > 0)
        ft_moves_rotate(a_stack, 1);
}

void ft_sort_rb_rra(t_stack *a_stack, t_stack *b_stack, int rb, int rra)
{
    while(rra-- > 0)
		ft_moves_rev_rotate(a_stack, 1);
    while(rb-- > 0)
        ft_moves_rotate(b_stack, 2);
}

void ft_sort_ra_rb(t_stack *a_stack, t_stack *b_stack, int ra, int rb)
{
    if (ra > rb)
    {
        while(rb-- > 0)
        {
            ft_moves_rotate_both(a_stack, b_stack, 1);
            ra--;
        }
        while(ra-- > 0)
            ft_moves_rotate(a_stack, 1);
    }
    else
    {
        while(ra-- > 0)
        {
            ft_moves_rotate_both(a_stack, b_stack, 1);
            rb--;
        }
        while(rb-- > 0)
            ft_moves_rotate(b_stack, 2);
    }
}

void ft_sort_rra_rrb(t_stack *a_stack, t_stack *b_stack, int rra, int rrb)
{
    if (rra > rrb)
    {
        while(rrb-- > 0)
        {
            ft_moves_rev_rotate_both(a_stack, b_stack, 1);
            rra--;
        }
        while(rra-- > 0)
            ft_moves_rev_rotate(a_stack, 1);
    }
    else
    {
        while(rra-- > 0)
        {
            ft_moves_rev_rotate_both(a_stack, b_stack, 1);
            rrb--;
        }
        while(rrb-- > 0)
            ft_moves_rev_rotate(b_stack, 2);
    }
}

void ft_sort_three(t_stack *a_stack, t_stack *b_stack)
{
	t_piece *first;
	
	first = a_stack->first;
	if (ft_check_issorted(a_stack,b_stack) == 0 && a_stack->length == 3)
	{
		if(first->index > first->next->index && first->index > first->next->next->index)
			ft_moves_rotate(a_stack,1);
		else if (first->next->index > first->next->next->index)
			ft_moves_rev_rotate(a_stack,1);
		first = a_stack->first;
		if (first->index > first->next->index)
			ft_moves_swap(a_stack, 1);
	}
}