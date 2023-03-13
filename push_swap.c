/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:02:59 by mmoramov          #+#    #+#             */
/*   Updated: 2023/03/13 22:19:02 by mmoramov         ###   ########.fr       */
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

void	ft_lstpadd_back(t_piece **lst, t_piece *new)
{
	if (*lst)
		ft_lstplast(*lst)-> next = new;
	else
		*lst = new;
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
	t_piece *current;

    a = NULL; //delete
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

		printf("Size of set is %d", a_stack->length);

        // sort
    }
    //gcc push_swap.c push_swap.a && ./a.out 4 5 7 5
    return(0);
}
