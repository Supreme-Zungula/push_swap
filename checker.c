/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:57:17 by yzungula          #+#    #+#             */
/*   Updated: 2018/08/30 17:15:44 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		has_duplicates(char **args)
{
	int		i;
	int		j;

	i = 1;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		is_number(char *str)
{
	int		i;

	i = 0;
	if (ft_strlen(str) == 0)
		return (0);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '\0')
		return (0);
	if (ft_strcmp(str, "+0") == 0 || ft_strcmp(str, "-0") == 0)
		return (0);
	if ((str[i] == '-' || str[i] == '+') && !ft_isdigit(str[i + 1]))
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int		exceedes_int_max(char *num_str)
{
	int		num;
	char	*itoa_str;

	num = ft_atoi(num_str);
	itoa_str = ft_itoa(num);
	if (ft_strcmp(num_str, itoa_str) == 0)
	{
		ft_strdel(&itoa_str);
		return (0);
	}
	ft_strdel(&itoa_str);
	return (1);
}

int		is_correct(char **args)
{
	int			len;
	t_stack		*stack;

	len = 1;
	stack = NULL;
	while (args[len])
		len++;
	while (--len >= 1)
	{
		if (!is_number(args[len]) || exceedes_int_max(args[len]))
			return (0);
	}
	if (has_duplicates(args))
		return (0);
	return (1);
}

int		valid_op(char *op)
{
	if (ft_strcmp(op, "sa") == 0)
		return (1);
	else if (ft_strcmp(op, "sb") == 0)
		return (1);
	else if (ft_strcmp(op, "ss") == 0)
		return (1);
	else if (ft_strcmp(op, "pa") == 0)
		return (1);
	else if (ft_strcmp(op, "pb") == 0)
		return (1);
	else if (ft_strcmp(op, "ra") == 0)
		return (1);
	else if (ft_strcmp(op, "rb") == 0)
		return (1);
	else if (ft_strcmp(op, "rr") == 0)
		return (1);
	else if (ft_strcmp(op, "rra") == 0)
		return (1);
	else if (ft_strcmp(op, "rrb") == 0)
		return (1);
	else if (ft_strcmp(op, "rrr") == 0)
		return (1);
	else
		return (0);
}
