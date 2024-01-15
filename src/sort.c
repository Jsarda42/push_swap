/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:27:59 by jsarda            #+#    #+#             */
/*   Updated: 2024/01/15 15:35:29 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	get_target(t_list *current_b, t_list *cheapest_a)
{
	if (current_b->data < cheapest_a->data)
		return (true);
	else
		return (false);
}

void	push_to_b(t_list **stack_a, t_list **stack_b)
{

}

void	sort(t_list **stack_a, t_list **stack_b)
{
	int	stack_size;

	(void)*stack_b;
	stack_size = ft_lstsize(*stack_a);
	if (stack_size <= 3)
		sort_3(stack_a);
	else
	{
	}
}
