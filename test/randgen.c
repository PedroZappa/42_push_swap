/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randgen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:52:00 by passunca          #+#    #+#             */
/*   Updated: 2024/04/19 15:04:19 by passunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "randgen.h"
#include "../lib/pcg-c/include/pcg_variants.h"

int main(int argc, char **argv) 
{
    int				n_randnum;
	int32_t		random_number;
	int64_t		seed;	
    pcg32_random_t	rng;

	if (argc != 3)
        seed = time(NULL); // If no seed is provided, generate one based on the current time
	else
        seed = strtoull(argv[2], NULL, 10); // Convert seed to uint64_t
    n_randnum = atoi(argv[1]);
    if (n_randnum <= 0)
	{
        ft_printf("Error: The number of random numbers must be greater than 0.\n");
        return (1);
    }
	// Use the provided seed and a fixed initseq 
    pcg32_srandom_r(&rng, seed, 54u);
    for (int i = 0; i < n_randnum; i++)
	{
        random_number = pcg32_random_r(&rng);
        ft_printf("%d\n",random_number);
    }
    return (0);
}
