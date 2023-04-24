/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_do.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 22:05:59 by mmoramov          #+#    #+#             */
/*   Updated: 2023/04/24 17:27:46 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_do_swap_push(t_stack *a, t_stack *b, char *txt)
{
	if (!ft_strncmp(txt, "sa\n", 3) && a->len > 0)
		ft_moves_swap(a, 0);
	else if (!ft_strncmp(txt, "sb\n", 3) && b->len > 0)
		ft_moves_swap(b, 0);
	else if (!ft_strncmp(txt, "ss\n", 3) && a->len > 0 && b->len > 0)
		ft_moves_swap_both(a, b, 0);
	else if (!ft_strncmp(txt, "pa\n", 3) && b->len > 0)
		ft_moves_push(b, a, 0);
	else if (!ft_strncmp(txt, "pb\n", 3) && a->len > 0)
		ft_moves_push(a, b, 0);
	else
		return (0);
	return (1);
}

int	ft_do_rrotate(t_stack *a, t_stack *b, char *txt)
{
	if (!ft_strncmp(txt, "rra\n", 4) && a->len > 0)
		ft_moves_rev_rotate(a, 0);
	else if (!ft_strncmp(txt, "rrb\n", 4) && b->len > 0)
		ft_moves_rev_rotate(b, 0);
	else if (!ft_strncmp(txt, "rrr\n", 4) && a->len > 0 && b->len > 0)
		ft_moves_rev_rotate_both(a, b, 0);
	else
		return (0);
	return (1);
}

int	ft_do_rotate(t_stack *a, t_stack *b, char *txt)
{
	if (!ft_strncmp(txt, "ra\n", 3) && a->len > 0)
		ft_moves_rotate(a, 0);
	else if (!ft_strncmp(txt, "rb\n", 3) && b->len > 0)
		ft_moves_rotate(b, 0);
	else if (!ft_strncmp(txt, "rr\n", 3) && a->len > 0 && b->len > 0)
		ft_moves_rotate_both(a, b, 0);
	else
		return (0);
	return (1);
}

int	ft_checker_do_instructions(t_stack *a, t_stack *b, char *txt)
{
	while (txt[0])
	{
		if (ft_do_rrotate(a, b, txt))
			txt++;
		else if (!ft_do_swap_push(a, b, txt) && !ft_do_rotate(a, b, txt))
		{
			ft_gnl_free(&txt);
			ft_lst_free(&a -> first, &b -> first);
			ft_putstr_fd("Error\n", 1);
			return (1);
		}
		txt = txt + 3;
	}
	return (0);
}
