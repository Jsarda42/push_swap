/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:27:59 by jsarda            #+#    #+#             */
/*   Updated: 2024/01/04 15:51:07 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push a to b until there is only 3 left in the stack_a
void	push_to_b_till_3(t_list **stack_a, t_list **stack_b)
{
	int	stack_a_size;

	stack_a_size = ft_lstsize(*stack_a);
	while (stack_a_size > 3 && *stack_a)
	{
		ft_printf("this is the size :%d\n", stack_a_size);
		if (get_max(*stack_a) == (*stack_a)->data)
		{
			pb(stack_a, stack_b);
			stack_a_size--;
		}
		else
		{
			*stack_a = (*stack_a)->next;
		}
	}
}

// sort_b
t_list	**sort_stack_b(t_list **stack_b)
{
	return (stack_b);
}

// sort_a
t_list	**sort_stack_a(t_list **stack_a)
{
	sort_3(stack_a);
	return (stack_a);
}

// sort algo
void	sort(t_list **stack_a, t_list **stack_b)
{
	push_to_b_till_3(stack_a, stack_b);
	sort_stack_a(stack_a);
}
