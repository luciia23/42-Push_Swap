/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollado <lcollado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:42:55 by lcollado          #+#    #+#             */
/*   Updated: 2023/12/20 12:03:58 by lcollado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_midpoint(t_stack **a, int size, int *array)
{
	copy_stack(*a, array, size);
	insertion_sort(array, size);
	return (array[(size / 4)]);
}

void	get_array(t_stack **a, int *array_big, int size)
{
	int	*array;
	int	len;
	int	i;

	array = (int *)malloc(size * sizeof(int));
	len = stack_size(*a) - 1;
	i = 0;
	copy_stack(*a, array, size);
	insertion_sort(array, size);
	while (len >= 0 && i < 3)
	{
		array_big[i] = array[len];
		len--;
		i++;
	}
	free(array);
}

int	get_index(int mid_point, int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == mid_point)
			return (i);
		i++;
	}
	return (-1);
}

void	process_chunks(t_ps *ps, int mid_point, int count, int *array_big)
{
	int	bottom;

	while (count > 0 && !check_sorted(ps->a) && stack_size(ps->a) > 3)
	{
		bottom = stack_last(ps->a)->nbr;
		if (ps->a->nbr < mid_point && !contains_big(ps->a->nbr, array_big))
		{
			pb(&ps->a, &ps->b);
			count--;
		}
		else if (bottom < mid_point && !contains_big(ps->a->nbr, array_big))
		{
			rra(&ps->a);
			pb(&ps->a, &ps->b);
			count--;
		}
		else
			ra(&ps->a);
	}
}

void	push_to_b(t_ps *ps)
{
	int	*array;
	int	mid_point;
	int	count;
	int	array_big[3];

	get_array(&ps->a, array_big, stack_size(ps->a));
	while (ps->a->next && stack_size(ps->a) > 3 && !check_sorted(ps->a))
	{
		array = (int *)malloc(stack_size(ps->a) * sizeof(int));
		mid_point = get_midpoint(&ps->a, stack_size(ps->a), array);
		count = get_index(mid_point, array, stack_size(ps->a));
		free(array);
		process_chunks(ps, mid_point, count, array_big);
	}
	if (!check_sorted(ps->a))
		sort_three(&ps->a);
}
