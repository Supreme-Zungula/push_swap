/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 11:20:43 by yzungula          #+#    #+#             */
/*   Updated: 2018/08/30 17:15:40 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct		s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;

void				push(t_stack **stack, t_stack *node);
t_stack				*pop(t_stack **stack);
t_stack				*make_stack(int ac, char **argv);
void				delete_stack(t_stack **stack);
void				print_stack(t_stack **stack);
int					is_empty(t_stack *stack);

void				swap(t_stack **stack);
void				swap_both(t_stack **stack_a, t_stack **stack_b);
void				rotate(t_stack **stack);
void				rotate_both(t_stack **stack_a, t_stack **stack_b);
void				reverse_rotate(t_stack **stack);
void				reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);

void				perform_op(t_stack **stack_a, t_stack **stack_b, char *op);
void				perform_op2(t_stack **stac_a, t_stack **stack_b, char *op);
int					get_smallest(const t_stack *stack);
int					sorted(t_stack **stack);
void				sort_stack(t_stack **stack_a, t_stack **stack_b);

int					check_args(int ac, char **argv);
char				**split_args(int ac, char **args);
int					valid_op(char *op);
int					is_number(char *str);
int					is_correct(char **args);
int					exceeds_int_max(char *str);
int					has_duplicates(char **args);
#endif
