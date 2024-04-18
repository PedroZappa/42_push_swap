/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:46:10 by passunca          #+#    #+#             */
/*   Updated: 2024/04/16 16:33:50 by passunca         ###   ########.fr       */
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
	if ((ft_get_stack_min(stack_b).num > stack_a[idx].num) || \
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

/* get_op_for_topplace() (using rotations)
 *	## Calculates the number of operations needed to move an element at a given
 *	index to the top of a stack.
 *
 *	- Initialize n_ops counter to 0;
 *	- Get the start of the stack;
 *	- Get the end of the stack;
 *	- Get the median position of the stack;
 *	- If the index is greater than the median:
 *		(closer to the end of the stack):
 *		- Get the difference between the end of the stack and the index + 1;
 *		- If the parameter sign is set to one:
 *			- Make n_ops negative to signify the direction of rotation;
 *	- Else if the index is less than or equal to the median 
 *		(closer to the start of the stack):
 *		- Get the difference between the index and the start of the stack;
 *	- Return n_ops;	
 * */
int	get_op_for_topplace(t_elem *stack, int idx, int sign)
{
	int		n_ops;
	int		start;
	int		end;
	int		median;

	n_ops = 0;
	start = ft_get_stack_start(stack);
	end = ft_get_stack_end(stack);
	median = (start + ((end - start) / 2));
	if (idx > median)
	{
		n_ops = (end - idx + 1);
		if (sign == 1)
			n_ops = -n_ops;
	}
	else if (idx <= median)
		n_ops = (idx - start);
	return (n_ops);
}
