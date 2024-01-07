/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollado <lcollado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:48:41 by lcollado          #+#    #+#             */
/*   Updated: 2024/01/07 16:19:00 by lcollado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	copy_stack(t_stack *a, int *array, int size)
{
	int	i;

	i = 0;
	while (i < size && a)
	{
		array[i] = a->nbr;
		a = a->next;
		i++;
	}
}

t_stack	*new_stack(int nbr)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		error();
	new->nbr = nbr;
	new->next = NULL;
	return (new);
}

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	add_back(t_stack **stack, t_stack *new)
{
	if (*stack && new)
		stack_last(*stack)->next = new;
	else
		*stack = new;
}
