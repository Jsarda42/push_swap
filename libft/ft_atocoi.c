/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atocoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:41:14 by jsarda            #+#    #+#             */
/*   Updated: 2024/01/04 13:53:05 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*skip_whitespace(const char *str)
{
	while (*str && (*str == ' ' || (*str >= 9 && *str <= 13)))
		str++;
	return (str);
}

static long	ft_atoi(const char *str, int sign)
{
	long	number;

	number = 0;
	while (ft_isdigit(*str))
	{
		if (number > (INT_MAX - (*str - '0')) / 10)
			return (2147483648);
		number = (number * 10) + (*str - '0');
		str++;
	}
	return (number * sign);
}

long	ft_atocoi(const char *str)
{
	long	sign;

	sign = 1;
	str = skip_whitespace(str);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		else
			sign = 1;
		str++;
	}
	return (ft_atoi(str, sign));
}
