/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:21:18 by passunca          #+#    #+#             */
/*   Updated: 2024/04/13 08:39:40 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**ft_get_elems(int *argc, char **argv, int *must_free);
static int	ft_argv_count(char **argv);
static void	ft_free_ps(t_elem *stack_a, t_elem *stack_b,
				char **input_list, int must_free);
static void	ft_sort(t_elem *stack_a, t_elem *stack_b, int argc);

/*	PUSH_SWAP
 *	- Increment argv to skip program name;
 *	- Assign argv to input_list;
 *	- Set flag to signal if alloced memory needs freeing;
 *	- Handle input arguments;
 *	- Check for errors;
 *		- If there is an error free allocated memory;,
 *	- Create stack_a and stack_b;
 *	- if stack_a is not sorted
 *		- sort it
 *	- Free allocated memory
 * */
int	main(int argc, char **argv)
{
	char	**input_list;
	t_elem	*stack_a;
	t_elem	*stack_b;
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
		ft_free_ps(NULL, NULL, input_list, must_free);
		return (0);
	}
	stack_a = ft_create_stack(argc, input_list, 1);
	stack_b = ft_create_stack(argc, input_list, 0);
	if (ft_is_sorted(stack_a) == -1)
		ft_sort(stack_a, stack_b, argc);
	ft_free_ps(stack_a, stack_b, input_list, must_free);
	return (0);
}

/*	ft_get_elems()
 *	- Get args by splitting input list;
 *	- Count args in input list;
 *	- Set flag to signal that alloced memory needs freeing;
 *	- Return list of args
 *	*/
static char	**ft_get_elems(int *argc, char **argv, int *must_free)
{
	char	**split_list;

	split_list = ft_split(argv[0], ' ');
	*argc = ft_argv_count(split_list) + 1;
	*must_free = 1;
	return (split_list);
}

/* ft_argv_count() 
 *	- Count args in input list;
 *	- Return count;
 *	*/
static int	ft_argv_count(char **argv)
{
	int	n;

	n = 0;
	while (argv[n])
		++n;
	return (n);
}

/*	ft_free_ps()
*	- Free allocated memory;
*	*/
static void	ft_free_ps(t_elem *stack_a, t_elem *stack_b,
				char **input_list, int must_free)
{
	int	i;

	i = 0;
	if (must_free)
	{
		while (input_list[i] != 0)
		{
			free(input_list[i]);
			++i;
		}
		free(input_list[i]);
		free(input_list);
	}
	if (stack_a != NULL)
		free(stack_a);
	if (stack_b != NULL)
		free(stack_b);
	return ;
}

static void	ft_sort(t_elem *stack_a, t_elem *stack_b, int argc)
{
	if (argc == 3)
	{
		if (ft_is_sorted(stack_a) == -1)
			ft_swap_elem(stack_a, "sa\n");
	}
	else if (argc == 4)
		ft_sort_three(stack_a);
	else
		ft_sort_stack(stack_a, stack_b, argc);
}
