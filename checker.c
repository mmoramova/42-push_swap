/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 12:37:12 by mmoramov          #+#    #+#             */
/*   Updated: 2023/04/22 20:14:00 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *ft_checker_read_input(void)
{
	char *txt;
	char *line;

	txt = NULL;
	line = "begin";

	while (line != NULL)
	{
		line = NULL;
		line = get_next_line(0);
		if (line != NULL)
		txt = ft_gnl_strjoin(txt, line);
		free(line);
	}
	return (txt);
}

int ft_checker_find_instructions(t_stack *a_stack, t_stack *b_stack, char *txt)
{
	while (txt[0])
	{
		if (ft_strncmp(txt, "sa\n", 3) == 0 && a_stack->length > 0)
			ft_moves_swap(a_stack, 0);
		else if (ft_strncmp(txt, "sb\n", 3) == 0 && b_stack->length > 0)
			ft_moves_swap(b_stack, 0);
		else if (ft_strncmp(txt, "ss\n", 3) == 0 && a_stack->length > 0 && b_stack->length > 0)
			ft_moves_swap_both(a_stack, b_stack, 0);
		else if (ft_strncmp(txt, "pa\n", 3) == 0 && b_stack->length > 0)
			ft_moves_push(b_stack, a_stack, 0);
		else if (ft_strncmp(txt, "pb\n", 3) == 0 && a_stack->length > 0)
			ft_moves_push(a_stack, b_stack, 0);
		else if (ft_strncmp(txt, "rra\n", 4) == 0 && a_stack->length > 0)
		{
			ft_moves_rev_rotate(a_stack, 0);
			txt++;
		}
		else if (ft_strncmp(txt, "rrb\n", 4) == 0 && b_stack->length > 0)
		{
			ft_moves_rev_rotate(b_stack, 0);
			txt++;
        }
		else if (ft_strncmp(txt, "rrr\n", 4) == 0 && a_stack->length > 0 && b_stack->length > 0)
		{
			ft_moves_rev_rotate_both(a_stack, b_stack, 0);
			txt++;
		}
		else if (ft_strncmp(txt, "ra\n", 3) == 0 && a_stack->length > 0)
			ft_moves_rotate(a_stack, 0);
		else if (ft_strncmp(txt, "rb\n", 3) == 0 && b_stack->length > 0)
			ft_moves_rotate(b_stack, 0);
		else if (ft_strncmp(txt, "rr\n", 3) == 0 && a_stack->length > 0 && b_stack->length > 0)
			ft_moves_rotate_both(a_stack, b_stack, 0);
		else
			return(1);
		txt = txt+3;
	}
	return(0);
}

int	main(int argc, char **argv)
{
	t_stack	a_stack;
	t_stack	b_stack;
	char	*txt;

	if (argc > 1)
	{
		if(ft_stack_init(argc, argv, &a_stack, &b_stack) == 1)
		{
			ft_putstr_fd("Error\n", 1);
			return(1);
		}
		if (ft_check_dup(&a_stack) == 1)
		{
			ft_putstr_fd("Error\n", 1);
			ft_lst_free(&a_stack.first, &b_stack.first);
			return(1);
		}
		ft_stack_init_addindex(&a_stack);
		txt = ft_checker_read_input();
		if (txt)
		{
			if (ft_checker_find_instructions(&a_stack,&b_stack,txt) == 1)
			{
				ft_putstr_fd("Error\n", 1);
				ft_lst_free(&a_stack.first, &b_stack.first);
				ft_gnl_free(&txt);
				return(1);
			}
		}
		if (ft_check_issorted(&a_stack,&b_stack) == 1)
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
		ft_lst_free(&a_stack.first, &b_stack.first);
		ft_gnl_free(&txt);
	}
	return(0);
}
