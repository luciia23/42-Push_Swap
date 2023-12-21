/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollado <lcollado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:40:26 by lcollado          #+#    #+#             */
/*   Updated: 2023/12/20 20:35:57 by lcollado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_leaks(void) { system("leaks push_swap"); }

int	main(int argc, char *argv[])
{
	t_stack	*a;
	// atexit(check_leaks);

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
