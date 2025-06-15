/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:53:41 by rysato            #+#    #+#             */
/*   Updated: 2025/06/04 16:53:41 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	search_maxrank_index(const t_stack *stack)
{
	int				i;
	int				index;
	int				max_rank;
	const t_node	*ref;

	i = 1;
	index = 0;
	ref = stack->top;
	max_rank = ref->value;
	while (i < stack->size)
	{
		ref = ref->next;
		if (ref->value > max_rank)
		{
			max_rank = ref->value;
			index = i;
		}
		i++;
	}
	return (index);
}

static void	rotate_shortest_b(t_stack *stack, int index)
{
	int	half;

	half = (stack->size / 2);
	if (index <= half)
	{
		while (index > 0)
		{
			rb(stack);
			index--;
		}
	}
	else
	{
		while (index < stack->size)
		{
			rrb(stack);
			index++;
		}
	}
}

void	push_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	index;

	while (stack_b->size != 0)
	{
		index = search_maxrank_index(stack_b);
		if (index != 0)
			rotate_shortest_b(stack_b, index);
		pa(stack_a, stack_b);
	}
}
