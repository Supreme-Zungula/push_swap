/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 18:06:55 by yzungula          #+#    #+#             */
/*   Updated: 2018/09/06 18:06:59 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_args(int ac, char **argv)
{
	char	*str;
	char	**vals;

	str = NULL;
	vals = NULL;
	if (ac == 2 && ft_strlen(argv[1]) && !ft_is_spaces_str(argv[1]))
	{
		if (!(str = ft_strjoin("arg ", argv[1])))
			return (0);
		vals = ft_strsplit(str, ' ');
		if (!is_correct(vals))
		{
			ft_strings_del(vals);
			ft_strdel(&str);
			return (0);
		}
		else
		{
			ft_strdel(&str);
			ft_strings_del(vals);
			return (1);
		}
	}
	else
		return (is_correct(argv) ? 1 : 0);
}

char		**split_args(int ac, char **args)
{
	char	**vals;
	char	*str;

	vals = NULL;
	str = NULL;
	if (ac == 2)
	{
		str = ft_strjoin("args ", args[1]);
		vals = ft_strsplit(str, ' ');
		ft_strdel(&str);
	}
	else
		vals = args;
	return (vals);
}
