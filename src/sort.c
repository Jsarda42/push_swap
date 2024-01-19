/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:27:59 by jsarda            #+#    #+#             */
/*   Updated: 2024/01/19 15:51:53 by jsarda           ###   ########.fr       */
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
		both_rotate(stack_a, stack_b, cheapest);
	else if (!(way_to_move(stack_a, (*stack_a)->pos_a))
		&& !(way_to_move(stack_b, (*stack_a)->pos_b)))
		both_rotate_reverse(stack_a, stack_b, cheapest);
	normal_rotation(stack_a, stack_b);
	pb(stack_a, stack_b);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	int		stack_a_size;
	int		stack_b_size;
	t_list	*current_b;
	t_list *stack_a_target;

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
		current_b = *stack_b;
		if (current_b->data < current_b->next->data)
			sb(stack_b);
		stack_a_size = ft_lstsize(*stack_a);
		while (stack_a_size > 3)
		{
			push_best_to_b(stack_a, stack_b);
			stack_a_size--;
		}
		if (!is_sorted(*stack_a))
			sort_3(stack_a);

		ft_printf("this is the stack a\n");
		print_stack(*stack_a);
		ft_printf("\n");
		ft_printf("this is the stack b\n");
		print_stack(*stack_b);
	}
}
