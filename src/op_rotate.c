# include "push_swap.h"

int rotate_stack(t_stack **src)
{
    t_stack *tmp;

    if (!*src || !(*src)->next)
        return (0);
    tmp = *src;
    *src = stack_last(*src);
    (*src)->next = tmp;
    *src = tmp->next;
    tmp->next = NULL;
    return (1);
}

void    ra(t_stack **a)
{
    if (rotate_stack(&(*a)))
        write(1, "ra\n", 3);
}

void    rb(t_stack **b)
{
    if (rotate_stack(&(*b)))
        write(1, "rb\n", 3);
}

void    rr(t_stack **a, t_stack **b)
{
    if (rotate_stack(&(*a)) && rotate_stack(&(*b)))
        write(1, "rr\n", 3);
}