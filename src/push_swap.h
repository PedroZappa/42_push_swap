/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:01:22 by passunca          #+#    #+#             */
/*   Updated: 2024/04/18 11:46:54 by passunca         ###   ########.fr       */
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
	int	set;
}	t_elem;

//=============================================================================/
//							Function Prototypes                                /
//=============================================================================/

/* ft_create_stack.c */
t_elem	*ft_create_stack(int argc, char **argv, int stack);

/* ft_errors.c */
int		ft_errors(int argc, char **argv);

/* ft_median.c */
int		ft_get_median(t_elem *stack);
t_elem	ft_min_above_thresh(t_elem *stack, int threshold);

/* ft_ops.c */
void	ft_swap_elem(t_elem *stack, char *msg);
void	ft_push_elem(t_elem *stack_a, t_elem *stack_b, char *msg);

/* ft_order.c */
int		ft_check_order(t_elem *stack_a, t_elem *stack_b, int idx);
void	ft_order(t_elem *stack_a, t_elem *stack_b, int idx);
int		ft_getontop_ops(t_elem *stack_a, int idx, int sign);

/* ft_rotate.c */
void	ft_rotate(t_elem *stack, char *msg);
void	ft_rev_rotate(t_elem *stack, char *msg);
int		ft_rotate_top(t_elem *stack_a, int index, char *r, char *rr);
void	ft_rotate_both(t_elem *stack_a, t_elem *stack_b, int direction);

/* ft_sort_stack.c */
void	ft_sort_stack(t_elem *stack_a, t_elem *stack_b, int stack_len);

/* ft_sort_three.c */
void	ft_sort_three(t_elem *stack);

/* ft_stack.c */
int		ft_is_sorted(t_elem *stack);
int		ft_stack_start(t_elem *stack);
int		ft_stack_end(t_elem *stack);
t_elem	ft_stack_min(t_elem *stack);
t_elem	ft_stack_max(t_elem *stack, int threshold);

#endif
