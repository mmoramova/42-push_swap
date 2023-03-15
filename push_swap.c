/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:02:59 by mmoramov          #+#    #+#             */
/*   Updated: 2023/03/15 20:25:06 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int ft_check_input(char *argv)
{
	return(0);
}

int ft_fill_stack(int argc, t_stack *a)
{
	return(0);
}
*/
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

t_stack	*ft_lstsnew()
{
	t_stack	*lst;

	lst = (t_stack *) malloc(sizeof(t_stack));
	if (!lst)
		return (NULL);
	lst -> length = 0;
	lst -> first = NULL;
	lst -> last = NULL;
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

void ft_moves_swap(t_piece *lst)
{
	int temp_value;
	
	if (lst && lst->next)
	{
		temp_value = lst->value;
		lst->value = lst->next->value;
		lst->next->value = temp_value;
		//write sa/sb;
	}
}

void ft_moves_swap_both(t_piece *a, t_piece *b)
{
	ft_moves_swap(a);
	ft_moves_swap(b);
	//write ss;
}

void ft_moves_push(t_stack *a, t_stack *b)
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

		printf("Changes after pa\n");
		printf("Size of set a is %d \n", a->length);
		printf("First value of set a is %d \n", a->first->value);
		printf("Second value of set a is %d \n", a->first->next->value);
		printf("Last value of set a is %d \n\n", a->last->value);
	
		printf("Size of set b is %d \n", b->length);
		printf("First value of set b is %d \n", b->first->value);
		//printf("Second value of set b is %d \n", b->first->next->value);
		printf("Last value of set b is %d \n\n", b->last->value);
	}
}

void ft_moves_rotate(t_stack *a)
{
	t_piece *current;

	current = a->first;

	if(a->length > 1)
	{
		a->last->next = current;
		a->first = current->next;
		current->next = NULL;
		a->last = ft_lstplast(a->first);
		
		printf("Changes after rr\n");
		printf("Size of set a is %d \n", a->length);
		printf("First value of set a is %d \n", a->first->value);
		printf("Second value of set a is %d \n", a->first->next->value);
		printf("Last value of set a is %d \n\n", a->last->value);
		//write ra/rb
	}
}

void ft_moves_rev_rotate(t_stack *a)
{
	t_piece *beforelast;

	beforelast = ft_lstpbflast(a->first);

	if(a->length > 1)
	{
		a->last->next = a->first;
		
		a->first = a->last;
		beforelast->next = NULL;
		a->last = beforelast;

		printf("Changes after reverse rr\n");
		printf("Size of set a is %d \n", a->length);
		printf("First value of set a is %d \n", a->first->value);
		printf("Second value of set a is %d \n", a->first->next->value);
		printf("Last value of set a is %d \n\n", a->last->value);
		//write rra/rrb
	}
}

void ft_moves_rotate_both(t_stack *a, t_stack *b)
{
	ft_moves_rotate(a);
	ft_moves_rotate(b);
	//write rr;
}

void ft_moves_rev_rotate_both(t_stack *a, t_stack *b)
{
	ft_moves_rev_rotate(a);
	ft_moves_rev_rotate(b);
	//write rrr;
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

int main(int argc, char **argv)
{
    int i;
    t_stack *a_stack;
    t_stack *b_stack;
	t_piece *a;
	t_piece *b;
	t_piece *current;

    a = NULL; //delete
	b = NULL;
	a_stack = NULL;
	b_stack = NULL;

    i = 1;

    //if (argc == 1)
      //  ft_putstr_fd("Error\n", 1);
    if (argc > 1)
    {
        // check correct input
		//ft_check_input(*argv);

        //fill a
		while (i < argc)
		{
			//continue;
			printf("number is %s \n", argv[i]);
			
			current = ft_lstpnew(ft_atoi(argv[i]));
			printf("Current added number is %d \n", current->value);
			
			ft_lstpadd_back(&a, current);
			printf("Length of the stack is %d \n\n", ft_lstpsize(a));
			i++;
		}
		a_stack = ft_lstsnew();
		a_stack->length = ft_lstpsize(a);
		a_stack->first = a;
		a_stack->last = ft_lstplast(a);

		b_stack = ft_lstsnew();

		printf("Size of set a is %d \n", a_stack->length);
		printf("First value of set a is %d \n", a_stack->first->value);
		printf("Second value of set a is %d \n", a_stack->first->next->value);
		printf("Last value of set a is %d \n\n", a_stack->last->value);

        // sort
		// sa
		ft_moves_swap(a);

		printf("Changes after sa\n");
		printf("Size of set a is %d \n", a_stack->length);
		printf("First value of set a is %d \n", a_stack->first->value);
		printf("Second value of set a is %d \n", a_stack->first->next->value);
		printf("Last value of set a is %d \n\n", a_stack->last->value);
    
		ft_moves_swap_both(a, b);

		printf("Changes after ss\n");
		printf("Size of set a is %d \n", a_stack->length);
		printf("First value of set a is %d \n", a_stack->first->value);
		printf("Second value of set a is %d \n", a_stack->first->next->value);
		printf("Last value of set a is %d\n\n", a_stack->last->value);

		ft_moves_push(a_stack, b_stack);

		ft_moves_rotate(a_stack);

		ft_moves_rev_rotate(a_stack);
	}
    //gcc push_swap.c push_swap.a && ./a.out 4 5 7 5
    return(0);
}
