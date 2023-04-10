/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:00:14 by mmoramov          #+#    #+#             */
/*   Updated: 2023/04/10 17:35:30 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
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

void ft_print_log(t_stack *a, t_stack *b);
t_piece	*ft_lstpnew(int content);
int	ft_lstpsize(t_piece *lst);
void	ft_lstpadd_front(t_piece **lst, t_piece *new);
t_piece	*ft_lstplast(t_piece *lst);
t_piece	*ft_lstpbflast(t_piece *lst);
void	ft_lstpadd_back(t_piece **lst, t_piece *new);
void ft_moves_swap(t_stack *a, int i);
void ft_moves_swap_both(t_stack *a, t_stack *b);
void ft_moves_push(t_stack *a, t_stack *b, int i);
void ft_moves_rotate(t_stack *a, int i);
void ft_moves_rev_rotate(t_stack *a, int i);
void ft_moves_rotate_both(t_stack *a, t_stack *b);
void ft_moves_rev_rotate_both(t_stack *a, t_stack *b);
int ft_isnumber(char *str);
int ft_stack_init(int argc, char **argv, t_stack *a_stack, t_stack *b_stack);
void ft_stack_init_addindex(t_stack *a_stack);
int ft_check_dup(t_stack *a_stack);
int ft_check_issorted(t_stack *a_stack, t_stack *b_stack);
void ft_sort_two(t_stack *a_stack, t_stack *b_stack) ;
void ft_sort_three(t_stack *a_stack, t_stack *b_stack);
int ft_count_moves_a(t_stack *a_stack, int nbr);
int ft_count_moves_b(t_stack *b_stack, int nbr);
void ft_sort(t_stack *a_stack, t_stack *b_stack);
int ft_find_positon(t_stack *a_stack, int nbr);
int ft_lst_value_min(t_stack *a_stack);
int ft_lst_value_max(t_stack *a_stack);
int ft_lst_value_numopmin(t_stack *a_stack);

#endif
