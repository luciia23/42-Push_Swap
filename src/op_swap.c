#include "push_swap.h"

int swap_stack(t_stack **src)
{
    t_stack *tmp;

	if (!*src || !((*src)->next))
		return (0);
    tmp = *src;
    *src = (*src)->next;
    tmp->next = (*src)->next;
    (*src)->next = tmp;
    return (1);
}

void    sa(t_stack **a)
{
    if (swap_stack(&(*a)))
        write(1, "sa\n", 3);
}

void    sb(t_stack **b)
{
    if (swap_stack(&(*b)))
        write(1, "sb\n", 3);
}

void    ss(t_stack **a, t_stack **b)
{
    if (swap_stack(&(*a)) && swap_stack(&(*b)))
        write(1, "ss\n", 3);
}
