/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:08:36 by mmoramov          #+#    #+#             */
/*   Updated: 2023/04/15 10:54:58 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_check_input(char *str)
{
	int i;
    long nbr;

	i = 0;
    nbr = 0;
	if ((str[i] == '-' || str[i] == '+') && str[i+1])
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return(1);
        nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
    if (str[0] == '-')
        nbr *= -1;
     if (nbr < INT_MIN || nbr > INT_MAX)
        return(1);
	return(0);
}

int ft_check_dup(t_stack *a_stack)
{
	t_piece *lst;
	t_piece *current;

	current = a_stack->first;
	lst = current;

	while(current && current->next)
	{
		lst = current->next;	
		while (lst)
		{
			if (current->value == lst->value)
				return(1);
			lst = lst->next;
		}
		current = current->next;
	}
	return(0);
}

int ft_check_issorted(t_stack *a_stack, t_stack *b_stack)
{
	t_piece *current;

	current = a_stack->first;

	if (b_stack->length != 0)
		return(0);
	while(current && current->next)
	{
		if (current->index > current->next->index)
				return(0);
		current = current->next;
	}
	return(1);
}

void	ft_check_free(t_piece **lst)
{
	t_piece	*tmp;

	if (*lst == NULL)
		return ;
	tmp = *lst;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		free (*lst);
		*lst = tmp;
	}
}