/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 13:54:10 by yzungula          #+#    #+#             */
/*   Updated: 2018/09/03 13:54:22 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rotate(t_stack **stack)
{
	t_stack		*first;
	t_stack		*second;
	t_stack		*last;

	first = NULL;
	second = NULL;
	last = NULL;
	if (stack && *stack && (*stack)->next->next)
	{
		first = *stack;
		second = (*stack)->next;
		last = (*stack)->next->next;
		while (last->next)
			last = last->next;
		last->next = first;
		first->next = NULL;
		*stack = second;
	}
	else if (stack && *stack && (*stack)->next)
	{
		second = (*stack)->next;
		second->next = *stack;
		(*stack)->next = NULL;
		*stack = second;
	}
}

void		rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void		reverse_rotate(t_stack **stack)
{
	t_stack		*last;
	t_stack		*sec_last;

	last = NULL;
	sec_last = NULL;
	if (stack && *stack && (*stack)->next && (*stack)->next->next)
	{
		sec_last = (*stack)->next;
		last = (*stack)->next->next;
		while (last->next)
		{
			sec_last = sec_last->next;
			last = last->next;
		}
		last->next = *stack;
		sec_last->next = NULL;
		*stack = last;
	}
	else if (stack && *stack && (*stack)->next)
	{
		last = (*stack)->next;
		last->next = *stack;
		(*stack)->next = NULL;
		*stack = last;
	}
}

void		reverse_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
