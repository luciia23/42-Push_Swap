# include "push_swap.h"

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

int	get_midpoint(t_stack **a, int size, int *array)
{
	copy_stack(*a, array, size);
	insertion_sort(array, size);
	return (array[(size / 4)]);
}

void    get_array(t_stack **a, int *array_big, int size)
{
    int *array = (int *)malloc(size * sizeof(int));
    copy_stack(*a, array, size);
	insertion_sort(array, size);
    int len = stack_size(*a) - 1;
    int i = 0;
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

int contains_big(int nbr, int *array_big)
{
    int i;

    i = 0;
    while(i < 3)
    {
        if (array_big[i] == nbr)
            return (1);
        i++;
    }
    return (0);
}

void    process_chunks(t_ps *ps, int mid_point, int count, int *array_big)
{
    int bottom;

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

void    push_to_b(t_ps *ps)
{
    int *array;
    int mid_point;
    int count;
    int array_big[3];

    get_array(&ps->a, array_big, stack_size(ps->a));
    while(ps->a->next && stack_size(ps->a) > 3 && !check_sorted(ps->a))
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