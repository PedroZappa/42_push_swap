/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:47:20 by passunca          #+#    #+#             */
/*   Updated: 2024/04/12 15:02:13 by passunca         ###   ########.fr       */
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