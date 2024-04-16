/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:01:22 by passunca          #+#    #+#             */
/*   Updated: 2024/04/16 16:34:02 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//=============================================================================/
//								Variables                                      /
//=============================================================================/

//=============================================================================/
//								Librariy Headers                               /
//=============================================================================/

# include "../lib/libft/libft/libft.h"			// libft library
# include "../lib/libft/ft_printf/ft_printf.h" 	// ft_printf

//=============================================================================/
//                               Structures                                    /
//=============================================================================/

// Stack element
typedef struct s_elem {
	int	num;
	int	index;
	int	filled;
}	t_elem;

//=============================================================================/
//							Function Prototypes                                /
//=============================================================================/

/* ft_create_stack.c */
t_elem	*ft_create_stack(int argc, char **argv, int stack);

/* ft_stack.c */
int		ft_is_sorted(t_elem *stack);
int		ft_get_stack_start(t_elem *stack);
int		ft_get_stack_end(t_elem *stack);
t_elem	ft_get_stack_min(t_elem *stack);
t_elem	ft_get_stack_max(t_elem *stack, int threshold);

/* ft_errors.c */
int		ft_errors(int argc, char **argv);

/* ft_ops.c */
void	ft_swap_elem(t_elem *stack, char *msg);
void	ft_rotate(t_elem *stack, char *msg);
void	ft_rev_rotate(t_elem *stack, char *msg);
void	ft_push_elem(t_elem *stack_a, t_elem *stack_b, char *msg);

/* ft_median.c */
int		ft_get_median(t_elem *stack);
t_elem	ft_min_above_thresh(t_elem *stack, int threshold);

/* ft_sort_three.c */
void	ft_sort_three(t_elem *stack);

/* ft_sort_stack.c */
void	ft_sort_stack(t_elem *stack_a, t_elem *stack_b, int stack_len);

/* ft_order.c */
int		ft_check_order(t_elem *stack_a, t_elem *stack_b, int idx);
void	ft_order(t_elem *stack_a, t_elem *stack_b, int idx);
int		get_op_for_topplace(t_elem *stack_a, int idx, int sign);

#endif
