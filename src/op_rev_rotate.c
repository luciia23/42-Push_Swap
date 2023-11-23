# include "push_swap.h"

int rev_stack(t_stack **src)
{
    t_stack *tmp;
    int i;

    if (!*src || !(*src)->next)
        return (0);
    tmp = *src;
    i = 0;
    while ((*src)->next)
    {
        *src = (*src)->next;
        i++;
    }
    (*src)->next = tmp;
    while(i > 1)
    {
        tmp = tmp->next;
        i--;
    }
    tmp->next = NULL;
    return (1);
}


void    rra(t_stack **a)
{
    if (rev_stack(&(*a)))
        write(1, "rra\n", 4);
}

void    rrb(t_stack **b)
{
    if (rev_stack(&(*b)))
        write(1, "rrb\n", 4);
}

void    rrr(t_stack **a, t_stack **b)
{
    if (rev_stack(&(*a)) && rev_stack(&(*b)))
        write(1, "rrr\n", 4);
}