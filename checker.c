/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 12:37:12 by mmoramov          #+#    #+#             */
/*   Updated: 2023/04/15 13:10:03 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack a_stack;
    t_stack b_stack;

    if (argc > 1) //add instruction doesn’t exist and/or is incorrectly formatted
    {
		if(ft_stack_init(argc, argv, &a_stack, &b_stack) == 1)
		{
			ft_putstr_fd("Error\n", 1);
            //ft_check_free(&a_stack.first); 
            //ft_check_free(&b_stack.first);      
			return(1);
		}
        //citam

        //spravim pokyn podla precitaneho

        //ak docitam pozriem sa ci je sorted ak ano pisem ok inak nie
        if (ft_check_issorted(&a_stack,&b_stack) == 1)
            ft_putstr_fd("OK\n", 1);
        else
            ft_putstr_fd("KO\n", 1);
		//ft_sort(&a_stack, &b_stack); 
        //ft_check_free(&a_stack.first); 
        //ft_check_free(&b_stack.first);
	}
    return(0);
}