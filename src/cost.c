/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:15:16 by jsarda            #+#    #+#             */
/*   Updated: 2024/01/17 15:16:46 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_cost_in_stack_a(t_list **stack, int median, int stack_size)
{
	t_list	*current;

	current = *stack;
	if (current->index <= median - 1)
		return (current->index);
	else
		return (stack_size - current->index);
}

#include <limits.h>

int	get_distance_to_target(t_list *node_a, t_list *target_b, int stack_size_b)
{
	int	distance_forward;
	int	distance_backward;

	distance_forward = abs(target_b->index - node_a->index);
	distance_backward = stack_size_b - distance_forward;
	return ((distance_forward < distance_backward) ? distance_forward : distance_backward);
}

int	move_cost_in_stack_b(t_list *node_a, t_list **stack_b, int stack_size_b)
{
	int	cost;

	cost = get_distance_to_target(node_a, *stack_b, stack_size_b);
	return (cost);
}

t_list	*cheapest_node(t_list **stack_a, t_list **stack_b, int stack_size_a, int stack_size_b)
{
	t_list	*current;
	t_list	*cheapest;
	int		min_cost;
	int		cost;
	int		median_a;
	int		median_b;

	median_a = get_median(stack_a);
	median_b = get_median(stack_b);
	current = *stack_a;
	cheapest = current;
	min_cost = INT_MAX;
	while (current)
	{
		cost = move_cost_in_stack_a(stack_a, median_a, stack_size_a)
			+ move_cost_in_stack_b(*stack_a, stack_b, stack_size_b);
		if (cost < min_cost)
		{
			min_cost = cost;
			cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}
