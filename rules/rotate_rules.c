/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 10:24:18 by jsarda            #+#    #+#             */
/*   Updated: 2023/12/28 15:31:28 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

// we make a function to rotate the first node with the last node
// we then initialise the head with the first node of the stack
// then the first node of our stack become the second one
// the head next should now become NULL this mean the head is now the last node
// we then add back the head at the back of our stack
int	rotate(t_list **stack)
{
	t_list	*head;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	*stack = head->next;
	head->next = NULL;
	ft_lstadd_back(stack, head);
	return (0);
}

// ra and rb are going to rotate for there respective list
// we make sure there atleast 2 node and print the action we made
int	ra(t_list **stack_a)
{
	if (rotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	rb(t_list **stack_b)
{
	if (rotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rb", 1);
	return (0);
}

// and for rr we just make sure they both have enought node
// and rotate for both stack
// then print the action on the fd
int	rr(t_list **stack_a, t_list **stack_b)
{
	if (rotate(stack_a) == -1 || rotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rr", 1);
	return (0);
}
