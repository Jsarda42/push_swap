/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:27:59 by jsarda            #+#    #+#             */
/*   Updated: 2024/01/22 15:44:34 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// if they both top median
void	both_rotate(t_list **stack_a, t_list **stack_b, t_list *cheapest)
{
	while (*stack_a != cheapest && *stack_b != cheapest->target)
		rr(stack_a, stack_b);
}

// if they both bot median
void	both_rotate_reverse(t_list **stack_a, t_list **stack_b,
		t_list *cheapest)
{
	while (*stack_a != cheapest && *stack_b != cheapest->target)
		rrr(stack_a, stack_b);
}

// normal rotation
void	normal_rotation(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest;

	cheapest = cheapest_node(stack_a, stack_b);
	while (*stack_a != cheapest)
	{
		if (way_to_move(stack_a, (*stack_a)->pos_a))
			ra(stack_a);
		else
			rra(stack_a);
	}
	while (*stack_b != cheapest->target)
	{
		if (way_to_move(stack_b, (*stack_a)->pos_b))
			rb(stack_b);
		else
			rrb(stack_b);
	}
}

void	push_best_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest;

	cheapest = cheapest_node(stack_a, stack_b);
	if (way_to_move(stack_a, (*stack_a)->pos_a) && way_to_move(stack_b,
			(*stack_a)->pos_b))
		// if they both on top of median rotate together
		both_rotate(stack_a, stack_b, cheapest);
	else if (!(way_to_move(stack_a, (*stack_a)->pos_a))
		&& !(way_to_move(stack_b, (*stack_a)->pos_b)))
		// if they both under the median rotate reverse
		both_rotate_reverse(stack_a, stack_b, cheapest);
	normal_rotation(stack_a, stack_b);
	pb(stack_a, stack_b);
}

t_list	*get_min_target(t_list *stack)
{
	t_list	*min;

	min = stack;
	while (stack)
	{
		if (stack < min)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_list	*get_target_closest_bigger(int current_a_data, t_list **stack)
{
	t_list	*current;
	t_list	*target;
	int		fit;

	target = NULL;
	current = *stack;
	if (current)
		fit = current->data;
	else
		fit = 0;
	while (current)
	{
		if (current_a_data < current->data)
		{
			if (fit > current->data || !target)
			{
				fit = current->data;
				target = current;
			}
		}
		current = current->next;
	}
	if (!target)
		target = get_min_target(*stack);
	return (target);
}

void	push_back_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*target;

	target = get_target_closest_bigger((*stack_b)->data, stack_a);
	while (*stack_a != target)
	{
		if (way_to_move(stack_a, (*stack_a)->pos_a))
			ra(stack_a);
		else
			rra(stack_a);
	}
	pa(stack_b, stack_a);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	int stack_a_size;
	int stack_b_size;
	t_list *current_b;

	stack_a_size = ft_lstsize(*stack_a);
	stack_b_size = ft_lstsize(*stack_b);
	current_b = NULL;
	if (stack_a_size <= 3)
		sort_3(stack_a);
	else
	{
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
		if (*stack_b < (*stack_b)->next)
			sb(stack_b);
		stack_a_size = ft_lstsize(*stack_a);
		while (stack_a_size > 3)
		{
			push_best_to_b(stack_a, stack_b);
			stack_a_size--;
		}
		if (!is_sorted(*stack_a))
		 		sort_3(stack_a);
		while (get_max(*stack_b) != (*stack_b)->data)
		 		rb(stack_b);
		// // 	while (*stack_b)
		// // 		push_back_to_a(stack_a, stack_b);
		}
		while (*stack_a)
		{
			ft_printf("this is the stack a : %d\n", (*stack_a)->data);
			*stack_a = (*stack_a)->next;
		}
		if (!*stack_b)
			ft_printf("the stack_b is empty");
		ft_printf("\n");
		while (*stack_b)
		{
			ft_printf("this is the stack b : %d\n", (*stack_b)->data);
			*stack_b = (*stack_b)->next;
		}
	}
