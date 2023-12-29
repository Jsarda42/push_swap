/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rules.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:11:09 by jsarda            #+#    #+#             */
/*   Updated: 2023/12/29 09:51:11 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

// same has the rotate but this time we rotate the last node with the first node
// to do this we use ft_lstlast to store the last node inside of last
// we define new_last to be the first node of our stack
// then we loop the new_last until we reach the last node of the list
// and set the next to NULL then we add the last to the front of the node
int	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*new_last;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	last = ft_lstlast(*stack);
	new_last = *stack;
	while (new_last->next != last)
		new_last = new_last->next;
	new_last->next = NULL;
	ft_lstadd_front(stack, last);
	return (0);
}

int	rra(t_list **stack_a)
{
	if (reverse_rotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_list **stack_b)
{
	if (reverse_rotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if (reverse_rotate(stack_a) == -1 || reverse_rotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rrr", 1);
	return (0);
}
