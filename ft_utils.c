/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:47:40 by mmoramov          #+#    #+#             */
/*   Updated: 2023/04/24 17:42:54 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_positon(t_stack *a, int nbr)
{
	int		position;
	t_piece	*current;

	position = 0;
	current = a -> first;
	while (current && current -> index != nbr)
	{
		current = current -> next;
		position++;
	}
	return (position);
}

int	ft_find_opt_moves(int ra, int rb, int rra, int rrb)
{
	int	moves;

	moves = ra + rrb;
	if (moves > (rb + rra))
		moves = rb + rra;
	if (moves > ft_nbrmax(ra, rb))
		moves = ft_nbrmax(ra, rb);
	if (moves > ft_nbrmax(rra, rrb))
		moves = ft_nbrmax(rra, rrb);
	return (moves);
}

int	ft_nbrmax(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	ft_stack_init_addindex(t_stack *a)
{
	int		i;
	t_piece	*current;
	t_piece	*ap;
	int		count;

	i = 0;
	current = a -> first;
	while (i++ < a -> len)
	{
		ap = a -> first;
		count = 1;
		while (ap)
		{
			if (current -> value > ap -> value)
				count++;
			ap = ap -> next;
		}
		current -> index = count;
		current = current -> next;
	}
}

int	ft_stack_init(char **argv, t_stack *a, t_stack *b)
{
	t_piece	*ap;
	int		i;

	i = 1;
	ap = NULL;
	while (argv[i])
	{
		if (ft_check_input(argv[i]) == 1)
		{
			ft_lst_del_piece(ap);
			return (1);
		}
		ft_lst_add_back(&ap, ft_lst_new(ft_atoi(argv[i++])));
	}
	a -> first = ap;
	a -> last = ft_lst_last(ap);
	a -> len = ft_lst_size(ap);
	b -> first = NULL;
	b -> last = NULL;
	b -> len = 0;
	ft_stack_init_addindex(a);
	if (ft_check_dup(a, b) == 1)
		return (1);
	return (0);
}
