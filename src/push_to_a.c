# include "push_swap.h"

void	rotate(t_ps *ps, int i)
{
	while (i > 0)
	{
		rb(&ps->b);
		i--;
	}
	pa(&ps->a, &ps->b);
}

void	rrotate(t_ps *ps, int i)
{
	while (i > 0)
	{
		rrb(&ps->b);
		i--;
	}
	pa(&ps->a, &ps->b);
}

void	sorted_array(t_stack *b, int *array, int size)
{
	copy_stack(b, array, size);
	insertion_sort(array, size);
}

void	push_them(t_ps *ps, int *stack, int *array, int total)
{
	int	i;

	i = 0;
	while(i < total)
	{
		if (stack[i] == array[total - 1])
			break ;
		i++;
	}
	if (i == 0)
		pa(&ps->a, &ps->b);
	else if (i < (total / 2))
		rotate(ps, i);
	else
		rrotate(ps, total - i);
	
}

void	push_to_a(t_ps *ps)
{
	int		*stack;
	int		*array;
	int		total;

	total = stack_size(ps->b);
	stack = (int *)malloc(sizeof(int) * total);
	array = (int *)malloc(sizeof(int) * total);
	while(total >= 0)
	{
		copy_stack(ps->b, stack, total);
		sorted_array(ps->b, array, total);
		push_them(ps, stack, array, total);
		total--;
	}
}