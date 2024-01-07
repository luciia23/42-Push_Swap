/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollado <lcollado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:31:54 by lcollado          #+#    #+#             */
/*   Updated: 2024/01/07 16:33:22 by lcollado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_whitespace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

long int	process_digits(const char *str, unsigned int *i)
{
	long int	result;

	result = 0;
	while (str[*i])
	{
		if (!is_digit(str[*i]))
			error();
		result *= 10;
		result += str[*i] - '0';
		(*i)++;
	}
	return (result);
}

int	ft_atoi_ps(const char *str)
{
	unsigned int	i;
	long int		sign;
	long int		result;

	i = 0;
	sign = 1;
	result = 0;
	while (is_whitespace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	result = process_digits(str, &i);
	if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
		error();
	return ((int)(result * sign));
}
