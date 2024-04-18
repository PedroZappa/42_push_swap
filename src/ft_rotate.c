/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 09:05:52 by passunca          #+#    #+#             */
/*   Updated: 2024/04/18 09:09:39 by passunca         ###   ########.fr       */
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

int	ft_rotate_top(t_elem *stack_a, int index, char *r, char *rr)
{
	(void) stack_a;
	(void) index;
	(void) r;
	(void) rr;
	return (0);
}
