/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_median.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 11:14:45 by passunca          #+#    #+#             */
/*   Updated: 2024/04/13 11:22:27 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_median(t_elem *stack, int num);

/* ft_get_median() 
 *
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

/*	ft_is_median()
 *
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
