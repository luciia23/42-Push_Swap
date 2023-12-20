#include "push_swap.h"

void check_leaks(void) { system("leaks push_swap"); }

int main(int argc, char *argv[])
{
    // atexit(check_leaks);
    t_stack *a;

    a = manage_input(argc, argv);
    if (!a || check_doubles(a))
    {
        // free_stack(&a);
        error("there are doubles in the input or wrong input");
    }
    if (!check_sorted(a))
        ft_sort(&a);
    // free_stacks(&a, &b);
    // free_stack(&a);
    return (0);
}