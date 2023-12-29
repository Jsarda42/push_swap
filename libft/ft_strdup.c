/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:14:11 by jsarda            #+#    #+#             */
/*   Updated: 2023/11/14 11:26:48 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	void	*res;
	size_t	s_len;

	s_len = ft_strlen(s) + 1;
	res = malloc(sizeof(char) * s_len);
	if (!res)
		return (NULL);
	res = ft_memcpy(res, s, s_len);
	return (res);
}
