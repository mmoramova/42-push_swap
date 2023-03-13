/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:00:14 by mmoramov          #+#    #+#             */
/*   Updated: 2023/03/13 22:19:04 by mmoramov         ###   ########.fr       */
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
	struct s_piece	*next;
}	t_piece;

typedef struct s_stack
{
	int				length;
	struct s_piece	*first;
	struct s_piece	*last;
}	t_stack;

//int		push_swap(int c);
//int			ft_check_input(char *argv);
#endif
