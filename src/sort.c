/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:27:59 by jsarda            #+#    #+#             */
/*   Updated: 2024/01/17 15:23:11 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list **stack_a, t_list **stack_b)
{
	int		stack_a_size;
	int		stack_b_size;
	t_list	*cheapest;

	stack_a_size = ft_lstsize(*stack_a);
	stack_b_size = ft_lstsize(*stack_b);
	if (stack_a_size <= 3)
		sort_3(stack_a);
	else
	{
		while (stack_b_size < 2)
		{
			pb(stack_a, stack_b);
			stack_b_size++;
		}
		while (stack_a_size < 3)
		{
		}
	}
}
