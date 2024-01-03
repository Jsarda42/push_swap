/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:35:02 by jsarda            #+#    #+#             */
/*   Updated: 2024/01/03 17:16:21 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	clear_list(t_list **stack)
{
	t_list	*current;
	t_list	*next_node;

	current = *stack;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*stack = NULL;
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}

void	error_message(char *message, t_list **stack)
{
	ft_putendl_fd(message, 1);
	if (stack)
		clear_list(stack);
	exit(EXIT_FAILURE);
}

void	succes_message(char *message, t_list **stack)
{
	ft_putendl_fd(message, 1);
	free_stack(stack);
	exit(EXIT_SUCCESS);
}

int	nothing_to_be_done(t_list **stack)
{
	t_list	*current;

	current = *stack;
	while (current && current->next)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}
