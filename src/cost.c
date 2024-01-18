/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliensarda <juliensarda@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:15:16 by jsarda            #+#    #+#             */
/*   Updated: 2024/01/18 15:04:38 by juliensarda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*****************************************************************/
/* i need to define the cheapest node to move to b :			 */
/* the cheapest node will be the cheapest in a + his target cost */
/* to get the cost i need to calculate the cost for each node in */
/* stack_a to move to top and cost of his target in b to move to */
/* top i can use a median to reduce the cost.					 */
/* i need to store the cheapest in a temporary t_list 			 */
/* check each node of a until i find the cheapest one			 */
/*****************************************************************/

int	get_cost(t_list *stack, t_list *current_node)
{
	int	cost;
	
	cost = 0;
	while (current_node != stack)
	{
		cost++;
		current_node = current_node->next;
	}
	return cost;
}

t_list	*cheapest_node(t_list **stack_a, t_list **stack_b)
{
	t_list	*current_a;
	t_list	*cheapest;
	int	final_cost;
	int	total_cost;
	
	current_a = *stack_a;
	cheapest = NULL;
	final_cost = INT_MAX;
	while (current_a)
	{
		current_a->target = get_target(current_a->data, stack_b);
		// i have a seg fault here 
		// int cost_b = get_cost(*stack_b, current_a->target);
		if (*stack_a && current_a && *stack_b && current_a->target) 
			total_cost = get_cost(*stack_a, current_a) + get_cost(*stack_b, current_a->target);
		if (total_cost < final_cost)
		{
			final_cost = total_cost;
			cheapest = current_a;
		}
		current_a = current_a->next;
	}
	return (cheapest);
}