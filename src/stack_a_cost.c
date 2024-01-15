/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_cost.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:15:16 by jsarda            #+#    #+#             */
/*   Updated: 2024/01/15 13:38:09 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_list **stack)
{
	t_list	*current;

	current = *stack;
	current->index = 1;
	while (current)
	{
		if (current->next)
			current->next->index = current->index + 1;
		current = current->next;
	}
}

int	get_median(t_list **stack)
{
	int	median;

	return (median = ((ft_lstsize(*stack) / 2) + (ft_lstsize(*stack) % 2)));
}

int	move_cost_in_stack_a(t_list **stack)
{
	t_list	*current;
	int		median;
	int		stack_size;

	median = get_median(stack);
	stack_size = ft_lstsize(*stack);
	current = *stack;
	if (current->index <= median)
		return (current->index - 1);
	else
		return (stack_size - current->index);
}

t_list	*cheapest_in_a(t_list **stack_a)
{
	t_list	*current;
	t_list	*cheapest_node;
	int		cheapest_cost;
	int		cost;

	current = *stack_a;
	cheapest_node = NULL;
	cheapest_cost = INT_MAX;
	while (current)
	{
		cost = move_cost_in_stack_a(stack_a);
		if (cost < cheapest_cost)
		{
			cheapest_cost = cost;
			cheapest_node = current;
		}
		current = current->next;
	}
	return (cheapest_node);
}
