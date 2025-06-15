/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:52:57 by rysato            #+#    #+#             */
/*   Updated: 2025/06/04 16:52:57 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*array_copy(t_stack *stack)
{
	int		*array;
	ssize_t	i;
	t_node	*ref;

	i = 0;
	array = malloc(sizeof(int) * stack->size);
	if (array == NULL)
		return (NULL);
	ref = stack->top;
	while (i < stack->size)
	{
		array[i] = ref->value;
		ref = ref->next;
		i++;
	}
	return (array);
}

static int	sort_and_dupli_check(int *array, t_stack *stack)
{
	ssize_t	i;
	ssize_t	j;
	int		tmp;

	i = 0;
	tmp = 0;
	while (i < stack->size)
	{
		j = i;
		while (j > 0 && array[j] < array[j - 1])
		{
			tmp = array[j];
			array[j] = array[j - 1];
			array[j - 1] = tmp;
			j--;
		}
		if (j > 0 && array[j] == array[j - 1])
			return (-1);
		i++;
	}
	return (0);
}

static ssize_t	search_rank(int value, int *array)
{
	ssize_t	rank;

	rank = 0;
	while (value != array[rank])
		rank++;
	return (rank);
}

static void	change_to_rank(t_stack *stack, int *array)
{
	ssize_t	i;
	t_node	*ref;

	ref = stack->top;
	i = 0;
	while (i < stack->size)
	{
		ref->value = search_rank(ref->value, array);
		i++;
		ref = ref->next;
	}
}

int	make_rank(t_stack *stack)
{
	int	*array;

	array = array_copy(stack);
	if (array == NULL)
	{
		put_error_invalid();
		return (-1);
	}
	if (sort_and_dupli_check(array, stack) == -1)
	{
		put_error_free(array);
		return (-1);
	}
	change_to_rank(stack, array);
	free(array);
	return (0);
}
