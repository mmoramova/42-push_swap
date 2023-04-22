/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:02:59 by mmoramov          #+#    #+#             */
/*   Updated: 2023/04/22 21:24:12 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_a_to_b(t_stack *a, t_stack *b)
{
	int	moves;
	int	ra;
	int	rb;

	ft_lst_fill_numop(a, b, 1);
	ra = ft_find_positon(a, ft_lst_value_numopmin(a));
	rb = ft_moves_count_b(b, ft_lst_value_numopmin(a));
	moves = ft_find_opt_moves(ra, rb, a->len - ra, b->len - rb);

	if (moves == ra + b->len - rb)
		ft_sort_ra_rrb(a, b, ra, b->len - rb);
	else if (moves == (rb + a->len - ra))
		ft_sort_rb_rra(a, b, rb, a->len - ra);
	else if (moves == ft_nbrmax(ra, rb))
		ft_sort_ra_rb(a, b, ra, rb);
	else if (moves == ft_nbrmax(a->len - ra, b->len - rb))
		ft_sort_rra_rrb(a, b, a->len - ra, b->len - rb);
	ft_moves_push(a, b, 2);
}

void	ft_sort_b_to_a(t_stack *a, t_stack *b)
{
	int	moves;
	int	ra;
	int	rb;

	ft_lst_fill_numop(b, a, 2);
	ra = ft_moves_count_a(a, ft_lst_value_numopmin(b));
	rb = ft_find_positon(b, ft_lst_value_numopmin(b));
	moves = ft_find_opt_moves(ra, rb, a->len - ra, b->len - rb);
	if (moves == ra + b->len - rb)
		ft_sort_ra_rrb(a, b, ra, b->len - rb);
	else if (moves == (rb + a->len - ra))
		ft_sort_rb_rra(a, b, rb, a->len - ra);
	else if (moves == ft_nbrmax(ra, rb))
		ft_sort_ra_rb(a, b, ra, rb);
	else if (moves == ft_nbrmax(a->len - ra, b->len - rb))
		ft_sort_rra_rrb(a, b, a->len - ra, b->len - rb);
	ft_moves_push(b, a, 1);
}

void	ft_sort(t_stack *a, t_stack *b)
{
	if (ft_check_issorted(a,b) != 1 && a -> len > 3)
		ft_moves_push(a, b, 2);
	if (ft_check_issorted(a,b) != 1 && a -> len > 3)
		ft_moves_push(a, b, 2);
	while (ft_check_issorted(a,b) != 1 && a -> len > 3)
		ft_sort_a_to_b(a, b);
	if (a -> len == 3)
		ft_sort_three(a, b);
	while (ft_check_issorted(a,b) != 1 && b -> len != 0)
		ft_sort_b_to_a(a, b);
	while (ft_check_issorted(a,b) != 1)
	{
		if (ft_find_positon(a, ft_lst_value_min(a)) < a -> len / 2)
			ft_moves_rotate(a, 1);
		else
			ft_moves_rev_rotate(a, 1);
	}
}

int	main(int argc, char **argv)
{
	t_stack a;
	t_stack b;

	if	(argc > 1)
	{
		if (ft_stack_init(argv, &a, &b) == 1)
		{
			ft_putstr_fd("Error\n", 1);
			return(1);
		}
		ft_sort(&a, &b);
		ft_lst_free(&a.first, &b.first);
	}
	return(0);
}
