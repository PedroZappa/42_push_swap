/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:26:44 by passunca          #+#    #+#             */
/*   Updated: 2024/04/26 13:07:24 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_check_op(t_elem *stack_a, t_elem *stack_b, char *op);
static int	ft_parse_op(char *op, t_elem *stack_a, t_elem *stack_b);
static int	ft_strncmp_checker(char *s1, char *s2, size_t n);

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
	if ((ft_is_sorted(stack_a) == 1) && (stack_b[start].index == -1))
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
	if (ft_strncmp_checker(op, "pa\n", 3) == 0)
		ft_push_elem(stack_b, stack_a);
	else if (ft_strncmp_checker(op, "pb\n", 3) == 0)
		ft_push_elem(stack_a, stack_b);
	else if (ft_strncmp_checker(op, "sa\n", 3) == 0)
		ft_swap_elem(stack_a);
	else if (ft_strncmp_checker(op, "sb\n", 3) == 0)
		ft_swap_elem(stack_b);
	else if (ft_strncmp_checker(op, "ss\n", 3) == 0)
		ft_swap_both(stack_a, stack_b);
	else if (ft_strncmp_checker(op, "ra\n", 3) == 0)
		ft_rotate(stack_a);
	else if (ft_strncmp_checker(op, "rb\n", 3) == 0)
		ft_rotate(stack_b);
	else if (ft_strncmp_checker(op, "rr\n", 3) == 0)
		ft_rotate_both(stack_a, stack_b, 0);
	else if (ft_strncmp_checker(op, "rra\n", 4) == 0)
		ft_rev_rotate(stack_a);
	else if (ft_strncmp_checker(op, "rrb\n", 4) == 0)
		ft_rev_rotate(stack_b);
	else if (ft_strncmp_checker(op, "rrr\n", 4) == 0)
		ft_rotate_both(stack_a, stack_b, 1);
	else
		return (-1);
	return (1);
}

static int	ft_strncmp_checker(char *s1, char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
