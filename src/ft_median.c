/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_median.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 11:14:45 by passunca          #+#    #+#             */
/*   Updated: 2024/04/13 16:46:56 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_median(t_elem *stack, int num);

/* ft_get_median() 
 *	- Get the start of the stack;
 *	- Get the end of the stack;
 *	- Loop through the stack from start to end;
 *		- Check if the current element is the median;
 *			- If yes, return the current element;
 *		- Increment start;
 *	- Return -1 if no median is found;
 * */
int	ft_get_median(t_elem *stack)
{
	int	start;
	int	end;

	start = ft_stack_start(stack);
	end = ft_stack_end(stack);
	while (start <= end)
	{
		if (ft_is_median(stack, stack[start].num))
			return (stack[start].num);
		++start;
	}
	return (-1);
}

/* ft_is_median()
 *	- Get the start of the stack;
 *	- Get the end of the stack;
 *	- Initialize max and min to 0;
 *	- Loop through the stack from start to end;
 *		- Check if the current element is greater than num;
 *			- If yes, increment max;
 *		- Check if the current element is lesser than num;
 *			- If yes, increment min;
 *		- Increment start;
 *	- Calculate the difference between max and min;
 *	- If diff is within the range of -1 and 1, return 1;
 *		(meaning the current element is the median);
 *	*/
static int	ft_is_median(t_elem *stack, int num)
{
	int	start;
	int	end;
	int	max;
	int	min;
	int	diff;

	start = ft_stack_start(stack);
	end = ft_stack_end(stack);
	min = 0;
	max = 0;
	while (start <= end)
	{
		if (stack[start].num > num)
			++max;
		else if (stack[start].num < num)
			++min;
		++start;
	}
	diff = (max - min);
	if ((diff >= -1) && (diff <= 1))
		return (1);
	return (0);
}

t_elem	ft_min_above_thresh(t_elem *stack, int threshold)
{
	int	start;
	int	end;
	int	min;

	start = ft_stack_start(stack);
	end = ft_stack_end(stack);
	min = -1;
	while (start <= end)
	{
		if ((stack[start].num > threshold)
			&& ((min == -1) || (stack[start].num < stack[min].num)))
			min = stack[start].index;
		++start;
	}
	if (min == -1)
		return (ft_stack_min(stack));
	return (stack[min]);
}
