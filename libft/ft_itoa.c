/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifarahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 22:52:26 by ifarahi           #+#    #+#             */
/*   Updated: 2019/09/28 22:52:28 by ifarahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_count_digits(long long int nb)
{
	long long int			total;
	unsigned long long int	nbr;

	total = 0;
	if (nb < 0)
		nb *= -1;
	nbr = (unsigned long long int)nb;
	while (nbr >= 10)
	{
		nbr /= 10;
		total++;
	}
	total++;
	return (total);
}

long long int	ft_abs_l(long long int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

char			*ft_itoa(long long int n)
{
	char					*number;
	int						i;
	unsigned long long int	nbr;
	int						digitscount;

	digitscount = ft_count_digits(n);
	if (n < 0)
		digitscount++;
	n = ft_abs_l(n);
	number = (char *)malloc(sizeof(char) * (digitscount + 1));
	if (number == NULL)
		return (NULL);
	number[0] = '-';
	nbr = (unsigned long long int)n;
	i = digitscount;
	number[i--] = '\0';
	while (nbr >= 10)
	{
		number[i--] = '0' + (nbr % 10);
		nbr /= 10;
	}
	number[i] = '0' + nbr;
	return (number);
}
