#include "push_swap.h"

int main(int argc, char *argv[]){
    t_stack *a;

    a = manage_input(argc, argv);
    if (check_doubles(a))
    {
        free_stack(&a);
        error("there are doubles in the input");
    }
    if (!check_sorted(a))
        ft_sort(&a);
    // free_stacks(&a, &b);
    free_stack(&a);
    return (0);
}