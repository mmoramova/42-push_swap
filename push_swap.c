/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:02:59 by mmoramov          #+#    #+#             */
/*   Updated: 2023/04/10 18:10:51 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int ft_check_input(char *argv)
{
	return(0);
}
*/

void ft_print_log(t_stack *a, t_stack *b)
{
		printf("\nChanges: \n A: ");
		
        int len;
        t_piece *current;
        
         if (a)
         {
            current = a->first;
            len = a->length;

            while (a && len--)
            {
                printf("%d ", current->value);
                current = current->next;
            }
        }

        printf("\n B: ");
        
        if (!b)
            return;
        current = b->first;
        len = b->length;

        while (b && len--)
		{
			printf("%d ", current->value);
            current = current->next;
		}
}

int ft_isnumber(char *str)
{
	int i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && str[i+1])
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return(0);	
		i++;
	}
	return(1);
}

int ft_stack_init(int argc, char **argv, t_stack *a_stack, t_stack *b_stack)
{
	t_piece	*current;
	t_piece	*a;
	int		i;
	
	i = 1;
	a = NULL;

	while (i < argc)
		{
			if (ft_isnumber(argv[i]) == 0)
				return(1);

			current = ft_lstpnew(ft_atoi(argv[i]));
			ft_lstpadd_back(&a, current);
			i++;
		}

		a_stack->first = a;
		a_stack->last = ft_lstplast(a);
		a_stack->length = ft_lstpsize(a);

		b_stack -> first = NULL;
		b_stack -> last = NULL;
		b_stack -> length = 0;

		ft_print_log(a_stack,b_stack);
	return(0);
}

void ft_stack_init_addindex(t_stack *a_stack)
{
	int		i;
	t_piece	*current;
	t_piece *a;
	int		count;

	i = 0;
	current = a_stack->first;

	while (i < a_stack->length)
	{
		a = a_stack->first;
		count = 1;
		while(a)
		{
			if (current -> value > a -> value)
				count++;
			a = a ->next;
		}	
		current -> index = count;	
		current = current->next;
		i++;
	}
}

int ft_check_dup(t_stack *a_stack)
{
	t_piece *lst;
	t_piece *current;

	current = a_stack->first;
	lst = current;

	while(current && current->next)
	{
		lst = current->next;	
		while (lst)
		{
			if (current->value == lst->value)
				return(1);
			lst = lst->next;
		}
		current = current->next;
	}
	return(0);
}

int ft_check_issorted(t_stack *a_stack, t_stack *b_stack)
{
	t_piece *current;

	current = a_stack->first;

	if (b_stack->length != 0)
		return(0);
	while(current && current->next)
	{
		if (current->index > current->next->index)
				return(0);
		current = current->next;
	}
	return(1);
}

void ft_sort_two(t_stack *a_stack, t_stack *b_stack) 
{
	if (ft_check_issorted(a_stack,b_stack) == 0)
		ft_moves_swap(a_stack, 1);
}

void ft_sort_three(t_stack *a_stack, t_stack *b_stack)
{
	t_piece *first;
	
	first = a_stack->first;
	if (ft_check_issorted(a_stack,b_stack) == 0 && a_stack->length == 3)
	{
		if(first->index > first->next->index && first->index > first->next->next->index)
			ft_moves_rotate(a_stack,1);
		else if (first->next->index > first->next->next->index)
			ft_moves_rev_rotate(a_stack,1);
		first = a_stack->first;
		if (first->index > first->next->index)
			ft_moves_swap(a_stack, 1);
	}
}

int ft_find_positon(t_stack *a_stack, int nbr)
{
    int position;
    t_piece *current;

    position = 0;
    current = a_stack->first;

    while (current && current->index != nbr)
    {
        current = current->next;
        position++;
    }
    return(position);
}

int ft_count_moves_a(t_stack *a_stack, int nbr)
{
    int position;
    t_piece *current;

    position = 0;
    current = a_stack->first;

    while (current && current->index != nbr)
    {
        current = current->next;
        position++;
    }
    return(position);
}

int ft_count_moves_b(t_stack *b_stack, int nbr)
{
    int position;
    t_piece *current;

    position = 1;
    current = b_stack->first;

    if (nbr < ft_lst_value_min(b_stack) || nbr > ft_lst_value_max(b_stack))
        return(ft_find_positon(b_stack, ft_lst_value_max(b_stack)));
    while (current && current->next && (current->index < nbr || current->next->index > nbr))
    {
        current = current->next;
        position++;
     }
    
    if (b_stack->length == position)
        return(0);
    return (position);
}

void ft_sort(t_stack *a_stack, t_stack *b_stack)
{
    //1. prve dve dam pb
    // CYKLUS dokym nemam zoradene alebo neostali 3ks
    //1. v stack A pridelim vsade 0
    //2. pridelim vsetkym z A vypocet krokov ako ra + rb + 1x pb
    //3. vyberiem si to cislo kde je najmenenej krokov
    //4. prevediem dane kroky tj x krat ra a x krat rb a pb
    //5. skontrolujem ci prebehlo
    //6. znova

    int i;
    int value;
    //int len;
    //t_piece *current;
    t_piece *a;
    
    a = a_stack->first;
    i = 0;
    value = 0;

    if (ft_check_issorted(a_stack,b_stack) != 1 && a_stack->length > 3)
        ft_moves_push(a_stack, b_stack, 2);
    if (ft_check_issorted(a_stack,b_stack) != 1 && a_stack->length > 3)
        ft_moves_push(a_stack, b_stack, 2);

    while (ft_check_issorted(a_stack,b_stack) != 1 && a_stack->length > 3)
    {
        a = a_stack->first;
        i = 0;
        
        while (a)
        {
            a->numop = ft_count_moves_a(a_stack,a->index) + ft_count_moves_b(b_stack,a->index) + 1;
            a = a -> next;
        }
            
        /*current = a_stack->first;
        len = a_stack->length;

        while (a_stack && len--)
        {
            printf("\n|%d-%d|", current->value, current->numop);
            current = current->next;
        }
        */
        value = ft_lst_value_numopmin(a_stack);
        
        i = ft_count_moves_a(a_stack,value);
        while (i-- > 0)
            ft_moves_rotate(a_stack, 1);

        i = ft_count_moves_b(b_stack,value);
        while (i-- > 0)
            ft_moves_rotate(b_stack, 2);
        ft_moves_push(a_stack, b_stack, 2);


    }
    if (a_stack->length == 3)
		ft_sort_three(a_stack, b_stack);
    ft_print_log(a_stack,b_stack);
    return;
}

int main(int argc, char **argv)
{
    int i;
    t_stack a_stack;
    t_stack b_stack;

    i = 1;

    //if (argc == 1)
      //  ft_putstr_fd("Error\n", 1);
    if (argc > 1)
    {
        // check correct input
		//ft_checks_input(argv);

		if(ft_stack_init(argc, argv, &a_stack, &b_stack) == 1)
		{
			ft_putstr_fd("Error - init, nonnbr", 1);
			//free
			return(1);
		}

		if (ft_check_dup(&a_stack) == 1)
		{
			ft_putstr_fd("Error - dupl\n",1);
			//free;
			return(1);
		}

		ft_stack_init_addindex(&a_stack);
		
		if (ft_check_issorted(&a_stack,&b_stack) == 1)
		{
			//free;
			return(1);
		}
		else if (a_stack.length == 2)
			ft_sort_two(&a_stack, &b_stack);
		else if (a_stack.length == 3)
			ft_sort_three(&a_stack, &b_stack);
        else
            ft_sort(&a_stack, &b_stack);
        
		return(0);

		/* LIST
        make && ./push_swap 2 5 7 1 6 3 9 4 8
        
		sa
			ft_moves_swap(&a_stack, 1);
		sb
			ft_moves_swap(&b_stack, 2);
		ss
			ft_moves_swap_both(&a_stack, &b_stack);
		pa
			ft_moves_push(&a_stack, &b_stack, 1);
		pb
			ft_moves_push(&b_stack, &a_stack, 2);
		ra
			ft_moves_rotate(&a_stack, 1);
		rb
			ft_moves_rotate(&b_stack, 2);
		rr		
			ft_moves_rotate_both(&a_stack, &b_stack);
		ra
			ft_moves_rev_rotate(&a_stack, 1);
		rb
			ft_moves_rev_rotate(&b_stack, 2);
		rrr	
			ft_moves_rev_rotate_both(&a_stack, &b_stack);	

        ARG="4 5 3"; ./push_swap $ARG | ./42Barcelona-PushSwap-ProChecker/pro_checker $ARG	
        ARG=$(ruby -e "puts (0..50).to_a.shuffle.join(' ')"); ./push_swap $ARG |./42Barcelona-PushSwap-ProChecker/pro_checker $ARG 
		*/
	}

    return(0);
}
