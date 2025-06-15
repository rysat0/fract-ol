/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 21:36:34 by rysato            #+#    #+#             */
/*   Updated: 2025/06/13 21:36:34 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_shortest_a(t_stack *stack_a, int low, int high)
{
	int		ra_idx;
	int		rra_idx;
	t_node	*ref;

	ra_idx = 0;
	rra_idx = 0;
	ref = stack_a->top;
	while (!(ref->value >= low && ref->value <= high))
	{
		ra_idx++;
		ref = ref->next;
	}
	ref = stack_a->top;
	while (!(ref->value >= low && ref->value <= high))
	{
		rra_idx++;
		ref = ref->prev;
	}
	if (ra_idx <= rra_idx)
		return (ra_idx);
	return (-(rra_idx));
}

void	rotate_a(t_stack *a, int low, int span)
{
	int	step;

	step = search_shortest_a(a, low, low + span - 1);
	while (step > 0)
	{
		ra(a);
		step--;
	}
	while (step < 0)
	{
		rra(a);
		step++;
	}
}

static void	transfer_chunk(t_stack *a, t_stack *b, int low, int high)
{
	int	span;
	int	todo;
	int	pushed;

	span = high - low + 1;
	todo = count_remain(a, low, high);
	pushed = 0;
	while (pushed < todo && a->size)
	{
		if (a->top->value >= low && a->top->value <= high)
		{
			pb(a, b);
			pushed++;
			if (b->size > 1 && b->top->value <= low + span / 3)
				rb(b);
		}
		else
			rotate_a(a, low, span);
	}
}

void	push_to_b(t_stack *a, t_stack *b, int span, int k)
{
	int	idx;
	int	low;
	int	high;

	idx = 0;
	while (idx < k && a->size)
	{
		low = idx * span;
		high = low + span - 1;
		transfer_chunk(a, b, low, high);
		idx++;
	}
}

void	chunk_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	span;
	int	chunk_qua;

	chunk_qua = define_chunk_width(stack_a, &span);
	push_to_b(stack_a, stack_b, span, chunk_qua);
	push_to_a(stack_a, stack_b);
}
