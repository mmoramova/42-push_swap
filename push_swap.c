/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:02:59 by mmoramov          #+#    #+#             */
/*   Updated: 2023/03/23 19:43:38 by mmoramov         ###   ########.fr       */
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
		printf("Changes: \n");
		if (a && a->length > 0)
		{
			printf("Size of set a is %d \n", a->length);
			printf("First value of set a is %d \n", a->first->value);
			if (a->length > 1)
				printf("Second value of set a is %d \n", a->first->next->value);
			printf("Last value of set a is %d \n\n", a->last->value);
		}

		if (b && b->length > 0)
		{
			printf("Size of set b is %d \n", b->length);
			printf("First value of set b is %d \n", b->first->value);
			if(b->length > 1)
				printf("Second value of set b is %d \n", b->first->next->value);
			printf("Last value of set b is %d \n\n", b->last->value);
		}
}

t_piece	*ft_lstpnew(int content)
{
	t_piece	*lst;

	lst = (t_piece *) malloc(sizeof(t_piece));
	if (!lst)
		return (NULL);
	lst -> value = content;
	lst -> index = 0; 
	lst -> next = NULL;
	return (lst);
}

int	ft_lstpsize(t_piece *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst -> next;
	}
	return (len);
}

void	ft_lstpadd_front(t_piece **lst, t_piece *new)
{
	new -> next = *lst;
	*lst = new;
}

t_piece	*ft_lstplast(t_piece *lst)
{
	while (lst && lst -> next)
		lst = lst -> next;
	return (lst);
}

t_piece	*ft_lstpbflast(t_piece *lst)
{
	while (lst && lst -> next && lst -> next -> next)
		lst = lst -> next;
	return (lst);
}

void	ft_lstpadd_back(t_piece **lst, t_piece *new)
{
	if (*lst)
		ft_lstplast(*lst)-> next = new;
	else
		*lst = new;
}

void ft_moves_swap(t_stack *a, int i)
{
	int temp_value;
	
	if (a && a->first->next)
	{
		temp_value = a->first->value;
		a->first->value = a->first->next->value;
		a->first->next->value = temp_value;

		temp_value = a->first->index;
		a->first->index = a->first->next->index;
		a->first->next->index = temp_value;
		
		if (i == 1)
		{
			ft_putstr_fd("sa\n",1);
			ft_print_log(a, NULL);
		}
		if (i == 2)
		{	
			ft_putstr_fd("sb\n",1);
			ft_print_log(NULL,a);
		}
	} 
}

void ft_moves_swap_both(t_stack *a, t_stack *b)
{
	ft_moves_swap(a,0);
	ft_moves_swap(b,0);
	ft_putstr_fd("ss\n",1);
	ft_print_log(a,b);
}

void ft_moves_push(t_stack *a, t_stack *b, int i)
{
	t_piece *current;

	current = a->first;
	
	if(a->length > 0)
	{
		a->first = a->first->next;
		if(a->length == 1)
			a->last = NULL;
		ft_lstpadd_front(&b->first,current);
		b->first = current;
		b->last = ft_lstplast(current);

		a->length -= 1;
		b->length += 1;
		
		if (i == 1)
		{
			ft_putstr_fd("pa\n",1);
			ft_print_log(a,b);
		}
		if (i == 2)
		{
			ft_putstr_fd("pb\n",1);
			ft_print_log(b,a);
		}
	}
}

void ft_moves_rotate(t_stack *a, int i)
{
	t_piece *current;

	current = a->first;

	if(a->length > 1)
	{
		a->last->next = current;
		a->first = current->next;
		current->next = NULL;
		a->last = ft_lstplast(a->first);
				
		if (i == 1)
		{
			ft_putstr_fd("ra\n",1);
			ft_print_log(a, NULL);
		}
		if (i == 2)
		{
			ft_putstr_fd("rb\n",1);
			ft_print_log(NULL,a);
		}
	}
}

void ft_moves_rev_rotate(t_stack *a, int i)
{
	t_piece *beforelast;

	beforelast = ft_lstpbflast(a->first);

	if(a->length > 1)
	{
		a->last->next = a->first;
		
		a->first = a->last;
		beforelast->next = NULL;
		a->last = beforelast;

		if (i == 1)
		{
			ft_putstr_fd("rra\n",1);
			ft_print_log(a, NULL);
		}
		if (i == 2)
		{
			ft_putstr_fd("rrb\n",1);
			ft_print_log(NULL,a);
		}
	}
}

void ft_moves_rotate_both(t_stack *a, t_stack *b)
{
	ft_moves_rotate(a,0);
	ft_moves_rotate(b,0);
	ft_putstr_fd("rr\n",1);
}

void ft_moves_rev_rotate_both(t_stack *a, t_stack *b)
{
	ft_moves_rev_rotate(a,0);
	ft_moves_rev_rotate(b,0);
	ft_putstr_fd("rrr\n",1);
}
	
/*
void	ft_lstpiter(t_piece *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst -> index);
		lst = lst -> next;
	}
}

t_piece	*ft_lstpmap(t_piece *lst, void *(*f)(void *), void (*del)(void *))
{
	t_piece	*new;
	t_piece	*current;
	void	*temp;

	new = NULL;
	while (lst)
	{
		temp = f(lst -> index);
		current = ft_lstpnew(temp);
		if (!current)
		{
			ft_lstpclear(&new, del);
			del(temp);
			return (NULL);
		}
		ft_lstpadd_back(&new, current);
		lst = lst -> next;
	}
	return (new);
}*/

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

			printf("number is %s \n", argv[i-1]);
			printf("Current added number is %d \n", current->value);
			printf("Length of the stack is %d \n\n", ft_lstpsize(a));
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

int ft_checks_dup(t_stack *a_stack)
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
	printf("before sort three: %d|%d|%d\n\n", first->index,first->next->index,first->next->next->index);
	if (ft_check_issorted(a_stack,b_stack) == 0 && a_stack->length == 3)
	{
		if(first->index > first->next->index && first->index > first->next->next->index)
		{
			ft_moves_rotate(a_stack,1);
			first = a_stack->first;
			printf("after ra: %d|%d|%d\n\n", first->index,first->next->index,first->next->next->index);
		}
		else if (first->next->index > first->next->next->index)
		{
			ft_moves_rev_rotate(a_stack,1);
			first = a_stack->first;
			printf("after rra: %d|%d|%d\n\n", first->index,first->next->index,first->next->next->index);
		}
		if (first->index > first->next->index)
		{	
			ft_moves_swap(a_stack, 1);
			printf("after ss: %d|%d|%d\n\n", first->index,first->next->index,first->next->next->index);
		}
	}
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

		if (ft_checks_dup(&a_stack) == 1)
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

		return(0);

		ft_moves_rotate(&a_stack,1);
		ft_moves_swap(&a_stack, 1);    
		
		return(0);
		ft_moves_push(&a_stack, &b_stack, 1);
		ft_moves_push(&a_stack, &b_stack, 1);

		ft_moves_swap_both(&a_stack, &b_stack);

		ft_moves_rotate(&a_stack, 1);

		ft_moves_rev_rotate(&a_stack, 2);

		/* LIST
		sa
			ft_moves_swap(&a_stack, 1);
		sb
			ft_moves_swap(&b_stack, 2);
		ss
			ft_moves_swap_both(&a_stack, &b_stack);
		pa
			ft_moves_push(&a_stack, &b_stack);
		pb
			ft_moves_push(&b_stack, &a_stack);
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
		*/
	}

    return(0);
}
