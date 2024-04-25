/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops_mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:06:59 by passunca          #+#    #+#             */
/*   Updated: 2024/04/25 09:18:00 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_swap_both(t_elem *stack_a, t_elem *stack_b)
{
	ft_swap_elem(stack_a);
	ft_swap_elem(stack_b);
}

/*	ft_rotate_both()
*	## Rotates both stacks in a given direction.
*	*/
void	ft_rotate_both(t_elem *stack_a, t_elem *stack_b, int direction)
{
	if (direction == 0)
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
	}
	else
	{
		ft_rev_rotate(stack_a);
		ft_rev_rotate(stack_b);
	}
}
