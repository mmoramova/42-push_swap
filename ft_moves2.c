/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:22:45 by mmoramov          #+#    #+#             */
/*   Updated: 2023/04/24 17:45:42 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_moves_rotate_both(t_stack *a, t_stack *b, int i)
{
	ft_moves_rotate(a, 0);
	ft_moves_rotate(b, 0);
	if (i != 0)
		ft_putstr_fd("rr\n", 1);
}

void	ft_moves_rev_rotate_both(t_stack *a, t_stack *b, int i)
{
	ft_moves_rev_rotate(a, 0);
	ft_moves_rev_rotate(b, 0);
	if (i != 0)
		ft_putstr_fd("rrr\n", 1);
}

int	ft_moves_count_a(t_stack *a, int nbr)
{
	int		position;
	t_piece	*current;

	position = 1;
	current = a -> first;
	if (nbr < ft_lst_value_min(a) || nbr > ft_lst_value_max(a))
		return (ft_find_positon(a, ft_lst_value_min(a)));
	while (current && current->next && (current->index > nbr
			|| current->next->index < nbr))
	{
		current = current->next;
		position++;
	}
	if (a->len == position)
		return (0);
	return (position);
}

int	ft_moves_count_b(t_stack *b, int nbr)
{
	int		position;
	t_piece	*current;

	position = 1;
	current = b -> first;
	if (nbr < ft_lst_value_min(b) || nbr > ft_lst_value_max(b))
		return (ft_find_positon(b, ft_lst_value_max(b)));
	while (current && current->next && (current->index < nbr
			|| current->next->index > nbr))
	{
		current = current->next;
		position++;
	}
	if (b->len == position)
		return (0);
	return (position);
}

int	ft_moves_count(t_stack *a, t_stack *b, int nbr, int i)
{
	int	moves;
	int	ra;
	int	rb;

	if (i == 1)
	{
		ra = ft_find_positon(a, nbr);
		rb = ft_moves_count_b(b, nbr);
	}
	else
	{
		ra = ft_moves_count_a(a, nbr);
		rb = ft_find_positon(b, nbr);
	}
	moves = ft_find_opt_moves(ra, rb, a->len - ra, b->len - rb);
	return (moves);
}
