/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple_cases.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:27:59 by jsarda            #+#    #+#             */
/*   Updated: 2024/01/03 16:46:16 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min(t_list *stack)
{
	int	i;

	i = stack->data;
	while (stack)
	{
		if (stack->data < i)
			i = stack->data;
		stack = stack->next;
	}
	return (i);
}

static int	get_max(t_list *stack)
{
	int	i;

	i = stack->data;
	while (stack)
	{
		if (stack->data > i)
			i = stack->data;
		stack = stack->next;
	}
	return (i);
}

static void	sort_3(t_list **stack_a)
{
	if (get_min(*stack_a) == (*stack_a)->data)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (get_max(*stack_a) == (*stack_a)->data)
	{
		ra(stack_a);
		sa(stack_a);
	}
	else
	{

	}
}

void	sort_simple_cases(int argc, t_list **stack_a)
{
	if (argc == 4)
		sort_3(stack_a);
}

// 3 use only 2 action
// 5
// 100
// 500
