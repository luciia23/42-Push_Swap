# include "push_swap.h"

t_chunk *add_chunk(t_chunk **list, int start, int end, int size)
{
	t_chunk *new_chunk;
    
    new_chunk =  (t_chunk *)malloc(sizeof(t_chunk));
	//manejar error
	new_chunk->start = start;
	new_chunk->end = end;
	new_chunk->next = *list;
    if (start == end)
        size = 1;
    new_chunk->size = size;
	return (new_chunk);
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

int	get_midpoint(t_stack **a, int size, int *array)
{
	copy_stack(*a, array, size);
	insertion_sort(array, size);
	return (array[size / 2]);
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

void if_case(t_ps *ps, t_parameters *params)
{
    pb(&ps->a, &ps->b);
    if (*params->count == params->index)
        *params->end = (*params->tmp)->nbr;
    *params->start = (*params->tmp)->nbr;
    (*params->count)--;
}

void else_case(t_ps *ps, t_parameters *params)
{
    int bottom;
    
    bottom = stack_last(*params->tmp)->nbr;
    if (bottom < params->mid_point)
    {
        rra(&ps->a);
        pb(&ps->a, &ps->b);
        if (*params->count == params->index)
            *params->end = bottom;
        (*params->count)--;
        *params->start = bottom;
    } else {
        ra(&ps->a);
    }
}

void    process_chunks(t_ps *ps, t_stack *tmp_a, int *mid_point, int *count)
{
    int start;
    int end;
    int index;

    index = *count;
    start = 0;
    end = 0;
    t_parameters caseParams = {&tmp_a, count, &start, &end, index, *mid_point};
    while (*count > 0 && !check_sorted(ps->a) && stack_size(ps->a) > 3)
    {
        if (tmp_a->nbr < *mid_point)
            if_case(ps, &caseParams);
        else
            else_case(ps, &caseParams);
        tmp_a = ps->a;
    }
    ps->chunk_list = add_chunk(&ps->chunk_list, start, end, index);
    ps->total_chunks++;
}

void    push_to_b(t_ps *ps)
{
    t_stack *tmp_a;
    int     *array;
    int     mid_point;
    int     count;

    tmp_a = ps->a;
    while (tmp_a->next && stack_size(ps->a) > 3 && !check_sorted(ps->a))
    {
        array = (int *)malloc(stack_size(ps->a) * sizeof(int));
        mid_point = get_midpoint(&ps->a, stack_size(ps->a), array);
        count = get_index(mid_point, array, stack_size(ps->a));
        free(array);
        process_chunks(ps, tmp_a, &mid_point, &count);
        tmp_a = ps->a;
    }
    if (!check_sorted(ps->a))
        sort_three(&ps->a);
}