/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:22:45 by mmoramov          #+#    #+#             */
/*   Updated: 2023/04/14 18:46:35 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_moves_rotate_both(t_stack *a, t_stack *b)
{
	ft_moves_rotate(a,0);
	ft_moves_rotate(b,0);
	ft_putstr_fd("rr\n",1);
}

void ft_moves_rev_rotate_both(t_stack *a, t_stack *b)
{
	ft_moves_rev_rotate(a,0);
	ft_moves_rev_rotate(b,0);
	ft_putstr_fd("rrr\n",1);
}
	
int ft_moves_count_a(t_stack *a_stack, int nbr)
{
    int position;
    t_piece *current;

    position = 1;
    current = a_stack->first;

    if (nbr < ft_lst_value_min(a_stack) || nbr > ft_lst_value_max(a_stack))
        return(ft_find_positon(a_stack, ft_lst_value_min(a_stack)));
    while (current && current->next && (current->index > nbr || current->next->index < nbr))
    {
        current = current->next;
        position++;
     }
    
    if (a_stack->length == position)
        return(0);
    return (position);
}

int ft_moves_count_b(t_stack *b_stack, int nbr)
{
    int position;
    t_piece *current;

    position = 1;
    current = b_stack->first;

    if (nbr < ft_lst_value_min(b_stack) || nbr > ft_lst_value_max(b_stack))
        return(ft_find_positon(b_stack, ft_lst_value_max(b_stack)));
    while (current && current->next && (current->index < nbr || current->next->index > nbr))
    {
        current = current->next;
        position++;
     }
    
    if (b_stack->length == position)
        return(0);
    return (position);
}

int ft_moves_count(t_stack *a_stack, t_stack *b_stack, int nbr, int i)
{
    int moves;
    int ra;
    int rb;

    if (i ==1)
    {
        ra = ft_find_positon(a_stack, nbr);
        rb = ft_moves_count_b(b_stack, nbr);
    }
    else
    {
        ra = ft_moves_count_a(a_stack, nbr);
        rb = ft_find_positon(b_stack, nbr);
    }
    moves = ft_find_opt_moves(ra, rb, a_stack->length-ra, b_stack->length-rb);
    return (moves);
}