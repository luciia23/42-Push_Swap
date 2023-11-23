# include "push_swap.h"

int	get_chunk_midpoint(t_stack **b,int *array, int size)
{
	if (size == 1)
		return (0);
	copy_stack(*b, array, size);
	insertion_sort(array, size);
	return (array[size / 2]);
}

int	get_nbr_left(int mid_point, int *array, int size)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (mid_point == 0)
		return (1);
	while(i < size)
	{
		if (array[i] > mid_point)
			count++;
		i++;
	}
	return (count);
}

void    process_chunk(t_ps *ps, t_stack *tmp_b, int *mid_point, int *count)
{
	t_stack	*tmp_a;
	int		count_rrb;
	int		count_rra;

    while (*count > 0 && ps->chunk_list->size > 2)
    {
		if (tmp_b->nbr > *mid_point && (find_max(ps->b) == tmp_b->nbr))
		{
			if (tmp_b->nbr < tmp_a->nbr)
			{
				pa(&ps->a, &ps->b);
				if (count_rrb > 0)
				{
					while(count_rrb--)
						rrb(&ps->b);
					// act_chunk(*b, *chunk_list, copia - c);
				}
				*count--;
			}
			else if (tmp_b->nbr > tmp_a->nbr)
				ra(&ps->a);
		}
		else
		{
			rb(&ps->b);
			count_rrb++;
		}	
    }
}

void    sort_two(t_ps *ps, t_stack *tmp)
{
    if (!check_chunck_sorted(tmp, ps->chunk_list->size))
        sb(&ps->b);
    pa(&ps->a, &ps->b);
    pa(&ps->a, &ps->b);
}

void	last_chunk(t_ps *ps, t_stack *tmp)
{
	int	*array;
	int	mid_point;
	int	count;

	while(tmp->next && !check_desc_sorted(ps->b))
	{
		array = (int *)malloc(sizeof(int) * ps->chunk_list->size);
		mid_point = get_chunk_midpoint(&ps->b, array, ps->chunk_list->size);
		count = get_nbr_left(mid_point, array, ps->chunk_list->size);
		free(array);

	}
}

void    push_to_a(t_ps *ps)
{
	t_stack *tmp_b;
	int     *array;
	int     mid_point;
	int     count;

	tmp_b = ps->b;
	while  (tmp_b->next && ps->total_chunks > 1 && !check_desc_sorted(ps->b))
	{
		array = (int *)malloc(sizeof(int) * ps->chunk_list->size);
		mid_point = get_chunk_midpoint(&ps->b, array, ps->chunk_list->size);
		count = get_nbr_left(mid_point, array, ps->chunk_list->size);
		free(array);
		process_chunk(ps, tmp_b, &mid_point, &count);
		if (ps->chunk_list->size == 2)
			sort_two(ps, tmp_b);
		else if (ps->chunk_list->size == 1)
			pa(&ps->a, &ps->b);
		ps->chunk_list = ps->chunk_list->next;
		ps->total_chunks--;
		tmp_b = ps->b;
	}
	//chunk sorted or stack sorted?
	if (ps->total_chunks == 1 && !check_desc_sorted(ps->b))
		last_chunk(ps, tmp_b);
	if (check_desc_sorted(ps->b))
		push_them_all();
}