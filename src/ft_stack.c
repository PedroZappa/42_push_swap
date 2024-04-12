/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:33:19 by passunca          #+#    #+#             */
/*   Updated: 2024/04/12 15:05:13 by passunca         ###   ########.fr       */
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

	i = 0;
	while (stack[(i + 1)].index != -1)
	{
		if (stack[i].num > stack[(i + 1)].num)
			return (-1);
		++i;
	}
	return (1);
}

/*	ft_get_stack_start()
 *	- i keeps track of the index of the first filled stack element;
 *	- Loop from bottom to the top element of the stack;
 *	- After finding the first filled element decrement start by 1;
 *		(to account for the sentinel value);
 *	- Return start, the index of the first filled element;
 * */
int	ft_get_stack_start(t_elem *stack)
{
	int	start;

	start = 0;
	while (stack[start].filled != 1)
		++start;
	if (stack[start].index == -1)
		--start;
	return (start);
}

/*	ft_get_stack_end()
*	- Loops through stack until the sentinel value (-1) is found;
*	- Decrement end by 1 to select the value before the sentinel value;	
*	- Returns the index of the last filled element;
*	*/
int	ft_get_stack_end(t_elem *stack)
{
	int	end;

	end = 0;
	while (stack[end].index != -1)
		++end;
	--end;
	return (end);
}

/*	ft_get_stack_min()
 *	- Get the start of the stack;
 *	- Get the end of the stack;
 *	- Initialize min_idx to the index of the first filled element;
 *	- Loop through the stack from start to end;
 *		- If the current element is less than the element at current min_idx
 *			- Set min_idx to the index of the current element;
 *		- Increment start;
 *	- Return the element at min_idx;
 * */
t_elem	ft_get_stack_min(t_elem *stack)
{
	int	start;
	int	end;
	int	min_idx;

	start = ft_get_stack_start(stack);
	end = ft_get_stack_end(stack);
	min_idx = stack[start].index;
	while (start <= end)
	{
		if (stack[start].num < stack[min_idx].num)
			min_idx = stack[start].index;
		++start;
	}
	return (stack[min_idx]);
}

t_elem	ft_get_stack_max(t_elem *stack)
{
	(void)stack;
	return (stack[0]);
}
