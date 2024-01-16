/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:15:16 by jsarda            #+#    #+#             */
/*   Updated: 2024/01/16 18:19:37 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_cost_in_stack_a(t_list **stack, int median, int stack_size)
{
	t_list	*current;

	current = *stack;
	if (current->index <= median)
		return (current->index - 1);
	else
		return (stack_size - current->index);
}

int	move_cost_in_stack_b(t_list **stack_b, t_list *target)
{
	// i need to define the cost compare to the target in b from a
	// if the target is in the middle for exemple i need to bring it to the top
	// before i push a
	// so i need to know the cost
	// then i will be able to add both cost to define the cheapest node to push
}

t_list	*cheapest_node()
{
	// after i know the cost of both i can add them here to define the
	// cheapest node to move to b
	// then return it.
}
