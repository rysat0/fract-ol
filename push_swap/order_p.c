/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:08:05 by rysato            #+#    #+#             */
/*   Updated: 2025/06/01 15:21:30 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*pop_first(t_stack *stack)
{
	t_node	*target;
	t_node	*last;

	if (stack->size == 0)
		return (NULL);
	target = stack->top;
	if (stack->size == 1)
		stack->top = NULL;
	else
	{
		last = target->prev;
		stack->top = target->next;
		stack->top->prev = last;
		last->next = stack->top;
	}
	stack->size--;
	target->next = target;
	target->prev = target;
	return (target);
}

void	push_first(t_stack *stack, t_node *target)
{
	t_node	*last;

	if (stack->size == 0)
		stack->top = target;
	else
	{
		last = stack->top->prev;
		target->next = stack->top;
		target->prev = last;
		stack->top->prev = target;
		last->next = target;
		stack->top = target;
	}
	stack->size++;
	return ;
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*target;

	target = pop_first(stack_b);
	if (target == NULL)
		return ;
	push_first(stack_a, target);
	write(1, "pa\n", 3);
	return ;
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*target;

	target = pop_first(stack_a);
	if (target == NULL)
		return ;
	push_first(stack_b, target);
	write(1, "pb\n", 3);
	return ;
}
