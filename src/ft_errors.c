/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:37:27 by passunca          #+#    #+#             */
/*   Updated: 2024/04/09 15:38:45 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_are_args_nbr(int argc, char **argv);
static int	ft_is_duplicate(int argc, char **argv);

int	ft_errors(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	if (argc == 1)
		return (0);
	if (ft_are_args_nbr(argc, argv) == -1)
	{
		ft_putstr_fd("Error\n", 1);
		return (-1);
	}
	if (ft_is_duplicate(argc, argv) == -1)
	{
		ft_putstr_fd("Error\n", 1);
		return (-1);
	}
	return (1);
}

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
				if ((j != 0) && (argv[i][j] != '-'))
					return (-1);
			++j;
		}
		++i;
	}
	return (1);
}

static int	ft_is_duplicate(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	return (0);
}
