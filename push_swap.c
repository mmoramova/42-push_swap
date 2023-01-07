/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:02:59 by mmoramov          #+#    #+#             */
/*   Updated: 2023/01/07 22:41:19 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int agc, char **agv)
{
    int i;
    t_list *a;
    t_list *b;

    b = NULL;

    i = 0;

    if (agc == 1)
        ft_putstr_fd("Error\n", 1);
    else 
    {
        // check correct input
        // fill a
        // sort
    }
    //gcc push_swap.c push_swap.a && ./a.out 4 5 7 5
    return(0);
}