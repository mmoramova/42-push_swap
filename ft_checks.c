/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:08:36 by mmoramov          #+#    #+#             */
/*   Updated: 2023/04/24 17:29:48 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_input(char *str)
{
	int		i;
	long	nbr;

	i = 0;
	nbr = 0;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1])
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	if (str[0] == '-')
		nbr *= -1;
	if (nbr < INT_MIN || nbr > INT_MAX || i == 0)
		return (1);
	return (0);
}

int	ft_check_dup(t_stack *a, t_stack *b)
{
	t_piece	*lst;
	t_piece	*current;

	current = a->first;
	lst = current;
	while (current && current -> next)
	{
		lst = current -> next;
		while (lst)
		{
			if (current -> value == lst -> value)
			{
				ft_lst_free(&a -> first, &b -> first);
				return (1);
			}
			lst = lst -> next;
		}
		current = current -> next;
	}
	return (0);
}

int	ft_check_issorted(t_stack *a, t_stack *b)
{
	t_piece	*current;

	current = a -> first;
	if (b -> len != 0)
		return (0);
	while (current && current -> next)
	{
		if (current -> index > current -> next -> index)
			return (0);
		current = current -> next;
	}
	return (1);
}
