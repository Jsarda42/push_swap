/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:19:24 by jsarda            #+#    #+#             */
/*   Updated: 2024/01/05 16:03:50 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **stack_a)
{
	if (get_min(*stack_a) == (*stack_a)->data)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (get_max(*stack_a) == (*stack_a)->data)
	{
		ra(stack_a);
		if (!is_sorted(*stack_a))
			sa(stack_a);
	}
	else
	{
		if (ft_find_index(*stack_a, get_max(*stack_a)) == 1)
			rra(stack_a);
		else
			sa(stack_a);
	}
}

