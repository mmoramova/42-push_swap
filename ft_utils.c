/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:47:40 by mmoramov          #+#    #+#             */
/*   Updated: 2023/04/14 18:49:22 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_find_positon(t_stack *a_stack, int nbr)
{
    int position;
    t_piece *current;

    position = 0;
    current = a_stack->first;

    while (current && current->index != nbr)
    {
        current = current->next;
        position++;
    }
    return(position);
}

int ft_find_opt_moves(int ra, int rb, int rra, int rrb)
{
    int moves;

    moves = ra + rrb;
    if (moves >(rb + rra))
        moves = rb + rra;
    if (moves > ft_nbrmax(ra, rb))
        moves = ft_nbrmax(ra, rb);
    if (moves > ft_nbrmax(rra, rrb))
        moves = ft_nbrmax(rra, rrb);
    return(moves);
}

int ft_nbrmax(int a, int b)
{
   if (a > b)
    return (a);
   return(b);
}

void ft_stack_init_addindex(t_stack *a_stack)
{
	int		i;
	t_piece	*current;
	t_piece *a;
	int		count;

	i = 0;
	current = a_stack->first;

	while (i < a_stack->length)
	{
		a = a_stack->first;
		count = 1;
		while(a)
		{
			if (current -> value > a -> value)
				count++;
			a = a ->next;
		}	
		current -> index = count;	
		current = current->next;
		i++;
	}
}

int ft_stack_init(int argc, char **argv, t_stack *a_stack, t_stack *b_stack)
{
	t_piece	*current;
	t_piece	*a;
	int		i;
	
	i = 1;
	a = NULL;
	while (i < argc)
	{
		if (ft_check_input(argv[i]) == 0)
			return(1);
		current = ft_lst_new(ft_atoi(argv[i++]));
		ft_lst_add_back(&a, current);
	}
	a_stack->first = a;
	a_stack->last = ft_lst_last(a);
	a_stack->length = ft_lst_size(a);
	b_stack -> first = NULL;
	b_stack -> last = NULL;
	b_stack -> length = 0;
    if (ft_check_dup(a_stack) == 1)
        return(1);
    ft_stack_init_addindex(a_stack);
    return(0);
}