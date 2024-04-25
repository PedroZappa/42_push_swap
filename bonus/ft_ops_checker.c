/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:00:55 by passunca          #+#    #+#             */
/*   Updated: 2024/04/25 09:05:36 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*	ft_swap_elem()
 *	- get the start of the stack (skipping sentinel value);
 *	- store the first element in a temp variable;
 *	- Perform the swap:
 *		- set the first element to the next element;
 *		- set the next element to the temp variable;
 *	- Print the operation message to stdout;
 * */
void	ft_swap_elem(t_elem *stack)
{
	int	start;
	int	temp;

	start = ft_stack_start(stack);
	temp = stack[start].num;
	stack[start].num = stack[(start + 1)].num;
	stack[(start + 1)].num = temp;
}

/* ft_push_elem()
* 	- Initialize a_idx to 0;
* 	- Loop through stack_a until the first element is found (at top);
*		- Save the index of the top element in a_idx;
* 	- Initialize b_idx to 0;
* 	- Loop through stack_b until the last element is found (at top);
* 		- Save the index of the top element in b_idx;
* 	- Decrement b_idx by 1 to skip the sentinel value;
* 	- Set the value at b_idx to the value at a_idx;
* 	- Set the stack_b element as set;
* 	- Set the value at a_idx to 0;
* 	- Set the stack_a element as empty;
*	- Print the operation message to stdout;
*	*/
void	ft_push_elem(t_elem *stack_a, t_elem *stack_b)
{
	int	a_idx;
	int	b_idx;

	a_idx = 0;
	while ((stack_a[a_idx].index != -1) && (stack_a[a_idx].set != 1))
		++a_idx;
	b_idx = 0;
	while ((stack_b[b_idx].index != -1) && (stack_b[b_idx].set != 1))
		++b_idx;
	--b_idx;
	stack_b[b_idx].num = stack_a[a_idx].num;
	stack_b[b_idx].set = 1;
	stack_a[a_idx].num = 0;
	stack_a[a_idx].set = 0;
}

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
void	ft_rotate(t_elem *stack)
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
void	ft_rev_rotate(t_elem *stack)
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
}
