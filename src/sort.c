/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:27:59 by jsarda            #+#    #+#             */
/*   Updated: 2024/01/11 15:47:35 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// i need to define the cheapest move before moving to b
// so i devise the len of the stack to get the median and check if the node is < or >
// if smaller i will move it to top if bigger bottom
// then i need to calculate how many moove it will take to move to the top

int	current_index(t_list **stack)
{
	int		current_position;
	t_list	*current;

	current = *stack;
	current_position = 1;
	while (current)
	{
		if (current == *stack)
		{
			current_position = 1;
			break ;
		}
		current_position++;
		current = current->next;
	}
	return (current_position);
}

int	get_median(t_list **stack)
{
	int	median;
	return (median = ((ft_lstsize(*stack) / 2) + (ft_lstsize(*stack) % 2)));
}

t_bool	move_top_or_bot(t_list **stack)
{
	int	median;
	int		current_position;

	current_position = current_index(stack);
	median = 0;
	if (current_position < median)
		return (true); // top
	else
		return (false); // bot
}

void	move_cost(t_list **stack)
{
	int	cost;
	if (move_top_or_bot(stack))
		cost = current_index(stack) - get_median(stack);
	else
		cost = get_median(stack) - current_index(stack);
	ft_printf("this is the cost : %d\n", cost);
}

// if stack_a number is the biggest in stack b place if on top of stack b biggest
void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	int		stack_b_max;
	t_list	*tmp_b;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	stack_b_max = get_max(*stack_b);
	tmp_b = *stack_b;
	while (tmp_b)
	{
		// case if there is no biggest in b
		if ((*stack_a)->data > stack_b_max && tmp_b->data == stack_b_max)
		{
			// rotate stack_b max to the top
			rb(stack_b);
			// push stack_a above
			pb(stack_a, stack_b);
			// it become new max
			stack_b_max = (*stack_b)->data;
		}
		tmp_b = tmp_b->next;
	}
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	(void)*stack_b;
	if (ft_lstsize(*stack_a) <= 3)
		sort_3(stack_a);
	else
	{
		// push_to_b(stack_a, stack_b);
		// sort_3(stack_a);
		move_cost(stack_a);
		ft_printf("this is my stack_a\n");
		print_stack(*stack_a);
	}
}
