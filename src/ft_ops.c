/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 09:54:54 by passunca          #+#    #+#             */
/*   Updated: 2024/04/18 09:07:46 by passunca         ###   ########.fr       */
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

	start = ft_stack_start(stack);
	temp = stack[start].num;
	stack[start].num = stack[(start + 1)].num;
	stack[(start + 1)].num = temp;
	ft_putstr_fd(msg, 1);
}

/* ft_push_elem()
* 	- Initialize a_idx to 0;
* 	- Loop through stack_a until the first element is found (at top);
*		- Save the index of the top element in a_idx;
* 	- Initialize b_idx to 0;
* 	- Loop through stack_b until the last element is found (at top);
* 		- Save the index of the top element in b_idx;
* 	- Decrement b_idx by 1 to skip the sentinel value;
* 	- Set the value at b_idx to the value at a_idx;
* 	- Set the stack_b element as filled;
* 	- Set the value at a_idx to 0;
* 	- Set the stack_a element as empty;
*	- Print the operation message to stdout;
*	*/
void	ft_push_elem(t_elem *stack_a, t_elem *stack_b, char *msg)
{
	int a_idx;
	int b_idx;

	a_idx = 0;
	while (stack_a[a_idx].filled != 1)
		++a_idx;
	b_idx = 0;
	while ((stack_b[b_idx].index != -1) && (stack_b[b_idx].filled != 1))
		++b_idx;
	--b_idx;
	stack_b[b_idx].num = stack_a[a_idx].num;
	stack_b[b_idx].filled = 1;
	stack_a[a_idx].num = 0;
	stack_a[a_idx].filled = 0;
	ft_putstr_fd(msg, 1);
}
