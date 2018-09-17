/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:56:31 by yzungula          #+#    #+#             */
/*   Updated: 2018/08/30 17:15:33 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			get_smallest(const t_stack *stack_a)
{
	int				smallest;
	const t_stack	*node;

	node = stack_a;
	smallest = node->data;
	while (node)
	{
		if (node->data < smallest)
			smallest = node->data;
		node = node->next;
	}
	return (smallest);
}

int			descending(t_stack **stack)
{
	t_stack		*curr;
	t_stack		*prev;

	if (stack == NULL && *stack == NULL)
		return (0);
	prev = *stack;
	curr = (*stack)->next;
	while (curr)
	{
		if (prev->data < curr->data)
			return (0);
		curr = curr->next;
		prev = prev->next;
	}
	return (1);
}

void		fix_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*first;
	t_stack		*second;
	t_stack		*last;

	first = NULL;
	second = NULL;
	last = NULL;
	while (*stack_b && !descending(stack_b))
	{
		first = *stack_b;
		second = (*stack_b)->next;
		last = (*stack_b)->next;
		while (last && last->next)
			last = last->next;
		if (last->data > first->data)
			perform_op(stack_a, stack_b, "rrb");
		else if (first->data < last->data)
			perform_op(stack_a, stack_b, "rb");
		else if (first->data < second->data && second->data > last->data)
			perform_op(stack_a, stack_b, "sb");
	}
}

void		try_sorting(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*first;
	t_stack		*second;
	t_stack		*last;

	first = NULL;
	second = NULL;
	last = NULL;
	while (!sorted(stack_a))
	{
		first = *stack_a;
		second = (*stack_a)->next;
		last = (*stack_a)->next;
		while (last && last->next)
			last = last->next;
		if (first->data > last->data && first->data < second->data)
			perform_op(stack_a, stack_b, "rra");
		else if (first->data > last->data)
			perform_op(stack_a, stack_b, "ra");
		else if (first->data > second->data)
			perform_op(stack_a, stack_b, "sa");
		else if (first->data < second->data || first->data < last->data)
			perform_op(stack_a, stack_b, "pb");
		fix_stack_b(stack_a, stack_b);
	}
}

void		sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	try_sorting(stack_a, stack_b);
	if (sorted(stack_a) && !is_empty(*stack_b))
	{
		while (!is_empty(*stack_b))
		{
			perform_op(stack_a, stack_b, "pa");
			try_sorting(stack_a, stack_b);
		}
	}
}
