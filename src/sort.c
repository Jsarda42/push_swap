/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:27:59 by jsarda            #+#    #+#             */
/*   Updated: 2024/01/16 18:21:52 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_2_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;
	int		median;

	median = get_median(stack_a);
	current = *stack_a;
	current_index(stack_a);
	while (current)
	{
		if (get_min(*stack_a) == current->data && current->index <= median)
		{
			while (*stack_a != current)
				ra(stack_a);
			pb(stack_a, stack_b);
		}
		else if (get_min(*stack_a) == current->data && current->index > median)
		{
			while (*stack_a != current)
				rra(stack_a);
			pb(stack_a, stack_b);
		}
		else
			current = current->next;
	}
}

void	push_till_3(t_list **stack_a, t_list **stack_b)
{
	// as long as there is more than 3 nodes in stack a
	// i will push to b
	// i will push the cheapest node using my function cheapest node
	// that is returning the cheapest node to push
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	int		stack_a_size;
	int		stack_b_size;

	stack_a_size = ft_lstsize(*stack_a);
	stack_b_size = ft_lstsize(*stack_b);
	if (stack_a_size <= 3)
		sort_3(stack_a);
	else
	{
		while (stack_b_size < 2)
		{
			push_2_to_b(stack_a, stack_b);
			stack_b_size++;
		}
		push_till_3(stack_a, stack_b);
	}
}
