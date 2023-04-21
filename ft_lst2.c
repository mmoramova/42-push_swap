/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:19:51 by mmoramov          #+#    #+#             */
/*   Updated: 2023/04/16 17:53:03 by mmoramov         ###   ########.fr       */
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

void    ft_lst_fill_numop(t_stack *a_stack, t_stack *b_stack, int i)
{
    t_piece *a;
    
    a = a_stack->first;    
    while (a)
    {
        a->numop = ft_moves_count(a_stack,b_stack,a->index, i) + 1;
        a = a -> next;
    }
}

void	ft_lst_del_piece(t_piece *lst)
{
	t_piece *a;
    t_piece *current;
    
    a = lst; 
    current = lst;  

    while (a)
    {
        current = a;
        a = current -> next;
	    free(current);
    }
}