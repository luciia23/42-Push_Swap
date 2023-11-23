#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# include "../libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack{
    int     nbr;
    struct  s_stack *next;
}               t_stack;

typedef struct s_chunk
{
    int start;
    int end;
    int size;
    struct s_chunk *next;
}               t_chunk;

typedef struct s_ps{
    t_stack *a;
    t_stack *b;
    t_chunk *chunk_list;
    int     total_chunks;
}               t_ps;

// UTILS
int    ft_atoi_ps(const char *str);
int     error(char *msg);
void	free_stack(t_stack **stack);
void	free_str(char **str);
void    print_stacks(t_stack **a, t_stack **b);

// SORTING UTILS
int	check_sorted(t_stack *stack);
int	check_desc_sorted(t_stack *stack);
int	find_max(t_stack *src);
void	insertion_sort(int *array, int size);
int	get_index(int mid_point, int *array, int size);

// STACK UTILS
void    add_back(t_stack **stack, t_stack *new);
t_stack *new_stack(int nbr);
int stack_size(t_stack *stack);
t_stack *stack_last(t_stack *stack);
void	copy_stack(t_stack *a, int *array, int size);

// INPUT
t_stack *manage_input(int argc, char *argv[]);
int check_doubles(t_stack *a);

// SORTING
void    ft_sort(t_stack **a);
void	sort_three(t_stack **a);
// void	push_to_b(t_stack **a, t_stack **b, t_chunk **list, int *total_chunk);
void    push_to_b(t_ps *ps);
void    push_to_a(t_ps *ps);

// OPERATIONS
void    pb(t_stack **a, t_stack **b);
void    pa(t_stack **a, t_stack **b);
void    sa(t_stack **a);
void    sb(t_stack **b);
void    ss(t_stack **a, t_stack **b);
void    ra(t_stack **a);
void    rb(t_stack **b);
void    rr(t_stack **a, t_stack **b);
void    rra(t_stack **a);
void    rrb(t_stack **b);
void    rrr(t_stack **a, t_stack **b);



#endif