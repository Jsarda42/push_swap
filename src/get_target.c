/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliensarda <juliensarda@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:07:21 by jsarda            #+#    #+#             */
/*   Updated: 2024/01/18 14:34:05 by juliensarda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_target(int current_a_data, t_list **stack_b)
{
	t_list	*current_b;
	t_list	*target;
	int		fit;

	target = NULL;
	current_b = *stack_b;
	if (current_b)
		fit = current_b->data;
	else
		fit = 0;
	while (current_b)
	{
		if (current_a_data > current_b->data)
			if (fit < current_b->data || !target)
			{
				fit = current_b->data;
				target = current_b;
			}
		current_b = current_b->next;
	}
	return (target);
}
