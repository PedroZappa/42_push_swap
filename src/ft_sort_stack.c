/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 08:36:28 by passunca          #+#    #+#             */
/*   Updated: 2024/04/16 16:30:52 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_calc_move(t_elem *stack_a, t_elem *stack_b,
						 int idx, int stack_len);
static int	ft_best_op_idx(t_elem *stack_a, t_elem *stack_b, int stack_len);
static int	get_op_for_gplace(t_elem *stack_a, t_elem *stack_b, int idx);
static int	ft_rotate_top(t_elem *stack_a, int index, char *r, char *rr);

/* ft_sort_stack():
 * 	Sorts a stack of integers by repeatedly partitioning the stack around
 * 	a median value, pushing elements less than the median to a second stack, \
 * 	and then merging the two stacks back together in sorted order.
 *	
 *	- Initialize i to the start of the stack;
 *	- Initialize median to the median value of the stack;
 *	- Loop through the stack_a pushing elements to stack_b until there are only
 *		three elements left in stack_a;
 *		- If the current element in stack_b is greater than the median AND
 *			the number of elements in stack_a is greater than 3, 
 *			rotate stack_b;
 *		- Increment i;
 *	- Sort the three elements in stack_a;
 *	- Reset i to the start of the stack_a;
 *	- Loop through the stack_b:
 *		- Calculate the best move for the current element in stack_b;
 *		- Increment i;
 *	- Rotate stack_a until the smallest number greater than the value at
 *		the top of stack_b is at the top of stack_a;
 *	- Pushes the top of stack_b to stack_a;
 *	- Rotate stack_a until its smallest element is at the top;
 * */
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
		ft_calc_move(stack_b, stack_a, \
			ft_best_op_idx(stack_b, stack_a, stack_len), stack_len);
		++i;
	}
	ft_rotate_top(stack_a, ft_min_above_thresh(stack_a, stack_b[i].num).index, \
	"ra\n", "rra\n");
	ft_push_elem(stack_b, stack_a, "pa\n");
	ft_rotate_top(stack_a, ft_get_stack_min(stack_a).index, "ra\n", "rra\n");
}

/* ft_calc_move():
 *	- Get the start of the stack_a;
 *	- Get number of elements in stack_a & stack_b that are in the right order
 *		relative to eachother;
 *	- Moves the ordered elements from stack_b to stack_a;
 *	- If ordered elements were found, their indexes are adjusted accordingly;
 *	- Checks if the index is near the end if the stack or before the start 
 *		of the stack, adjusting indexes if necessary;
 *	- Rotates stack_a so that the element at idx is at the top;
 *	- Again, checks if the index is near the end of the stack or before the
 *		start of the stack, adjusting indexes if necessary;
 *	- Checks if the smallest element in stack_b is greater than the top of 
 *		stack_a OR if the largest element in stack_b is less than the top of
 *		stack_a;
 *		- If either conditions is true, rotates the stack_b so that it's 
 *			smallest element is at the top, 
 *	- Else, rotates stack_b so that it's smallest element greater than the top
 *		of stack_a is at the top;
 *	- Pushes the element in the top of stack_b to stack_a;
 * */
static void	ft_calc_move(t_elem *stack_a, t_elem *stack_b,
						 int idx, int stack_len)
{
	int start;
	int same;

	start = ft_get_stack_start(stack_a);
	same = ft_check_order(stack_a, stack_b, idx);
	ft_order(stack_a, stack_b, idx);
	if (same != 0)
		idx -= same;
	if (idx >= (stack_len - 2))
		idx = (start + (idx - (stack_len - 1)));
	else if (idx < start)
		idx = (ft_get_stack_end(stack_a) + idx);
	idx -= ft_rotate_top(stack_a, idx, "rb\n", "rrb\n");
	if (idx >= (stack_len - 2))
		idx = (start + (idx - (stack_len - 1)));
	if ((ft_get_stack_min(stack_b).num > stack_a[idx].num)
		|| (ft_get_stack_max(stack_b, -1).num < stack_a[idx].num))
		ft_rotate_top(stack_b, ft_get_stack_min(stack_b).index, "ra\n", "rra\n");
	else
		ft_rotate_top(stack_b, \
		ft_min_above_thresh(stack_b, stack_a[idx].num).index, "ra\n", "rra\n");
	ft_push_elem(stack_a, stack_b, "pa\n");
}

/* ft_best_op_idx():
 *	- Get the start of the stack_a;
 *	- Initialize i to the start of the stack;
 *	- Initialize min_ops to -1 to keep track of the smallest cost;
 *	- Loop from i till (stack_len - 1):
 *		- Calculate the cost of moving the element at i of stack_a to the top
	 *			and align it with the corresponding element at in stack_b;
 *			- If the cost is less than the current min_ops, 
 *				- update min_ops;
 *		- Increment i;
 *	- Return the index of the best move;
 * */
static int	ft_best_op_idx(t_elem *stack_a, t_elem *stack_b, int stack_len)
{
	int		i;
	int		cost;
	int		start;
	t_elem	min_ops;

	start = ft_get_stack_start(stack_a);
	i = start;
	min_ops.num = -1;
	while (i < (stack_len - 1))
	{
		cost = get_op_for_gplace(stack_a, stack_b, i);
		if ((cost < min_ops.num) || (min_ops.num == -1))
		{
			min_ops.num = cost;
			min_ops.index = i;
		}
		++i;
	}
	return (min_ops.index);
}

/* get_op_for_gplace():
 *	- Initialize n_ops to 0 to keep count of the number of operations;
 *	- Calculate the cost of moving the element at idx of stack_a to the top
 *		and add it to n_ops;
 *	- Check if the smallest element in stack_b is greater than the element at
 *		idx in stack_a OR if the largest element in stack_b is less than the
 *		element at idx in stack_a;
 *		- Calculate the number of operations needed to move the smallest element
 *			in stack_b to the top, and adds this number to n_ops.
 *	- Else 
 *		- Calculate the index of the smallest element in stack_b greater than
 *			the element at idx in stack_a;;
 *		- Calculate the number of operations needed to move the current element
 *			in stack_b to the top, and adds this number to n_ops;
 *	- Calculate the number of operations needed to align the two stacks;
 *	- If order is negative we take its absolute value;
 *	- Subtract order from n_ops to get the total number of operations;
 *	- Return (n_ops + 1);
 * */
static int	get_op_for_gplace(t_elem *stack_a, t_elem *stack_b, int idx)
{
	int		n_ops;
	int		order;
	t_elem	min_n_behind;

	n_ops = 0;
	n_ops += get_op_for_topplace(stack_a, idx, 0);
	if ((ft_get_stack_min(stack_b).num > stack_a[idx].num) \
	|| (ft_get_stack_max(stack_b, -1).num < stack_a[idx].num))
		n_ops += get_op_for_topplace(stack_b, ft_get_stack_min(stack_b).index, 0);
	else
	{
		min_n_behind = ft_min_above_thresh(stack_b, stack_a[idx].num);
		n_ops += get_op_for_topplace(stack_b, stack_b[min_n_behind.index].index, 0);
	}
	order = ft_check_order(stack_a, stack_b, idx);
	if (order < 0)
		order = -order;
	n_ops = (n_ops - order);
	return (n_ops + 1);
}

static int	ft_rotate_top(t_elem *stack_a, int index, char *r, char *rr)
{
	(void) stack_a;
	(void) index;
	(void) r;
	(void) rr;
	return (0);
}
