/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:31:41 by passunca          #+#    #+#             */
/*   Updated: 2024/04/12 17:46:46 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	ft_sort_three()
*	- Get the start index of the stack;
*	- Get the end index of the stack;
*	- If the stack is already sorted, return;
*	- if the min value in the stack is at the start AND the max in 2nd
*		- swap and rotate;
*	- if the max is at the start
*		- rotate;
*	- If the fist element is greater than the second element
*		- swap;
*	- if the min value is at the end
*		- reverse rotate;
*	*/
void	ft_sort_three(t_elem *stack)
{
	int	start;
	int	end;

	start = ft_get_stack_start(stack);
	end = ft_get_stack_end(stack);
	if ((ft_get_stack_min(stack).index == start)
		&& (ft_get_stack_max(stack, -1).index == end))
		return ;
	if ((ft_get_stack_min(stack).index == start)
		&& (ft_get_stack_max(stack, -1).index == (end - 1)))
	{
		ft_swap_elem(stack, "sa\n");
		ft_rotate(stack, "ra\n");
	}
	if (ft_get_stack_max(stack, -1).index == start)
		ft_rotate(stack, "ra\n");
	if (stack[start].num > stack[(start + 1)].num)
		ft_swap_elem(stack, "sa\n");
	if (ft_get_stack_min(stack).index == end)
		ft_rev_rotate(stack, "rra\n");
}
