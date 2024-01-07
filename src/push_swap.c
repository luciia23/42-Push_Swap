/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcollado <lcollado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:40:26 by lcollado          #+#    #+#             */
/*   Updated: 2024/01/07 16:36:36 by lcollado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;

	a = manage_input(argc, argv);
	if (!a || check_doubles(a))
	{
		free_stack(&a);
		error();
	}
	if (!check_sorted(a))
		ft_sort(&a);
	if (a)
		free_stack(&a);
	return (0);
}
