/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 17:25:21 by yzungula          #+#    #+#             */
/*   Updated: 2018/09/10 15:42:50 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ops_loop(t_stack **stack_a, t_stack **stack_b)
{
	char	*op;

	op = NULL;
	while (get_next_line(0, &op) > 0)
	{
		if (!valid_op(op))
		{
			ft_putendl("Error");
			ft_strdel(&op);
			return (0);
		}
		perform_op2(stack_a, stack_b, op);
		ft_strdel(&op);
	}
	ft_strdel(&op);
	return (1);
}

int		main(int ac, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	if (check_args(ac, argv) == 0)
	{
		ft_putendl("Error");
		return (0);
	}
	stack_a = make_stack(ac, argv);
	if (ops_loop(&stack_a, &stack_b) == 0)
	{
		delete_stack(&stack_a);
		delete_stack(&stack_b);
		return (0);
	}
	sorted(&stack_a) && is_empty(stack_b) ? ft_putendl("OK") : ft_putendl("KO");
	delete_stack(&stack_a);
	delete_stack(&stack_b);
	return (0);
}
