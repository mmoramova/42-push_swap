/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:02:59 by mmoramov          #+#    #+#             */
/*   Updated: 2023/04/15 10:55:00 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sort_a_to_b(t_stack *a_stack, t_stack *b_stack)
{
    int moves;
    int ra;
    int rb;

    ft_lst_fill_numop(a_stack, b_stack, 1);
    ra = ft_find_positon(a_stack, ft_lst_value_numopmin(a_stack));
    rb = ft_moves_count_b(b_stack, ft_lst_value_numopmin(a_stack));
    moves = ft_find_opt_moves(ra, rb, a_stack->length-ra, b_stack->length-rb);
    
    if (moves == ra + b_stack->length-rb)
        ft_sort_ra_rrb(a_stack, b_stack, ra, b_stack->length-rb);
    else if (moves == (rb + a_stack->length-ra))
        ft_sort_rb_rra(a_stack, b_stack, rb, a_stack->length-ra);
    else if (moves == ft_nbrmax(ra, rb))
        ft_sort_ra_rb(a_stack, b_stack, ra, rb);
    else if (moves == ft_nbrmax(a_stack->length-ra, b_stack->length-rb))
        ft_sort_rra_rrb(a_stack, b_stack, a_stack->length-ra, b_stack->length-rb);             
    ft_moves_push(a_stack, b_stack, 2);
}

void ft_sort_b_to_a(t_stack *a_stack, t_stack *b_stack)
{
    int moves;
    int ra;
    int rb;

    ft_lst_fill_numop(b_stack, a_stack, 2);
    ra = ft_moves_count_a(a_stack, ft_lst_value_numopmin(b_stack));
    rb = ft_find_positon(b_stack, ft_lst_value_numopmin(b_stack));
    moves = ft_find_opt_moves(ra, rb, a_stack->length-ra, b_stack->length-rb);
   
    if (moves == ra + b_stack->length-rb)
        ft_sort_ra_rrb(a_stack, b_stack, ra, b_stack->length-rb);
    else if (moves == (rb + a_stack->length-ra))
        ft_sort_rb_rra(a_stack, b_stack, rb, a_stack->length-ra);
    else if (moves == ft_nbrmax(ra, rb))
        ft_sort_ra_rb(a_stack, b_stack, ra, rb);
    else if (moves == ft_nbrmax(a_stack->length-ra, b_stack->length-rb))
        ft_sort_rra_rrb(a_stack, b_stack, a_stack->length-ra, b_stack->length-rb);             
    ft_moves_push(b_stack, a_stack, 1);
}

void ft_sort(t_stack *a_stack, t_stack *b_stack)
{
   if (ft_check_issorted(a_stack,b_stack) != 1 && a_stack->length > 3)
        ft_moves_push(a_stack, b_stack, 2);
    if (ft_check_issorted(a_stack,b_stack) != 1 && a_stack->length > 3)
        ft_moves_push(a_stack, b_stack, 2);
    while (ft_check_issorted(a_stack,b_stack) != 1 && a_stack->length > 3)
       ft_sort_a_to_b(a_stack, b_stack);
    if (a_stack->length == 3)
		ft_sort_three(a_stack, b_stack);
    while (ft_check_issorted(a_stack,b_stack) != 1 && b_stack->length != 0)
       ft_sort_b_to_a(a_stack, b_stack);
    while (ft_check_issorted(a_stack,b_stack) != 1)
    {
        if (ft_find_positon(a_stack, ft_lst_value_min(a_stack)) < a_stack->length/2)
            ft_moves_rotate(a_stack, 1);
        else
            ft_moves_rev_rotate(a_stack, 1);
    }
   return;
}

int main(int argc, char **argv)
{
    t_stack a_stack;
    t_stack b_stack;

    if (argc > 1)
    {
		if(ft_stack_init(argc, argv, &a_stack, &b_stack) == 1)
		{
			ft_putstr_fd("Error\n", 1);
            ft_check_free(&a_stack.first); 
            ft_check_free(&b_stack.first);      
			return(1);
		}
		ft_sort(&a_stack, &b_stack); 
        ft_check_free(&a_stack.first); 
        ft_check_free(&b_stack.first);
	}
    return(0);
}
