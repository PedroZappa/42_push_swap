/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 09:05:52 by passunca          #+#    #+#             */
/*   Updated: 2024/04/18 12:08:28 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	ft_rotate()
 *	- Get the start of the stack;
 *	- Get the end of the stack;
 *	- Step 1 idx back to get last element (instead of sentinel value);
 *	- Initialize i to the end of the stack;
 *	- Store the current element in a temp variable;
 *	- Loop through the stack from end to the start (top to bottom);
 *		- Store the previous (below) element in a temp2 variable;
 *		- Set the current element to the previous element;
 *		- Set temp2 to temp to be used on next iteration;
 *		- Decrement i to travel down the stack;
 *	- Set the element at the bottom to the top of the stack;
 *	- Print the operation message to stdout;
 * */
void	ft_rotate(t_elem *stack, char *msg)
{
	int	start;
	int	end;
	int	temp;
	int	temp2;
	int	i;

	start = 0;
	while ((stack[start].index != -1) && (stack[start].set != 1))
		++start;
	end = 0;
	while (stack[end].index != -1)
		++end;
	--end;
	i = end;
	temp = stack[i].num;
	while (i > start)
	{
		temp2 = stack[(i - 1)].num;
		stack[(i - 1)].num = temp;
		temp = temp2;
		--i;
	}
	stack[end].num = temp;
	ft_putstr_fd(msg, 1);
}

/*	ft_rev_rotate()
 *	- Get the start of the stack;
 *	- Get the end of the stack;
 *	- Step 1 idx back to get last element (instead of sentinel value);
 *	- Initialize i to the start of the stack;
 *	- Store the current element in a temp variable;
 *	- Loop through the stack from start to the end (bottom to top);
 *		- Store the next (above) element in a temp2 variable;
 *		- Set the next element to the temp variable;
 *		- Set temp2 to temp to be used on next iteration;
 *		- Increment i to travel up the stack;
 *	- Set the element at the bottom to the top of the stack;
 *	- Print the operation message to stdout;
 * */
void	ft_rev_rotate(t_elem *stack, char *msg)
{
	int	start;
	int	end;
	int	temp;
	int	temp2;
	int	i;

	start = 0;
	while ((stack[start].index != -1) && (stack[start].set != 1))
		++start;
	end = 0;
	while (stack[end].index != -1)
		++end;
	--end;
	i = start;
	temp = stack[i].num;
	while (i < end)
	{
		temp2 = stack[(i + 1)].num;
		stack[(i + 1)].num = temp;
		temp = temp2;
		++i;
	}
	stack[start].num = temp;
	ft_putstr_fd(msg, 1);
}

/*	ft_rotate_top()
 *	## Rotates a stack to a specific index position.
 *	
 *	- Calculate the cost of moving the element at given idx to the top of the
 *		stack;
 *	- Backup n_ops to teh variable sign;
 *	- If n_ops is negative (meaning the fastest way to get the element to the 
 *	top is by reverse rotating the stack):
 *		- Set it to its absolute value;
 *	- Backup n_ops to the variable op;
 *	- If n_ops is not 0:
 *		- While n_ops is greater than 0:
 *			- If sign is positive:
 *				- Rotate the stack;
 *			- Else:
 *				- Reverse rotate the stack;
 *			- Decrement n_ops;
 *	- If sign is positive:
 *		- Set sign to 1;
 *	- Else:
 *		- Set sign to -1;
 *	- Return the operation cost (sign * op);
 * */
int	ft_rotate_top(t_elem *stack, int idx, char *r, char *rr)
{
	int	op;
	int	n_ops;
	int	sign;

	n_ops = ft_getontop_ops(stack, idx, 1);
	sign = n_ops;
	if (n_ops < 0)
		n_ops = -n_ops;
	op = n_ops;
	if (n_ops != 0)
	{
		while (n_ops > 0)
		{
			if (sign > 0)
				ft_rotate(stack, r);
			else
				ft_rev_rotate(stack, rr);
			--n_ops;
		}
	}
	if (sign > 0)
		sign = 1;
	else
		sign = -1;
	return (sign * op);
}

/*	ft_rotate_both()
*	## Rotates both stacks in a given direction.
*	*/
void	ft_rotate_both(t_elem *stack_a, t_elem *stack_b, int direction)
{
	if (direction == 0)
	{
		ft_rotate(stack_a, "");
		ft_rotate(stack_b, "");
		ft_putstr_fd("rr\n", 1);
	}
	else
	{
		ft_rev_rotate(stack_a, "");
		ft_rev_rotate(stack_b, "");
		ft_putstr_fd("rrr\n", 1);
	}
}
