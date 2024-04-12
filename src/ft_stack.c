/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:33:19 by passunca          #+#    #+#             */
/*   Updated: 2024/04/12 10:53:53 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	ft_create_stack()
 *		- Allocated memory for stack (+1 for sentinel value);
 *		- If memory allocation fails return NULL;
 *		- Loops over args excluding the last one;
 *			- If select == 1 (building stack_a)
 *				- Convert string to int;
 *				- Set stack element as filled;
 *			- If select == 0 (building stack_b)
 *				- Set stack element as empty;
 *			- Assign current stack element index;
 *			- Increment stack index;
 *		- After the loop set the index of sentinel value to -1;
 *		- Return stack;
 * */
t_elem	*ft_create_stack(int argc, char **argv, int select)
{
	t_elem	*stack;
	int		i;

	stack = malloc(sizeof(t_elem) * (argc + 1));
	if (stack == NULL)
		return (NULL);
	i = 0;
	while (i < (argc - 1))
	{
		if (select == 1)
		{
			stack[i].num = ft_atoi(argv[i]);
			stack[i].filled = 1;
		}
		else
		{
			stack[i].num = 0;
			stack[i].filled = 0;
		}
		stack[i].index = i;
		++i;
	}
	stack[i].index = -1;
	return (stack);
}

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
