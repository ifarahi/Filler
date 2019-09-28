/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifarahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 22:55:44 by ifarahi           #+#    #+#             */
/*   Updated: 2019/09/28 22:55:46 by ifarahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	const char	*s;
	char		*d;

	s = src;
	d = dest;
	if (dest > src)
	{
		d += len;
		s += len;
		while (len--)
		{
			*--d = *--s;
		}
	}
	else
	{
		while (len--)
		{
			*d++ = *s++;
		}
	}
	return (dest);
}
