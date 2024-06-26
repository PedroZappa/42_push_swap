/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:33:19 by passunca          #+#    #+#             */
/*   Updated: 2024/04/12 16:45:54 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	ft_is_sorted()
 *		- Initialize counter i to 0;
 *		- Loop through stack until the sentinel value (-1) is found;
 *			- If curr element is greater than next element
 *				- Return -1, indicating that the stack is NOT sorted in 
 *					ascending order;
 *			- Increment i;
 *		- Return 1, indicating that the stack is sorted in ascending order;
 * */
int	ft_is_sorted(t_elem *stack)
{
	int	i;

	if (!stack)
		return (-1);
	i = 0;
	while (stack[(i + 1)].index != -1)
	{
		if (stack[i].num > stack[(i + 1)].num)
			return (-1);
		++i;
	}
	return (1);
}

/*	ft_stack_start()
 *	- start keeps track of the index of the first set stack element;
 *	- Loop from bottom to the top element of the stack;
 *	- After finding the first set element decrement start by 1;
 *		(to account for the sentinel value);
 *	- Return start, the index of the first set element;
 * */
int	ft_stack_start(t_elem *stack)
{
	int	start;

	if (!stack)
		return (-1);
	start = 0;
	while (stack[start].set != 1)
		++start;
	if (stack[start].index == -1)
		--start;
	return (start);
}

/*	ft_stack_end()
*	- Loops through stack until the sentinel value (-1) is found;
*	- Decrement end by 1 to select the value before the sentinel value;	
*	- Returns the index of the last set element;
*	*/
int	ft_stack_end(t_elem *stack)
{
	int	end;

	if (!stack)
		return (-1);
	end = 0;
	while (stack[end].index != -1)
		++end;
	--end;
	return (end);
}

/*	ft_get_stack_min()
 *	- Get the start of the stack;
 *	- Get the end of the stack;
 *	- Initialize min_idx to the index of the first set element;
 *	- Loop through the stack from start to end;
 *		- If the current element is less than the element at current min_idx
 *			- Set min_idx to the index of the current element;
 *		- Increment start;
 *	- Return the element at min_idx;
 * */
t_elem	ft_stack_min(t_elem *stack)
{
	int	start;
	int	end;
	int	min_idx;

	start = ft_stack_start(stack);
	end = ft_stack_end(stack);
	min_idx = stack[start].index;
	while (start <= end)
	{
		if (stack[start].num < stack[min_idx].num)
			min_idx = stack[start].index;
		++start;
	}
	return (stack[min_idx]);
}

/*	ft_get_stack_max()
 *	- Get the start of the stack;
 *	- Get the end of the stack;
 *	- Initialize to -1;
 *	- Loop through the stack from start to end;
 *		- check if max_idx is -1
 *		- OR if the curr element is greater than the element at max_idx
 *		- OR if the threshhold is -1 or the curr element is less than threshold
 *		- AND if the current element is not set
 *			- Set max_idx to the index of the current element;
 *		- Increment start;
 *	- Return the element at max_idx;
 * */
t_elem	ft_stack_max(t_elem *stack, int threshold)
{
	int	start;
	int	end;
	int	max_idx;

	start = ft_stack_start(stack);
	end = ft_stack_end(stack);
	max_idx = -1;
	while (start <= end)
	{
		if ((max_idx == -1) || (((stack[start].num > stack[max_idx].num)
					|| (((threshold == -1) || (stack[start].num < threshold))
						&& (stack[max_idx].set == -1)))))
			max_idx = stack[start].index;
		++start;
	}
	return (stack[max_idx]);
}
