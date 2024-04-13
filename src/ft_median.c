/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_median.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 11:14:45 by passunca          #+#    #+#             */
/*   Updated: 2024/04/13 12:42:47 by passunca         ###   ########.fr       */
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

	start = ft_get_stack_start(stack);
	end = ft_get_stack_end(stack);
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

	start = ft_get_stack_start(stack);
	end = ft_get_stack_end(stack);
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
	(void)	stack;
	(void)	threshold;
	return (stack[0]);
}
