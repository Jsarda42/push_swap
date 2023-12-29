/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 10:59:26 by jsarda            #+#    #+#             */
/*   Updated: 2023/12/29 11:04:19 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

// function to swap the first node with the second node
// if the size of the list is smaller than 2this mean the list only have 1 node
// we initialise the head
// we initialise next
// we store the data of the head inside a temporary variable
// we store the index inside of a temp variable
// then we swap the data and index of the head and the next
int	swap(t_list **stack)
{
	t_list	*head;
	t_list	*next;
	int		tmp_val;
	int		tmp_index;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	next = head->next;
	if (!head && !next)
		error_message("Error", stack);
	tmp_val = head->data;
	tmp_index = head->index;
	head->data = next->data;
	head->index = next->index;
	next->data = tmp_val;
	next->index = tmp_index;
	return (0);
}
// sa and sb functions will swap inside of their
// respective stack using our swap function
// we then use the function putendl_fd to write
// the action we made to the fd choosen follow by a \n

int	sa(t_list **stack_a)
{
	if (swap(stack_a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_list **stack_b)
{
	if (swap(stack_b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}
// ss function will do this for both stack a and b
// we making sur both list have 2 elements before swapping them

int	ss(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (-1);
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
	return (0);
}
