# include "push_swap.h"

int	check_sorted(t_stack *stack)
{
	int	nbr;

	nbr = stack->nbr;
	while(stack->next)
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

int	check_desc_sorted(t_stack *stack)
{
	int	nbr;

	nbr = stack->nbr;
	while(stack->next)
	{
		if (nbr > stack->next->nbr)
		{
			nbr = stack->next->nbr;
			stack = stack->next;
		}
		else
		return (0);
	}
	return (1);
}

void	insertion_sort(int *array, int size)
{
	int		i;
	int		j;
	int 	key;

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