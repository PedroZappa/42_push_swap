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
    if (argc != 3) {
        ft_printf("Usage: %s <n_num> <seed>\n", argv[0]);
        return (1);
    }

    int			n_randnum = atoi(argv[1]);
	uint64_t	seed = strtoull(argv[2], NULL, 10); // Convert seed to uint64_t

    if (n_randnum <= 0) {
        ft_printf("Error: The number of random numbers must be greater than 0.\n");
        return 1;
    }

    pcg32_random_t rng;
    pcg32_srandom_r(&rng, seed, 54u); // Use the provided seed and a fixed initseq

    for (int i = 0; i < n_randnum; i++) {
        uint32_t random_number = pcg32_random_r(&rng);
        ft_printf("%u\n", random_number);
    }
    return (0);
}
