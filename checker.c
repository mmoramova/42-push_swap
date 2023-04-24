/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 12:37:12 by mmoramov          #+#    #+#             */
/*   Updated: 2023/04/23 17:08:07 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_checker_read_input(void)
{
	char	*txt;
	char	*line;

	txt = NULL;
	line = "begin";
	while (line != NULL)
	{
		line = NULL;
		line = get_next_line(0);
		if (line != NULL)
		txt = ft_gnl_strjoin(txt, line);
		free(line);
	}
	return (txt);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	*txt;

	if (argc > 1)
	{
		if (ft_stack_init(argv, &a, &b) == 1)
		{
			ft_putstr_fd("Error\n", 1);
			return (1);
		}
		txt = ft_checker_read_input();
		if (ft_checker_do_instructions(&a, &b, txt) == 1)
			return (1);
		if (ft_check_issorted(&a, &b) == 1)
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
		ft_lst_free(&a.first, &b.first);
		ft_gnl_free(&txt);
	}
	return (0);
}
