# include "push_swap.h"

void    push_to_a(t_ps *ps)
{
    printf("STACK A:\n");
    while(ps->a)
    {
        printf("%d\n", ps->a->nbr);
        ps->a = ps->a->next;
    }
    printf("STACK b:\n");
    while(ps->b)
    {
        printf("%d\n", ps->b->nbr);
        ps->b = ps->b->next;
    }
}