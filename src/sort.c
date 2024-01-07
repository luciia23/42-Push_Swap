/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollado <lcollado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:46:20 by lcollado          #+#    #+#             */
/*   Updated: 2024/01/07 17:01:15 by lcollado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_rest(t_ps *ps)
{
	push_to_b(ps);
	push_to_a(ps);
	free_stack(&ps->b);
}

void	sort_three(t_stack **a)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = (*a)->nbr;
	n2 = (*a)->next->nbr;
	n3 = (*a)->next->next->nbr;
	if (n1 > n2 && n1 > n3)
		ra(a);
	else if (n2 > n1 && n2 > n3)
		rra(a);
	n1 = (*a)->nbr;
	n2 = (*a)->next->nbr;
	if (n1 > n2)
		sa(a);
}

void	print_stacks(t_stack *a, t_stack *b)
{
	printf("STACK A:\n");
	while (a)
	{
		printf("%d\n", a->nbr);
		a = a->next;
	}
	printf("STACK B:\n");
	while (b)
	{
		printf("%d\n", b->nbr);
		b = b->next;
	}
}

void	sort_five(t_ps *ps)
{
	int	min;
	int	max;

	min = find_min(ps->a);
	max = find_max(ps->a);
	while (stack_size(ps->a) > 3)
	{
		if ((ps->a)->nbr == min || (ps->a)->nbr == max)
			pb(&ps->a, &ps->b);
		else
			ra(&ps->a);
	}
	sort_three(&ps->a);
	while (stack_size(ps->b) > 0)
		pa(&ps->a, &ps->b);
}

void	ft_sort(t_stack **a)
{
	t_ps	ps;
	t_stack	*b;

	b = NULL;
	if (stack_size(*a) == 2)
		sa(a);
	if (stack_size(*a) == 3)
		sort_three(a);
	else if (stack_size(*a) == 5)
	{
		ps.b = b;
		ps.a = *a;
		sort_five(&ps);
		sort_rest(&ps);
	}
	else
	{
		ps.b = b;
		ps.a = *a;
		sort_rest(&ps);
	}
}
