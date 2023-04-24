/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:00:14 by mmoramov          #+#    #+#             */
/*   Updated: 2023/04/23 17:10:28 by mmoramov         ###   ########.fr       */
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
	int				numop;
	struct s_piece	*next;
}	t_piece;

typedef struct s_stack
{
	int				len;
	struct s_piece	*first;
	struct s_piece	*last;
}	t_stack;

/* LISTS */
t_piece	*ft_lst_new(int value);
t_piece	*ft_lst_last(t_piece *lst);
t_piece	*ft_lst_beforelast(t_piece *lst);
void	ft_lst_add_front(t_piece **lst, t_piece *new);
void	ft_lst_add_back(t_piece **lst, t_piece *new);
void	ft_lst_del_piece(t_piece *lst);
void	ft_lst_fill_numop(t_stack *a, t_stack *b, int i);
void	ft_lst_free(t_piece **a_lst, t_piece **lst);
int		ft_lst_size(t_piece *lst);
int		ft_lst_value_min(t_stack *a);
int		ft_lst_value_max(t_stack *a);
int		ft_lst_value_numopmin(t_stack *a);

/* MOVES */
void	ft_moves_swap(t_stack *a, int i);
void	ft_moves_swap_both(t_stack *a, t_stack *b, int i);
void	ft_moves_push(t_stack *a, t_stack *b, int i);
void	ft_moves_rotate(t_stack *a, int i);
void	ft_moves_rev_rotate(t_stack *a, int i);
void	ft_moves_rotate_both(t_stack *a, t_stack *b, int i);
void	ft_moves_rev_rotate_both(t_stack *a, t_stack *b, int i);
int		ft_moves_count(t_stack *a, t_stack *b, int nbr, int i);
int		ft_moves_count_a(t_stack *a, int nbr);
int		ft_moves_count_b(t_stack *b, int nbr);

/* CHECKS */
int		ft_check_dup(t_stack *a, t_stack *b);
int		ft_check_input(char *str);
int		ft_check_issorted(t_stack *a, t_stack *b);

/* UTILS */
int		ft_find_positon(t_stack *a, int nbr);
int		ft_find_opt_moves(int ra, int rb, int rra, int rrb);
int		ft_nbrmax(int a, int b);
int		ft_stack_init(char **argv, t_stack *a, t_stack *b);
void	ft_stack_init_addindex(t_stack *a);

/* SORT */
void	ft_sort(t_stack *a, t_stack *b);
void	ft_sort_b_to_a(t_stack *a, t_stack *b);
void	ft_sort_a_to_b(t_stack *a, t_stack *b);
void	ft_sort_three(t_stack *a, t_stack *b);
void	ft_sort_ra_rrb(t_stack *a, t_stack *b, int ra, int rrb);
void	ft_sort_rb_rra(t_stack *a, t_stack *b, int rb, int rra);
void	ft_sort_ra_rb(t_stack *a, t_stack *b, int ra, int rb);
void	ft_sort_rra_rrb(t_stack *a, t_stack *b, int rra, int rrb);

/* CHECKER */
char	*ft_checker_read_input(void);
int		ft_checker_do_instructions(t_stack *a, t_stack *b, char *txt);
int		ft_do_swap_push(t_stack *a, t_stack *b, char *txt);
int		ft_do_rrotate(t_stack *a, t_stack *b, char *txt);
int		ft_do_rotate(t_stack *a, t_stack *b, char *txt);
#endif
