/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:17:07 by jsarda            #+#    #+#             */
/*   Updated: 2024/01/04 15:23:57 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

static t_bool	is_valid_int(char *arg)
{
	int		i;
	long	num;

	i = 0;
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	while (arg[i])
	{
		if (arg[i] == ' ')
			i++;
		if (!ft_isdigit(arg[i]))
			return (false);
		i++;
	}
	num = ft_atocoi(arg);
	if (num > INT_MAX || num < INT_MIN)
		return (false);
	arg++;
	return (true);
}

static t_bool	is_duplicate(char **argv)
{
	int	i;
	int	j;
	int	num_i;
	int	num_j;

	i = -1;
	while (argv[++i])
	{
		if (is_valid_int(argv[i]))
		{
			num_i = ft_atocoi(argv[i]);
			j = i + 1;
			while (argv[j])
			{
				if (is_valid_int(argv[j]))
				{
					num_j = ft_atocoi(argv[j]);
					if (num_i == num_j)
						return (true);
				}
				j++;
			}
		}
	}
	return (false);
}

void	args_parsing(t_list **stack, int argc, char **argv)
{
	char	**args;
	int		i;

	i = 0;
	if (argc < 2)
		error_message("Error : Arguments need to be atleast two.", stack);
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		if (is_duplicate(args))
			free_args(argc, stack, args, "Error : Duplicate numbers detected.");
		if (!is_valid_int(args[i]))
			free_args(argc, stack, args,
				"Error : The argument is not a valid integer.");
		i++;
	}
	if (argc == 2)
		ft_free(args);
}
