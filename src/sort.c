# include "push_swap.h"

void    sort_rest(t_ps *ps)
{
    t_chunk *chunk_list;
    int     total_chunk;

    chunk_list = NULL;
    total_chunk = 0;
    ps->chunk_list = chunk_list;
    ps->total_chunks = total_chunk;
    push_to_b(ps);
    push_to_a(ps);
}

void    sort_three(t_stack **a)
{
    int    n1;
    int    n2;
    int    n3;

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

void    ft_sort(t_stack **a)
{
    t_ps    ps;
    t_stack *b;

    b = NULL;
    if (stack_size(*a) == 2)
        sa(a);
    if (stack_size(*a) == 3)
        sort_three(a);
    else
    {
        ps.b = b;
        ps.a = *a;
        sort_rest(&ps);
    }
}