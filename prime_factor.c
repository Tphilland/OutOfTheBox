/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prime_factor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphillan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 22:08:39 by tphillan          #+#    #+#             */
/*   Updated: 2019/11/07 22:08:52 by tphillan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/* This code inputs any integer and prints out all its prime factors*/

void	print(int num, int j)
{
		printf("%d ", num);
}

int is_prime(int facto)
{
	//prime factors of positive int
	int i;
	int j;

	i = 2;
	j = 1;

	//finding pfactors and j++
	while(i < facto)
	{
		int var;
		var = facto % i;
		if (var == 0)
			return (0);
		i++;
	}
	return (1);
}

void	is_factor(int pos_int)
{
	//factors of pos_int
	int facto = 2;
	int k;
	int pos;
	int facnum;

	pos = 1;
	facnum = 0;
	while (facto < pos_int)
	{
		k = 10;
		if (pos_int % facto == 0)
			k = is_prime(facto);
		if (k == 1)
		{
			print(facto, pos);
			pos++;
			facto++;
			facnum++;
		}
		else
			facto++;
	}
	if (facnum == 0)
		printf("%d", pos_int);
}

int	main(int ac, const char ** av)
{
	if (ac == 2)
	{
		int poi;

		poi = atoi(av[1]);
		is_factor(poi);
	}
	printf("\n");
	return (0);
}
