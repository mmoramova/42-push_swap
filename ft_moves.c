/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:44:34 by mmoramov          #+#    #+#             */
/*   Updated: 2023/04/14 18:46:06 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_moves_swap(t_stack *a, int i)
{
	int temp_value;
	
	if (a && a->first->next)
	{
		temp_value = a->first->value;
		a->first->value = a->first->next->value;
		a->first->next->value = temp_value;

		temp_value = a->first->index;
		a->first->index = a->first->next->index;
		a->first->next->index = temp_value;
		
		if (i == 1)
			ft_putstr_fd("sa\n",1);
		if (i == 2)	
			ft_putstr_fd("sb\n",1);
	} 
}

void ft_moves_swap_both(t_stack *a, t_stack *b)
{
	ft_moves_swap(a,0);
	ft_moves_swap(b,0);
	ft_putstr_fd("ss\n",1);
}

void ft_moves_push(t_stack *a, t_stack *b, int i)
{
	t_piece *current;

	current = a->first;
	
	if(a->length > 0)
	{
		a->first = a->first->next;
		if(a->length == 1)
			a->last = NULL;
		ft_lst_add_front(&b->first,current);
		b->first = current;
		b->last = ft_lst_last(current);

		a->length -= 1;
		b->length += 1;
		
		if (i == 1)
			ft_putstr_fd("pa\n",1);
		if (i == 2)
			ft_putstr_fd("pb\n",1);
	}
}

void ft_moves_rotate(t_stack *a, int i)
{
	t_piece *current;

	current = a->first;

	if(a->length > 1)
	{
		a->last->next = current;
		a->first = current->next;
		current->next = NULL;
		a->last = ft_lst_last(a->first);
				
		if (i == 1)
			ft_putstr_fd("ra\n",1);
		if (i == 2)
			ft_putstr_fd("rb\n",1);
	}
}

void ft_moves_rev_rotate(t_stack *a, int i)
{
	t_piece *beforelast;

	beforelast = ft_lst_beforelast(a->first);

	if(a->length > 1)
	{
		a->last->next = a->first;
		
		a->first = a->last;
		beforelast->next = NULL;
		a->last = beforelast;

		if (i == 1)
			ft_putstr_fd("rra\n",1);
		if (i == 2)
			ft_putstr_fd("rrb\n",1);
	}
}