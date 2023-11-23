#include "push_swap.h"

int check_doubles(t_stack *a)
{
    t_stack *tmp;

    while (a)
    {
        tmp = a->next;
        while (tmp)
        {
            if (a->nbr == tmp->nbr)
                return (1);
            tmp = tmp->next;
        }
        a = a->next;
    }
    return (0);
}

t_stack *manage_string(char **argv)
{
    t_stack *a;
    char    **split;
    int     i;
    int     nbr;

    i = 0;
    a = NULL;
    split = ft_split(argv[1], 32);
    while (split[i])
    {
        nbr = ft_atoi_ps(split[i]);
        add_back(&a, new_stack(nbr));
        i++;
    }
    free_str(split);
    return (a);
}

t_stack *manage_input(int argc, char *argv[])
{
    t_stack *a;
    int     i;
    int     nbr;

    i = 1;
    a = NULL;
    if (argc < 2)
        error("no input provided"); // or exit
    if (argc == 2)
        a = manage_string(argv);
    else
    {
        while (i < argc)
        {
            nbr = ft_atoi_ps(argv[i]);
            add_back(&a, new_stack(nbr));
            i++;
        }
    }
    return (a);
}