/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:35:02 by jsarda            #+#    #+#             */
/*   Updated: 2024/01/04 12:52:02 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

t_bool	is_sorted(t_list *stack_a)
{
	int	i;

	i = stack_a->data;
	while (stack_a)
	{
		if (i > stack_a->data)
			return (false);
		i = stack_a->data;
		stack_a = stack_a->next;
	}
	return (true);
}

int	ft_find_index(t_list *stack, int nbr)
{
	int	i;

	i = 0;
	while (stack->data != nbr)
	{
		i++;
		stack = stack->next;
	}
	stack->index = 0;
	return (i);
}

int	get_min(t_list *stack)
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

int	get_max(t_list *stack)
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
