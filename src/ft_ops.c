/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 09:54:54 by passunca          #+#    #+#             */
/*   Updated: 2024/04/12 17:47:33 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	ft_swap_elem()
 *	- get the start of the stack (skipping sentinel value);
 *	- store the first element in a temp variable;
 *	- Perform the swap:
 *		- set the first element to the next element;
 *		- set the next element to the temp variable;
 *	- Print the operation message to stdout;
 * */
void	ft_swap_elem(t_elem *stack, char *msg)
{
	int	start;
	int	temp;

	start = ft_get_stack_start(stack);
	temp = stack[start].num;
	stack[start].num = stack[(start + 1)].num;
	stack[(start + 1)].num = temp;
	ft_putstr_fd(msg, 1);
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
void	ft_rotate(t_elem *stack, char *msg)
{
	int	start;
	int	end;
	int	temp;
	int	temp2;
	int	i;

	start = 0;
	while ((stack[start].index != -1) && (stack[start].filled != 1))
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
	while ((stack[start].index != -1) && (stack[start].filled != 1))
		++start;
	end = 0;
	while (stack[end].index != -1)
		++end;
	--end;
	i = start;
	temp = stack[i].num;
	while (i < start)
	{
		temp2 = stack[(i + 1)].num;
		stack[(i + 1)].num = temp;
		temp = temp2;
		++i;
	}
	stack[start].num = temp;
	ft_putstr_fd(msg, 1);
}
