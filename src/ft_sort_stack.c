/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 08:36:28 by passunca          #+#    #+#             */
/*   Updated: 2024/04/13 12:21:15 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_stack(t_elem *stack_a, t_elem *stack_b, int stack_len)
{
	int	i;
	int	median;

	i = ft_get_stack_start(stack_a);
	median = ft_get_median(stack_a);
	while (i < (stack_len - 4))
	{
		ft_push_elem(stack_a, stack_b, "pb\n");
		if ((stack_b[ft_get_stack_start(stack_b)].num > median)
			&& ((ft_get_stack_end(stack_a) - ft_get_stack_start(stack_a)) + 1) > 3)
			ft_rotate(stack_b, "rb\n");
		++i;
	}
	ft_sort_three(stack_a);
	i = ft_get_stack_start(stack_b);
	while (i < ft_get_stack_end(stack_b))
	{
		resolve_nun(stack_b, stack_a, \
			get_best_op_index(stack_b, stack_a, stack_len), stack_len);
		++i;
	}
	r_top(stack_a, get_min_above_thresh(stack_a, stack_b[i].num).index, \
	"ra\n", "rra\n");
	ft_push_elem(stack_b, stack_a, "pa\n");
	r_top(stack_a, ft_get_stack_min(stack_a).index, "ra\n", "rra\n");
}
