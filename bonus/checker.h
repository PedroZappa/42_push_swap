/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 07:52:57 by passunca          #+#    #+#             */
/*   Updated: 2024/04/25 09:09:25 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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

/* ft_assert_stack.c */
int		ft_is_sorted(t_elem *stack);
int		ft_stack_start(t_elem *stack);
int		ft_stack_end(t_elem *stack);

/* ft_create_stack.c */
t_elem	*ft_create_stack(int argc, char **argv, int stack);

/* ft_errors.c */
int		ft_errors(int argc, char **input_list);

/* ft_ops.c */
void	ft_swap_elem(t_elem *stack);
void	ft_push_elem(t_elem *stack_a, t_elem *stack_b);
void	ft_rotate(t_elem *stack);
void	ft_rev_rotate(t_elem *stack);

/* ft_ops_mult.c */
void	ft_swap_both(t_elem *stack_a, t_elem *stack_b);
void	ft_rotate_both(t_elem *stack_a, t_elem *stack_b, int direction);

#endif
