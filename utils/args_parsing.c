/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:17:07 by jsarda            #+#    #+#             */
/*   Updated: 2023/12/29 13:50:22 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

bool	is_valid_int(int argc, char **argv)
{
	char	*current_arg;
	int		i;
	long	num;

	i = 1;
	while (i < argc)
	{
		current_arg = argv[i];
		if (*current_arg == '+' || *current_arg == '-')
			current_arg++;
		while (*current_arg)
		{
			if (!ft_isdigit(*current_arg))
				return (false);
			current_arg++;
		}
		num = ft_atoi(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (false);
		i++;
	}
	return (true);
}

bool	is_duplicate(int argc, char **argv)
{
	int	i;
	int	j;
	int	num_i;
	int	num_j;

	if (argc < 3)
		return (false);
	i = 1;
	while (i < argc - 1)
	{
		num_i = ft_atoi(argv[i]);
		j = i + 1;
		while (j < argc)
		{
			num_j = ft_atoi(argv[j]);
			if (num_i == num_j)
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

void	args_parsing(t_list **stack, int argc, char **argv)
{
	if (argc < 2)
		error_message("Error", stack);
	if (is_duplicate(argc, argv))
		error_message("Error : Duplicate numbers detected", stack);
	if (!is_valid_int(argc, argv))
		error_message("Error : The argument is not a valid integer", stack);
	// 4. Max and Min Integer Values:
	// Check if 'current_arg' falls within the acceptable integer value range
	// 5. Handling Positive/Negative Numbers:
	// Manage positive and negative integers
	// Implement your checks and handling logic here
}
