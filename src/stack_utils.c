#include "push_swap.h"

int stack_size(t_stack *stack)
{
    int i;

    i = 0;
    while (stack)
    {
        stack = stack->next;
        i++;
    }
    return (i);
}

void    print_stacks(t_stack **a, t_stack **b)
{
    printf("STACK B:\n");
    while (*b)
	{
		printf("b:%d\n", (*b)->nbr);
		(*b) = (*b)->next;
	}
    printf("--------\n");
    printf("STACK A\n");
	while (*a)
	{
		printf("a:%d\n", (*a)->nbr);
		(*a) = (*a)->next;
	}
}

t_stack *new_stack(int nbr)
{
    t_stack *new;

    new = (t_stack *)malloc(sizeof(t_stack));
    if (!new)
        error("malloc failed");
    new->nbr = nbr;
    new->next = NULL;
    return (new);
}

t_stack *stack_last(t_stack *stack)
{
    if(!stack)
        return (NULL);
    while (stack->next)
        stack = stack->next;
    return (stack);
}

void    add_back(t_stack **stack, t_stack *new)
{
    if (*stack && new)
        stack_last(*stack)->next = new;
    else
        *stack = new;
}