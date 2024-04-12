/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:01:22 by passunca          #+#    #+#             */
/*   Updated: 2024/04/12 14:43:04 by passunca         ###   ########.fr       */
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

/* ft_stack.c */
t_elem	*ft_create_stack(int argc, char **argv, int stack);
int		ft_is_sorted(t_elem *stack);
int		ft_get_stack_start(t_elem *stack);
int		ft_get_stack_end(t_elem *stack);

/* ft_errors.c */
int		ft_errors(int argc, char **argv);

/* ft_ops.c */
void	ft_swap_elem(t_elem *stack, char *msg);

/* ft_sort_three.c */
void	ft_sort_three(t_elem *stack);

#endif
