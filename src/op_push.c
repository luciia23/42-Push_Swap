/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollado <lcollado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:37:50 by lcollado          #+#    #+#             */
/*   Updated: 2023/12/20 11:40:34 by lcollado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_stack(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!*src)
		return (0);
	tmp = *dst;
	*dst = *src;
	*src = (*src)->next;
	(*dst)->next = tmp;
	return (1);
}

void	pb(t_stack **a, t_stack **b)
{
	if (push_stack(&(*a), &(*b)))
		write(1, "pb\n", 3);
}

void	pa(t_stack **a, t_stack **b)
{
	if (push_stack(&(*b), &(*a)))
		write(1, "pa\n", 3);
}
