/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:17:07 by jsarda            #+#    #+#             */
/*   Updated: 2023/12/29 13:23:16 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

// bool	is_valid_int(int argc, char **argv)
// {

// }

bool	is_duplicate(int argc, char **argv)
{
	int	i;
	int	j;
	int num_i;
	int num_j;

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
	// 1. Handling Duplicate Numbers:
	// Check for duplicates and handle them accordingly
	if (is_duplicate(argc, argv))
		error_message("Error : Duplicate numbers detected", stack);
	// 2. Validating Numeric Inputs:
	// Implement logic to check if 'current_arg' is a valid integer
	// if (!is_valid_int(argc, argv))
	// 	error_message("Error : The argument is not a valid integer", stack);
	// 3. Integer Type Checking:
	// Verify if 'current_arg' is an integer and not a non-numeric type
	// 4. Max and Min Integer Values:
	// Check if 'current_arg' falls within the acceptable integer value range
	// 5. Handling Positive/Negative Numbers:
	// Manage positive and negative integers
	// Implement your checks and handling logic here
}
