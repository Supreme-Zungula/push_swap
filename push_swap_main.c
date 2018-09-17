/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 11:51:31 by yzungula          #+#    #+#             */
/*   Updated: 2018/08/30 10:25:40 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int ac, char **argv)
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
	else
		stack_a = make_stack(ac, argv);
	sort_stack(&stack_a, &stack_b);
	delete_stack(&stack_a);
	delete_stack(&stack_b);
	return (0);
}
