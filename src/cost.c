/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:15:16 by jsarda            #+#    #+#             */
/*   Updated: 2024/01/19 14:00:05 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*****************************************************************/
/* i need to define the cheapest node to move to b :				*/
/* the cheapest node will be the cheapest in a + his target cost */
/* to get the cost i need to calculate the cost for each node in */
/* stack_a to move to top and cost of his target in b to move to */
/* top i can use a median to reduce the cost.						*/
/* i need to store the cheapest in a temporary t_list 				*/
/* check each node of a until i find the cheapest one				*/
/*****************************************************************/

int	get_node_position(t_list *stack, t_list *current_node)
{
	t_list	*head;
	int		pos;

	pos = 1;
	head = stack;
	while (current_node != head)
	{
		pos++;
		head = head->next;
	}
	return (pos);
}
/* if the position of the node is smaller than the median we move top else we move bottom*/
t_bool	way_to_move(t_list **stack, int current_node_pos)
{
	int	median;

	median = get_median(stack);
	if (current_node_pos <= median)
		return (true);
	return (false);
}

/*now to get the cost:
	if we are under the median we do the len - the current_node->node
	poistion - 1 and if we are after the median we do the len
		- current_node->position */
int	get_cost(t_list **stack, int current_node_pos)
{
	int	cost;
	int	len;

	len = ft_lstsize(*stack);
	cost = 0;
	if (way_to_move(stack, current_node_pos))
	{
		if (current_node_pos == 1)
			cost = 0;
		else
			cost = current_node_pos - 1;
	}
	else
	{
		if (current_node_pos == len)
			cost = 1;
		else
			cost = (len - current_node_pos) + 1;
	}
	return (cost);
}

t_list	*cheapest_node(t_list **stack_a, t_list **stack_b)
{
	t_list	*current_a;
	t_list	*cheapest;
	int		final_cost;
	int		total_cost;

	current_a = *stack_a;
	cheapest = NULL;
	final_cost = INT_MAX;
	total_cost = 0;
	while (current_a)
	{
		current_a->target = get_target(current_a->data, stack_b);
		current_a->pos_a = get_node_position(*stack_a, current_a);
		current_a->pos_b = get_node_position(*stack_b, current_a->target);
		total_cost = get_cost(stack_a, current_a->pos_a) + get_cost(stack_b,
				current_a->pos_b);
		if (total_cost < final_cost)
		{
			final_cost = total_cost;
			cheapest = current_a;
		}
		current_a = current_a->next;
	}
	return (cheapest);
}
