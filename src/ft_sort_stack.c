/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 08:36:28 by passunca          #+#    #+#             */
/*   Updated: 2024/04/13 12:42:16 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_calc_move(t_elem *stack_a, t_elem *stack_b,
						 int idx, int stack_len);
static int	ft_best_op_idx(t_elem *stack_a, t_elem *stack_b, int stack_len);
static int	ft_rotate_top(t_elem *stack_a, int index, char *r, char *rr);

void	ft_sort_stack(t_elem *stack_a, t_elem *stack_b, int stack_len)
{
	int	i;
	int	median;

	i = ft_get_stack_start(stack_a);
	median = ft_get_median(stack_a);
	while (i < (stack_len - 4))
	{
		ft_push_elem(stack_a, stack_b, "pb\n");
		if ((stack_b[ft_get_stack_start(stack_b)].num > median)
			&& ((ft_get_stack_end(stack_a) - ft_get_stack_start(stack_a)) + 1) > 3)
			ft_rotate(stack_b, "rb\n");
		++i;
	}
	ft_sort_three(stack_a);
	i = ft_get_stack_start(stack_b);
	while (i < ft_get_stack_end(stack_b))
	{
		ft_calc_move(stack_b, stack_a, \
			ft_best_op_idx(stack_b, stack_a, stack_len), stack_len);
		++i;
	}
	ft_rotate_top(stack_a, ft_min_above_thresh(stack_a, stack_b[i].num).index, \
	"ra\n", "rra\n");
	ft_push_elem(stack_b, stack_a, "pa\n");
	ft_rotate_top(stack_a, ft_get_stack_min(stack_a).index, "ra\n", "rra\n");
}

static void	ft_calc_move(t_elem *stack_a, t_elem *stack_b,
						 int idx, int stack_len)
{
	(void) stack_a;
	(void) stack_b;
	(void) idx;
	(void) stack_len;
}

static int	ft_best_op_idx(t_elem *stack_a, t_elem *stack_b, int stack_len)
{
	(void) stack_a;
	(void) stack_b;
	(void) stack_len;
	return (0);
}

static int	ft_rotate_top(t_elem *stack_a, int index, char *r, char *rr)
{
	(void) stack_a;
	(void) index;
	(void) r;
	(void) rr;
	return (0);
}
