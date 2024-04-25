/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:26:44 by passunca          #+#    #+#             */
/*   Updated: 2024/04/25 19:59:17 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_check_op(t_elem *stack_a, t_elem *stack_b, char *op);
static int	ft_parse_op(char *op, t_elem *stack_a, t_elem *stack_b);

void	ft_check_stack(t_elem *stack_a, t_elem *stack_b)
{
	int		result;
	int		start;
	char	*line;

	result = 1;
	while (result)
	{
		line = get_next_line(0);
		if (!line)
			result = 0;
		else
			ft_check_op(stack_a, stack_b, line);
	}
	start = 0;
	while ((stack_b[start].index != -1) && (stack_b[start].set != 1))
		++start;
	if (!(ft_is_sorted(stack_a) == 1) && (stack_b[start].index == -1))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

static void	ft_check_op(t_elem *stack_a, t_elem *stack_b, char *op)
{
	int		result;

	if ((op == NULL) || (ft_strlen(op) == 1))
		result = -1;
	else
		result = ft_parse_op(op, stack_a, stack_b);
	if (op != NULL)
		free(op);
	if (result == -1)
	{
		free(stack_a);
		free(stack_b);
		get_next_line(0);
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
}

static int	ft_parse_op(char *op, t_elem *stack_a, t_elem *stack_b)
{
	if (ft_strncmp(op, "pa\n", 3) == 0)
		ft_push_elem(stack_b, stack_a);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		ft_push_elem(stack_a, stack_b);
	else if (ft_strncmp(op, "sa\n", 3) == 0)
		ft_swap_elem(stack_a);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		ft_swap_elem(stack_b);
	else if (ft_strncmp(op, "ss\n", 3) == 0)
		ft_swap_both(stack_a, stack_b);
	else if (ft_strncmp(op, "ra\n", 3) == 0)
		ft_rotate(stack_a);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		ft_rotate(stack_b);
	else if (ft_strncmp(op, "rr\n", 3) == 0)
		ft_rotate_both(stack_a, stack_b, 0);
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		ft_rev_rotate(stack_a);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		ft_rev_rotate(stack_b);
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		ft_rotate_both(stack_a, stack_b, 1);
	else
		return (-1);
	return (1);
}
