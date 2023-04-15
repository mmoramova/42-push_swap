/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:00:14 by mmoramov          #+#    #+#             */
/*   Updated: 2023/04/15 10:54:49 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "libft/libft.h"

typedef struct s_piece
{
	int				value;
	int				index;
    int             numop;
	struct s_piece	*next;
}	t_piece;

typedef struct s_stack
{
	int				length;
	struct s_piece	*first;
	struct s_piece	*last;
}	t_stack;

/* LISTS */
t_piece	*ft_lst_new(int value);
t_piece	*ft_lst_last(t_piece *lst);
t_piece	*ft_lst_beforelast(t_piece *lst);
void ft_lst_add_front(t_piece **lst, t_piece *new);
void ft_lst_add_back(t_piece **lst, t_piece *new);
void ft_lst_fill_numop(t_stack *a_stack, t_stack *b_stack, int i);
int	ft_lst_size(t_piece *lst);
int ft_lst_value_min(t_stack *a_stack);
int ft_lst_value_max(t_stack *a_stack);
int ft_lst_value_numopmin(t_stack *a_stack);

/* MOVES */
void ft_moves_swap(t_stack *a, int i);
void ft_moves_swap_both(t_stack *a, t_stack *b);
void ft_moves_push(t_stack *a, t_stack *b, int i);
void ft_moves_rotate(t_stack *a, int i);
void ft_moves_rev_rotate(t_stack *a, int i);
void ft_moves_rotate_both(t_stack *a, t_stack *b);
void ft_moves_rev_rotate_both(t_stack *a, t_stack *b);
int ft_moves_count(t_stack *a_stack, t_stack *b_stack, int nbr, int i);
int ft_moves_count_a(t_stack *a_stack, int nbr);
int ft_moves_count_b(t_stack *b_stack, int nbr);

/* CHECKS */
int ft_check_dup(t_stack *a_stack);
void ft_check_free(t_piece **lst);
int ft_check_input(char *str);
int ft_check_issorted(t_stack *a_stack, t_stack *b_stack);

/* UTILS */
int ft_find_positon(t_stack *a_stack, int nbr);
int ft_find_opt_moves(int ra, int rb, int rra, int rrb);
void ft_free(t_stack **lst);
int ft_nbrmax(int a, int b);
int ft_stack_init(int argc, char **argv, t_stack *a_stack, t_stack *b_stack);
void ft_stack_init_addindex(t_stack *a_stack);

/* SORT */
void ft_sort(t_stack *a_stack, t_stack *b_stack);
void ft_sort_b_to_a(t_stack *a_stack, t_stack *b_stack);
void ft_sort_a_to_b(t_stack *a_stack, t_stack *b_stack);

void ft_sort_three(t_stack *a_stack, t_stack *b_stack);
void ft_sort_ra_rrb(t_stack *a_stack, t_stack *b_stack, int ra, int rrb);
void ft_sort_rb_rra(t_stack *a_stack, t_stack *b_stack, int rb, int rra);
void ft_sort_ra_rb(t_stack *a_stack, t_stack *b_stack, int ra, int rb);
void ft_sort_rra_rrb(t_stack *a_stack, t_stack *b_stack, int rra, int rrb);

#endif
