/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 08:03:22 by passunca          #+#    #+#             */
/*   Updated: 2024/04/25 08:03:35 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_are_args_nbr(int argc, char **argv);
static int	ft_is_duplicate(int argc, char **argv);

/*	ft_errors()
 *	- If there are no input arguments return 0;
 *	- if args are not numbers return -1;
 *	- if there are duplicate numbers return -1;
 *
 * */
int	ft_errors(int argc, char **input_list)
{
	if (argc == 1)
		return (0);
	if (ft_are_args_nbr(argc, input_list) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	if (ft_is_duplicate(argc, input_list) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	return (1);
}

/*	ft_are_args_nbr()
 *	- Loop through arguments
 *		- if NOT a digit
 *			- if NOT the first character AND NOT a '-'
 * */
static int	ft_are_args_nbr(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < (argc - 1))
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) == 0)
				if (!((j == 0) && (argv[i][j] == '-')))
					return (-1);
			++j;
		}
		++i;
	}
	return (1);
}

/*	ft_is_duplicate()
 *	- If argc == 2
 *		- if arg is the max int return -1
 *	- Loop through arguments comparing them 
 *		- if either is the max int return -1
 *		- check for duplicates
 *	*/
static int	ft_is_duplicate(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc == 2)
		if (ft_atoi(argv[0]) == INT_MAX)
			return (-1);
	i = 0;
	while (i < argc)
	{
		j = (i + 1);
		while (j < (argc - 1))
		{
			if ((ft_atoi(argv[i]) == INT_MAX) || (ft_atoi(argv[j]) == INT_MAX))
				return (-1);
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (-1);
			++j;
		}
		++i;
	}
	return (0);
}
