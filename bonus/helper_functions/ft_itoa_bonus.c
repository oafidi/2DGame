/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oafidi <oafidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:20:46 by oafidi            #+#    #+#             */
/*   Updated: 2025/02/27 00:08:20 by oafidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	nbr_digits(int nb)
{
	int	size;

	size = 0;
	if (nb <= 0)
		size++;
	while (nb != 0)
	{
		size++;
		nb = nb / 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*p;
	int		i;

	nb = n;
	i = nbr_digits(nb);
	p = malloc(i + 1);
	if (p == NULL)
		return (NULL);
	p[i] = '\0';
	if (nb == 0)
		p[0] = 48;
	if (nb < 0)
	{
		p[0] = '-';
		nb = -nb;
	}
	i = i - 1;
	while (nb != 0)
	{
		p[i] = (nb % 10) + 48;
		nb = nb / 10;
		i--;
	}
	return (p);
}
