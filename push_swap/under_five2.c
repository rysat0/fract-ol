/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_five2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:52:39 by rysato            #+#    #+#             */
/*   Updated: 2025/06/04 16:52:39 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_four_ver5(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*ref;

	ref = stack_a->top;
	if (ref->value == 1)
		pb(stack_a, stack_b);
	else if (ref->prev->value == 1)
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	else
	{
		while (stack_a->top->value != 1)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	sort_three_ver5(stack_a);
	pa(stack_a, stack_b);
}

void	sort_three_ver5(t_stack *stack_a)
{
	t_node	*ref;

	ref = stack_a->top;
	if (ref->value == 2 || ref->next->value == 4)
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
	else if (ref->value == 3 && ref->next->value == 2)
		sa(stack_a);
	else if (ref->value == 3 && ref->next->value == 4)
		rra(stack_a);
	else if (ref->value == 4 && ref->next->value == 2)
		ra(stack_a);
	else if (ref->value == 4 && ref->next->value == 3)
	{
		sa(stack_a);
		rra(stack_a);
	}
}

void	sort_three_ver4(t_stack *stack_a)
{
	t_node	*ref;

	ref = stack_a->top;
	if (ref->value == 1 || ref->next->value == 3)
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
	else if (ref->value == 2 && ref->next->value == 1)
		sa(stack_a);
	else if (ref->value == 2 && ref->next->value == 3)
		rra(stack_a);
	else if (ref->value == 3 && ref->next->value == 1)
		ra(stack_a);
	else if (ref->value == 3 && ref->next->value == 2)
	{
		sa(stack_a);
		rra(stack_a);
	}
}
