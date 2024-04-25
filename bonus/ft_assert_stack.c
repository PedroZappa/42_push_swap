/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assert_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 08:49:03 by passunca          #+#    #+#             */
/*   Updated: 2024/04/25 08:50:46 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

/*	ft_stack_start()
 *	- i keeps track of the index of the first set stack element;
 *	- Loop from bottom to the top element of the stack;
 *	- After finding the first set element decrement start by 1;
 *		(to account for the sentinel value);
 *	- Return start, the index of the first set element;
 * */
int	ft_stack_start(t_elem *stack)
{
	int	start;

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

	end = 0;
	while (stack[end].index != -1)
		++end;
	--end;
	return (end);
}
