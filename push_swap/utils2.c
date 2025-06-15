/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:52:14 by rysato            #+#    #+#             */
/*   Updated: 2025/06/04 16:52:14 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_free(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a);
	free(stack_b);
}

int	malloc_initialize_stack(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = malloc(sizeof(t_stack));
	if (*stack_a == NULL)
		return (-1);
	*stack_b = malloc(sizeof(t_stack));
	if (*stack_b == NULL)
	{
		free(*stack_a);
		return (-1);
	}
	(*stack_a)->size = 0;
	(*stack_a)->top = NULL;
	(*stack_b)->size = 0;
	(*stack_b)->top = NULL;
	return (0);
}

void	push_last(t_stack *stack, t_node *target)
{
	t_node	*last;

	if (stack->size == 0)
		stack->top = target;
	else
	{
		last = stack->top->prev;
		target->next = stack->top;
		target->prev = last;
		last->next = target;
		stack->top->prev = target;
	}
	stack->size++;
	return ;
}

int	is_in_chunk(int ref, int low, int span)
{
	if (ref >= low && ref <= low + span - 1)
		return (1);
	return (0);
}

int	define_chunk_width(t_stack *stack_a, int *span)
{
	int	quantity;

	quantity = 1;
	if (stack_a->size <= 150 && quantity)
		quantity = 5;
	else
		quantity = 9;
	*span = ((stack_a->size + quantity - 1) / quantity);
	if (*span == 0)
		*span = 1;
	return (quantity);
}
