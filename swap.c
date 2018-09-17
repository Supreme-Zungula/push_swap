/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 12:55:19 by yzungula          #+#    #+#             */
/*   Updated: 2018/08/25 14:21:31 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap(t_stack **stack)
{
	t_stack		*first;
	t_stack		*second;

	first = *stack;
	second = NULL;
	if (stack && *stack && (*stack)->next)
	{
		second = (*stack)->next;
		first->next = second->next;
		second->next = first;
		*stack = second;
	}
}

void		swap_both(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
