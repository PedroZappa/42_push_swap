/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:46:10 by passunca          #+#    #+#             */
/*   Updated: 2024/04/16 16:19:28 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_order(t_elem *stack_a, t_elem *stack_b, int idx)
{
	int n_op_a;
	int n_op_b;
	int n_ops;
	int min;

	n_op_a = get_op_for_topplace(stack_a, idx, 1);
	if ((ft_get_stack_min(stack_b).num > stack_a[idx].num)) || \
		(ft_get_stack_max(stack_b, -1).num < stack_a[idx].num))
		n_op_b = get_op_for_topplace(stack_b, ft_get_stack_min(stack_b).index, 1);
	else
	{
		min = ft_min_above_thresh(stack_b, stack_a[idx].num).index;
		n_op_b = get_op_for_topplace(stack_b, min, 1);
	}
	n_ops = 0;
	if ((n_op_a > 0) && (n_op_b > 0))
		n_ops = ft_min(n_op_a, n_op_b);
	if ((n_op_a < 0) && (n_op_b < 0))
		n_ops = ft_max(n_op_a, n_op_b);
	return (n_ops);
}

void	ft_order(t_elem *stack_a, t_elem *stack_b, int idx)
{
	(void) stack_a;
	(void) stack_b;
	(void) idx;
	return ;
}
