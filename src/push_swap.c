/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:17:35 by jsarda            #+#    #+#             */
/*   Updated: 2024/01/03 17:15:49 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ft_lstnew(ft_atocoi(args[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	if (argc == 2)
		ft_free(args);
}

static t_bool	is_sorted(t_list *stack_a)
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

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	t_list	*tmp;

	stack_a = NULL;
	stack_b = NULL;
	args_parsing(stack_a, argc, argv);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	init_stack(stack_a, argc, argv);
	if (is_sorted(*stack_a))
	{
		free_stack(stack_b);
		succes_message("Your list is properly sorted", stack_a);
	}
	sort_simple_cases(argc, stack_a);
	tmp = *stack_a;
	while (tmp)
	{
		ft_printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
