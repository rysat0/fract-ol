/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 21:31:06 by rysato            #+#    #+#             */
/*   Updated: 2025/06/13 21:31:52 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_remain(t_stack *a, int low, int high)
{
	int		cnt;
	int		i;
	t_node	*cur;

	cnt = 0;
	i = 0;
	cur = a->top;
	while (i++ < a->size)
	{
		if (cur->value >= low && cur->value <= high)
			cnt++;
		cur = cur->next;
	}
	return (cnt);
}
