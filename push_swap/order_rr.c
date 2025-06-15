/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 15:49:37 by rysato            #+#    #+#             */
/*   Updated: 2025/06/01 15:51:22 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rotate_stack(t_stack *stack)
{
	if (stack->size <= 1)
		return (-1);
	stack->top = stack->top->prev;
	return (1);
}

void	rra(t_stack *stack_a)
{
	if (reverse_rotate_stack(stack_a) == -1)
		return ;
	write(1, "rra\n", 4);
	return ;
}

void	rrb(t_stack *stack_b)
{
	if (reverse_rotate_stack(stack_b) == -1)
		return ;
	write(1, "rrb\n", 4);
	return ;
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate_stack(stack_a);
	reverse_rotate_stack(stack_b);
	write(1, "rrr\n", 4);
	return ;
}
