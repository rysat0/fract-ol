/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 15:00:03 by rysato            #+#    #+#             */
/*   Updated: 2025/06/01 15:51:18 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate_stack(t_stack *stack)
{
	if (stack->size <= 1)
		return (-1);
	stack->top = stack->top->next;
	return (1);
}

void	ra(t_stack *stack_a)
{
	if (rotate_stack(stack_a) == -1)
		return ;
	write(1, "ra\n", 3);
	return ;
}

void	rb(t_stack *stack_b)
{
	if (rotate_stack(stack_b) == -1)
		return ;
	write(1, "rb\n", 3);
	return ;
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate_stack(stack_a);
	rotate_stack(stack_b);
	write(1, "rr\n", 3);
	return ;
}
