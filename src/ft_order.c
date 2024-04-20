/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:46:10 by passunca          #+#    #+#             */
/*   Updated: 2024/04/18 09:24:40 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_order(t_elem *stack_a, t_elem *stack_b, int idx)
{
	int n_op_a;
	int n_op_b;
	int n_ops;
	int min;

	n_op_a = ft_getontop_ops(stack_a, idx, 1);
	if ((ft_get_stack_min(stack_b).num > stack_a[idx].num) || \
		(ft_get_stack_max(stack_b, -1).num < stack_a[idx].num))
		n_op_b = ft_getontop_ops(stack_b, ft_get_stack_min(stack_b).index, 1);
	else
	{
		min = ft_min_above_thresh(stack_b, stack_a[idx].num).index;
		n_op_b = ft_getontop_ops(stack_b, min, 1);
	}
	n_ops = 0;
	if ((n_op_a > 0) && (n_op_b > 0))
		n_ops = ft_min(n_op_a, n_op_b);
	if ((n_op_a < 0) && (n_op_b < 0))
		n_ops = ft_max(n_op_a, n_op_b);
	return (n_ops);
}
/* ft_order()
 * ## Aligns two stacks maintaining the relative order of their elements.
 *
 *	- Calculate the number of operations needed to align the two stacks;
 *	- If the number of operations is positive (means that the element at idx of
 *		stack_a and the corresponding element in stack_b need to be moved upwards):
 *		- Rotate both stacks;
 *		- Decrement the number of operations;
 *	- Else if the number of operations is negative (means that the element at idx
 *		of stack_a and the corresponding element in stack_b need to be moved downwards):
 *		- Reverse rotate both stacks;
 *		- Increment the number of operations;
 * */
void	ft_order(t_elem *stack_a, t_elem *stack_b, int idx)
{
	int	n_ops;

	n_ops = ft_check_order(stack_a, stack_b, idx);
	if (n_ops > 0)
	{
		while (n_ops > 0)
		{
			ft_rotate_both(stack_a, stack_b, 0);
			--n_ops;
		}
	}
	else if (n_ops < 0)
	{
		n_ops = -n_ops;
		while (n_ops > 0)
		{
			ft_rotate_both(stack_a, stack_b, 1);
			--n_ops;
		}
	}
	return ;
}

/* ft_getontop_ops() (using rotations)
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
int	ft_getontop_ops(t_elem *stack, int idx, int sign)
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
