/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:27:59 by jsarda            #+#    #+#             */
/*   Updated: 2024/01/05 16:52:48 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b_till_3(t_list **stack_a, t_list **stack_b)
{
	int	stack_size_a;
	// int		max_value;
	// int		index;
	// t_list	*current;
	stack_size_a = ft_lstsize(*stack_a);
	while (stack_size_a > 3 && *stack_a)
	{
		pb(stack_a, stack_b);
		// max_value = get_min(*stack_a);
		// index = 0;
		// current = *stack_a;
		// while (current && current->data != max_value)
		// {
		// 	current = current->next;
		// 	index++;
		// }
		// if (index > stack_size / 2)
		// 	while ((*stack_a)->data != max_value)
		// 		rra(stack_a);
		// else
		// 	while ((*stack_a)->data != max_value)
		// 		ra(stack_a);
		stack_size_a--;
	}
	while (*stack_b)
	{
		ft_printf("the stack b is :%d\n", (*stack_b)->data);
		*stack_b = (*stack_b)->next;
	}
}

void	push_back_to_a(t_list **stack_a, t_list **stack_b)
{
	if (*stack_b == NULL)
		return ;
	while (*stack_b)
		pa(stack_b, stack_a);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	// if (ft_lstsize(*stack_a) > 3)
	// {
	push_to_b_till_3(stack_a, stack_b);
	// 	if (!is_sorted(*stack_a))
	// 		sort_3(stack_a);
	// 	push_back_to_a(stack_a, stack_b);
	// }
	// else if (!is_sorted(*stack_a))
	// 	sort_3(stack_a);
}
