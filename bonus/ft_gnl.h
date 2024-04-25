/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:01:07 by passunca          #+#    #+#             */
/*   Updated: 2024/04/25 10:02:35 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GNL_H
# define FT_GNL_H

# include "../lib/libft/libft/libft.h"			// libft library
# include "../lib/libft/ft_printf/ft_printf.h" 	// ft_printf

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*ft_gnl(int fd, int del);
int		ft_strchr_index(char *s, int c);
void	*f_calloc(int size, int nb);
char	*ft_strjoin_gnl(char *s1, char *s2);

#endif
