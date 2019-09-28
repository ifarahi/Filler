/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifarahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 23:01:42 by ifarahi           #+#    #+#             */
/*   Updated: 2019/09/28 23:01:44 by ifarahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	s_strlen(const char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t d_len;
	size_t s_len;

	s_len = s_strlen(src);
	d_len = s_strlen(dest);
	if (size < d_len + 1)
		return (s_len + size);
	if (size > d_len)
		ft_strncat(dest, src, size - d_len - 1);
	return (d_len + s_len);
}
