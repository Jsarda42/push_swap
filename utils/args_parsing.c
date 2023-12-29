/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:17:07 by jsarda            #+#    #+#             */
/*   Updated: 2023/12/29 10:37:25 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

int	args_parsing(t_list **stack, int argc, char **argv)
{
	(void)argv;
	if (argc < 2)
		error_message("not enough arguments", stack);
	return (0);
}

// what case do i need to manage for the arguments parsing ?
// 1. Number of Arguments:
		// Checking that the number of arguments passed is sufficient
		// for your program to execute correctly.
		// Handling cases where the number of arguments is insufficient.
// 2 Validating Numeric Inputs:
		// Ensuring that all provided arguments are valid integers.
		// Handling cases where non-numeric characters or invalid input formats are passed.
// 3 Handling Duplicate Numbers:
		// Managing duplicate numbers within the input sequence as per your program's requirements.
		// Deciding whether to handle or disregard duplicates during the sorting process.
// 4 Integer Type Checking:
		// Verifying that the provided numbers are integers and not other types of data.
		// Ensuring they are whole numbers and not floating-point values or other non-integer types.
// 5 Max and Min Integer Values:
		// Checking that the provided integers fall within the range of acceptable integer values.
		// Ensuring they do not exceed the maximum or fall below the minimum integer value
		// supported by your system.
// 6 Handling Positive/Negative Numbers:
		// Managing both positive and negative integers, handling cases where both
		// positive and negative numbers are expected in the input sequence.
