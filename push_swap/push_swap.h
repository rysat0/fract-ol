/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rysato <rysato@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:53:14 by rysato            #+#    #+#             */
/*   Updated: 2025/06/04 16:53:14 by rysato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_node
{
	ssize_t			value;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}			t_stack;

long	ft_atol(const char *str);
void	push_first(t_stack *stack, t_node *target);
t_node	*make_new_node(int value);
int		make_rank(t_stack *stack);
void	put_error_free(int *array);
void	put_error_invalid(void);
int		is_sorted(const t_stack *stack);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	under_five_pattern(t_stack *stack_a, t_stack *stack_b);
void	sort_three_ver4(t_stack *stack_a);
void	sort_three_ver5(t_stack *stack_a);
void	sort_four_ver5(t_stack *stack_a, t_stack *stack_b);
void	chunk_sort(t_stack *stack_a, t_stack *stack_b);
void	push_to_a(t_stack *stack_a, t_stack *stack_b);
void	node_free(t_stack *stack);
void	stack_free(t_stack *stack_a, t_stack *stack_b);
int		malloc_initialize_stack(t_stack **stack_a, t_stack **stack_b);
void	push_last(t_stack *stack, t_node *target);
int		is_in_chunk(int ref, int low, int span);
int		define_chunk_width(t_stack *stack_a, int *span);
int		count_remain(t_stack *a, int low, int high);
