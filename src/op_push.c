# include "push_swap.h"

int    push_stack(t_stack **src, t_stack **dst)
{
    t_stack *tmp;

    if (!*src)
        return (0);
    tmp = *dst;
    *dst = *src;
    *src = (*src)->next;
    (*dst)->next = tmp;
    return (1);
}

void    pb(t_stack **a, t_stack **b)
{
    if (push_stack(&(*a), &(*b)))
        write(1, "pb\n", 3);
}

void    pa(t_stack **a, t_stack **b)
{
    if (push_stack(&(*b), &(*a)))
        write(1, "pa\n", 3);
}
