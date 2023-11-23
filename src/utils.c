#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	free(*stack);
}

void	free_stacks(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int error(char *msg)
{
 	ft_putstr_fd("\033[0;31m" " Error : ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit(0);   
}

int ft_atoi_ps(const char *str)
{
	unsigned int	i;
	long int		sign;
	long int		result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ((str[i] != 0))
	{
        if (!ft_isdigit(str[i]))
            error("there is a char in the input");
		result *= 10;
		result += str[i] - '0';
		i++;
	}

	if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
		error("the input has to be an integer");
	return (result * sign); 
}