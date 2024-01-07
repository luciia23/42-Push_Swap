/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollado <lcollado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:46:54 by lcollado          #+#    #+#             */
/*   Updated: 2024/01/07 17:23:51 by lcollado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_stack *stack)
{
	int	nbr;

	nbr = stack->nbr;
	while (stack->next)
	{
		if (nbr < stack->next->nbr)
		{
			nbr = stack->next->nbr;
			stack = stack->next;
		}
		else
			return (0);
	}
	return (1);
}

void	sorting_array(int *array, int size)
{
	int		i;
	int		j;
	int		key;

	i = 1;
	j = 0;
	while (i < size)
	{
		key = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = key;
		i++;
	}
}

int	find_min(t_stack *src)
{
	int	n;

	n = src->nbr;
	while (src)
	{
		if (n > src->nbr)
			n = src->nbr;
		src = src->next;
	}
	return (n);
}

int	find_max(t_stack *src)
{
	int	n;

	n = src->nbr;
	while (src)
	{
		if (n < src->nbr)
			n = src->nbr;
		src = src->next;
	}
	return (n);
}

int	contains_big(int nbr, int *array_big)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (array_big[i] == nbr)
			return (1);
		i++;
	}
	return (0);
}
