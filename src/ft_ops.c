/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 09:54:54 by passunca          #+#    #+#             */
/*   Updated: 2024/04/12 16:43:35 by passunca         ###   ########.fr       */
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

void	ft_rotate(t_elem *stack, char *msg)
{
	(void) stack;
	(void) msg;
}

void	ft_rev_rotate(t_elem *stack, char *msg)
{
	(void) stack;
	(void) msg;
}
