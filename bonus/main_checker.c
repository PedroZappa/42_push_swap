/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 07:58:08 by passunca          #+#    #+#             */
/*   Updated: 2024/04/25 19:15:25 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	**ft_get_elems(int *argc, char **argv, int *must_free);
static int	ft_argv_count(char **argv);
static void	ft_free(char **input_list, int must_free);

/* push_swap checker */
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
		ft_free(input_list, must_free);
		return (0);
	}
	stack_a = ft_create_stack(argc, input_list, 1);
	stack_b = ft_create_stack(argc, input_list, 0);
	ft_free(input_list, must_free);
	ft_check_stack(stack_a, stack_b);
	free(stack_a);
	free(stack_b);
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

/*	ft_free()
*	- Free allocated memory;
*	*/
static void	ft_free(char **input_list, int must_free)
{
	int	i;

	if (must_free)
	{
		i = 0;
		while (input_list[i] != 0)
		{
			free(input_list[i]);
			++i;
		}
		free(input_list[i]);
		free(input_list);
	}
}
