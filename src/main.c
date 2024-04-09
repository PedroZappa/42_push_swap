/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:21:18 by passunca          #+#    #+#             */
/*   Updated: 2024/03/05 21:14:04 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**ft_get_elems(int *argc, char **argv, int *must_free);
static int	ft_argv_count(char **argv);
static void	ft_free_list(t_elem *stack_a, t_elem *stack_b,
				char **input_list, int must_free);

/*	PUSH_SWAP
 *	- Set flag to signal if alloced memory needs freeing;
 *	- Increment argv to skip program name;
 *	- Assign argv to input_list;
 *	- Check for errors;
 *		- If there is an error free allocated memory;,
 *	- Create stack_a and stack_b;
 *	- if stack_a is not sorted
 *		- sort it
 *	- free allocated memory
 * */
int	main(int argc, char **argv)
{
	t_elem	*stack_a;
	t_elem	*stack_b;
	char	**input_list;
	int		must_free;
	int		error;

	++argv;
	input_list = argv;
	must_free = 0;
	if (argc == 2)
		input_list = ft_get_elems(&argc, argv, &must_free);
	error = ft_errors(argc, input_list);
	if (error <= 0)
	{
		ft_free_list(NULL, NULL, input_list, must_free);
		return (0);
	}
	stack_a = ft_create_stack(argc, input_list, 1);
	stack_b = ft_create_stack(argc, input_list, 0);
	if (ft_is_sorted(stack_a) == -1)
		ft_sort(stack_a, stack_b, argc);
	ft_free_list(stack_a, stack_b, input_list, must_free);
	return (0);
}

static char	**ft_get_elems(int *argc, char **argv, int *must_free)
{
	char	**split_list;

	split_list = ft_split(argv[0], ' ');
	*argc = ft_argv_count(split_list) + 1;
	*must_free = 1;
	return (split_list);
}

static int	ft_argv_count(char **argv)
{
	int	n;

	n = 0;
	while (argv[n])
		++n;
	return (n);
}

static void	ft_free_list(t_elem *stack_a, t_elem *stack_b,
				char **input_list, int must_free)
{
	return ;
}
