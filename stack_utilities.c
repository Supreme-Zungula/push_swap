/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 10:26:58 by yzungula          #+#    #+#             */
/*   Updated: 2018/09/01 10:27:02 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_empty(t_stack *stack)
{
	if (stack)
		return (0);
	return (1);
}

int			sorted(t_stack **stack)
{
	t_stack		*curr;
	t_stack		*prev;

	curr = NULL;
	prev = NULL;
	if (stack)
	{
		prev = *stack;
		curr = (*stack)->next;
		while (prev && curr)
		{
			if (curr->data < prev->data)
				return (0);
			curr = curr->next;
			prev = prev->next;
		}
	}
	return (1);
}

void		perform_op(t_stack **stack_a, t_stack **stack_b, char *op)
{
	if (ft_strcmp(op, "sa") == 0)
		swap(stack_a);
	else if (ft_strcmp(op, "sb") == 0)
		swap(stack_b);
	else if (ft_strcmp(op, "ss") == 0)
		swap_both(stack_a, stack_b);
	else if (ft_strcmp(op, "pa") == 0)
		push(stack_a, pop(stack_b));
	else if (ft_strcmp(op, "pb") == 0)
		push(stack_b, pop(stack_a));
	else if (ft_strcmp(op, "ra") == 0)
		rotate(stack_a);
	else if (ft_strcmp(op, "rb") == 0)
		rotate(stack_b);
	else if (ft_strcmp(op, "rr") == 0)
		rotate_both(stack_a, stack_b);
	else if (ft_strcmp(op, "rra") == 0)
		reverse_rotate(stack_a);
	else if (ft_strcmp(op, "rrb") == 0)
		reverse_rotate(stack_b);
	else if (ft_strcmp(op, "rrr") == 0)
		reverse_rotate_both(stack_a, stack_b);
	ft_putendl(op);
}

void		perform_op2(t_stack **stack_a, t_stack **stack_b, char *op)
{
	if (ft_strcmp(op, "sa") == 0)
		swap(stack_a);
	else if (ft_strcmp(op, "sb") == 0)
		swap(stack_b);
	else if (ft_strcmp(op, "ss") == 0)
		swap_both(stack_a, stack_b);
	else if (ft_strcmp(op, "pa") == 0)
		push(stack_a, pop(stack_b));
	else if (ft_strcmp(op, "pb") == 0)
		push(stack_b, pop(stack_a));
	else if (ft_strcmp(op, "ra") == 0)
		rotate(stack_a);
	else if (ft_strcmp(op, "rb") == 0)
		rotate(stack_b);
	else if (ft_strcmp(op, "rr") == 0)
		rotate_both(stack_a, stack_b);
	else if (ft_strcmp(op, "rra") == 0)
		reverse_rotate(stack_a);
	else if (ft_strcmp(op, "rrb") == 0)
		reverse_rotate(stack_b);
	else if (ft_strcmp(op, "rrr") == 0)
		reverse_rotate_both(stack_a, stack_b);
}

void		print_stack(t_stack **stack)
{
	t_stack		*node;

	node = NULL;
	if (stack && *stack)
	{
		node = *stack;
		while (node)
		{
			ft_putchar('[');
			ft_putnbr(node->data);
			ft_putchar(']');
			ft_putstr("->");
			node = node->next;
		}
	}
	ft_putstr("NULL\n");
}
