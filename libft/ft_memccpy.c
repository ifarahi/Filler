/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifarahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 22:54:30 by ifarahi           #+#    #+#             */
/*   Updated: 2019/09/28 22:54:32 by ifarahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;
	size_t				i;

	s = src;
	d = dest;
	i = 0;
	while (i < n)
	{
		*d = *s;
		if (*s == (unsigned char)c)
		{
			return (d + 1);
		}
		s++;
		d++;
		++i;
	}
	return (0);
}
