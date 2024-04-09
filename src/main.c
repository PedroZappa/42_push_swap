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

/*	Set flag to signal if alloced memory needs freeing;
 *	Increment argv to skip program name;
 *	Assign argv to input_list;
 *
 * */
int	main(int argc, char **argv)
{
	t_elem	*stack_a;
	t_elem	*stack_b;
	char	**input_list;
	int		must_free;
	int		error;

	must_free = 0;
	++argv;
	input_list = argv;

	return (0);
}
