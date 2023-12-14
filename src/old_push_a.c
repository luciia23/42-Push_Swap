// int	get_chunk_midpoint(t_stack **b,int *array, int size)
// {
// 	if (size == 1)
// 		return (0);
// 	copy_stack(*b, array, size);
// 	insertion_sort(array, size);
// 	return (array[size / 4]);
// }

// int	get_nbr_left(int mid_point, int *array, int size)
// {
// 	int	count;
// 	int	i;

// 	count = 0;
// 	i = 0;
// 	if (mid_point == 0)
// 		return (1);
// 	while(i < size)
// 	{
// 		if (array[i] > mid_point)
// 			count++;
// 		i++;
// 	}
// 	return (count);
// }

// void	act_chunk(t_stack *b, t_chunk *chunk_list, int size)
// {
// 	chunk_list->start = b->nbr;
// 	chunk_list->size = size;
// 	while(b->next && (size - 1) > 0)
// 	{
// 		b = b->next;
// 		size--;
// 	}
// 	if ((size - 1) == 0)
// 		chunk_list->end = b->nbr;
// }

// void    process_chunk(t_ps *ps, t_stack **tmp_b, int *mid_point, int *count)
// {
// 	t_stack	*tmp_a;
// 	int		count_rrb;
// 	int		count_rra;
// 	int		c;

// 	tmp_a = ps->a;
// 	count_rra = 0;
// 	count_rrb = 0;
// 	c = *count;
// 	if (ps->chunk_list->size > 2)
// 	{
// 		while (*count > 0 && ps->chunk_list->size > 2)
// 		{
// 			if (tmp_b[0]->nbr > *mid_point && (find_max(ps->b) == tmp_b[0]->nbr))
// 			{
// 				pa(&ps->a, &ps->b);
// 				*tmp_b = ps->b;
// 				(*count)--;
// 				if (count_rrb > 0)
// 				{
// 					while(count_rrb--)
// 						rrb(&ps->b);
// 					count_rrb = 0;
// 				}
// 			}
// 			else
// 			{
// 				rb(&ps->b);
// 				count_rrb++;
// 			}
// 			*tmp_b = ps->b;
// 			tmp_a = ps->a;
// 		}
// 		act_chunk(ps->b, ps->chunk_list, ps->chunk_list->size - c);
// 	}
// }

// void    sort_two(t_ps *ps, t_stack *tmp)
// {
//     if (!check_chunck_sorted(tmp, ps->chunk_list->size))
//         sb(&ps->b);
//     pa(&ps->a, &ps->b);
//     pa(&ps->a, &ps->b);
// 	ps->chunk_list = ps->chunk_list->next;
// 	ps->total_chunks--;
// }

// void	last_chunk(t_ps *ps, t_stack *tmp)
// {
// 	int	*array;
// 	int	mid_point;
// 	int	count;
// 	int	bottom;
// 	int	c;

// 	if (ps->chunk_list->size > 2)
// 	{
// 		while(tmp->next && !check_desc_sorted(ps->b) && ps->chunk_list->size > 2)
// 		{
// 			array = (int *)malloc(sizeof(int) * ps->chunk_list->size);
// 			mid_point = get_chunk_midpoint(&ps->b, array, ps->chunk_list->size);
// 			count = get_nbr_left(mid_point, array, ps->chunk_list->size);
// 			free(array);
// 			c = count;
// 			while (count > 0)
// 			{
// 				if (tmp->nbr > mid_point && find_max(ps->b) == tmp->nbr)
// 				{
// 					pa(&ps->a, &ps->b);
// 					count--;
// 				}
// 				else
// 				{
// 					bottom = stack_last(tmp)->nbr;
// 					if (bottom > mid_point && find_max(ps->b) == tmp->nbr)
// 					{
// 						rrb(&ps->b);
// 						pa(&ps->a, &ps->b);
// 						count--;
// 					}
// 					else
// 						rb(&ps->b);
// 				}
// 				tmp = ps->b;
// 			}
// 			act_chunk(ps->b, ps->chunk_list, ps->chunk_list->size - c);
// 		}
// 	}
// 	if (ps->chunk_list->size == 2)
// 		sort_two(ps, tmp); 
// }

// void    push_to_a(t_ps *ps)
// {
// 	t_stack *tmp_b;
// 	int     *array;
// 	int     mid_point;
// 	int     count;

// 	tmp_b = ps->b;
// 	while  (tmp_b->next && ps->total_chunks > 1 && !check_desc_sorted(ps->b))
// 	{
// 		array = (int *)malloc(sizeof(int) * ps->chunk_list->size);
// 		mid_point = get_chunk_midpoint(&ps->b, array, ps->chunk_list->size);
// 		count = get_nbr_left(mid_point, array, ps->chunk_list->size);
// 		free(array);
// 		process_chunk(ps, &tmp_b, &mid_point, &count);
// 		if (ps->chunk_list->size == 2)
// 			sort_two(ps, tmp_b);
// 		else if (ps->chunk_list->size == 1)
// 		{
// 			pa(&ps->a, &ps->b);
// 			ps->chunk_list->size--;
// 		}
// 		if (ps->chunk_list->size == 0)
// 		{
// 			ps->chunk_list = ps->chunk_list->next;
// 			ps->total_chunks--;
// 		}
// 		tmp_b = ps->b;
// 	}
// 	//chunk sorted or stack sorted?
// 	if (ps->total_chunks == 1)
// 	{
// 		last_chunk(ps, tmp_b);
// 		if (!(ps->total_chunks == 0) && check_desc_sorted(ps->b))
// 		{
// 			while(tmp_b)
// 			{
// 				pa(&ps->a, &ps->b);
// 				tmp_b = ps->b;
// 			}
// 		}
// 	}
// }