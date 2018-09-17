/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 14:07:37 by yzungula          #+#    #+#             */
/*   Updated: 2018/08/29 17:17:57 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push(t_stack **stack, t_stack *node)
{
	if (node)
	{
		node->next = *stack;
		*stack = node;
	}
}

t_stack		*pop(t_stack **stack)
{
	t_stack	*node;

	node = NULL;
	if (*stack)
	{
		node = *stack;
		*stack = (*stack)->next;
		node->next = NULL;
	}
	return (node);
}

void		delete_stack(t_stack **stack)
{
	t_stack		*node;

	node = NULL;
	if (*stack)
	{
		while (*stack)
		{
			node = *stack;
			*stack = (*stack)->next;
			node->next = NULL;
			free(node);
		}
		*stack = NULL;
		stack = NULL;
	}
}

t_stack		*get_stack(int ac, char **args)
{
	t_stack		*stack;
	t_stack		*node;
	int			size;

	size = ac;
	stack = NULL;
	node = NULL;
	if (size == 2)
	{
		while (args[size])
			size++;
	}
	while (--size >= 1)
	{
		if (!(node = (t_stack *)malloc(sizeof(t_stack))))
		{
			delete_stack(&stack);
			return (NULL);
		}
		node->data = ft_atoi(args[size]);
		node->next = NULL;
		push(&stack, node);
	}
	return (stack);
}

t_stack		*make_stack(int ac, char **argv)
{
	t_stack		*stack;
	char		**vals;
	int			i;

	stack = NULL;
	vals = NULL;
	i = 0;
	if (ac == 2)
	{
		vals = split_args(ac, argv);
		stack = get_stack(ac, vals);
		ft_strings_del(vals);
	}
	else
		stack = get_stack(ac, argv);
	return (stack);
}
