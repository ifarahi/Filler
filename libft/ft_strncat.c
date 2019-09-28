/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifarahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 23:03:13 by ifarahi           #+#    #+#             */
/*   Updated: 2019/09/28 23:03:16 by ifarahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, char const *src, size_t n)
{
	size_t i;
	size_t len;

	i = 0;
	len = 0;
	while (dest[len])
		len++;
	while (src[i] && n > 0)
	{
		dest[len + i] = src[i];
		i++;
		n--;
	}
	dest[len + i] = '\0';
	return (dest);
}
