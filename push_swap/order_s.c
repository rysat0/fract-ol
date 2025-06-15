/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 12:46:16 by rysato            #+#    #+#             */
/*   Updated: 2025/06/01 15:21:30 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_first_two(t_stack *stack)
{
	int	tmp;

	tmp = 0;
	if (stack->size < 2)
		return ;
	tmp = stack->top->value;
	stack->top->value = stack->top->next->value;
	stack->top->next->value = tmp;
	return ;
}

void	sa(t_stack *stack_a)
{
	write(1, "sa\n", 3);
	swap_first_two(stack_a);
	return ;
}

void	sb(t_stack *stack_b)
{
	write(1, "sb\n", 3);
	swap_first_two(stack_b);
	return ;
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	write(1, "ss\n", 3);
	swap_first_two(stack_a);
	swap_first_two(stack_b);
	return ;
}
