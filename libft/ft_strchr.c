/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifarahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 22:58:51 by ifarahi           #+#    #+#             */
/*   Updated: 2019/09/28 22:58:52 by ifarahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int ch)
{
	char c;

	c = ch;
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == *s)
		return ((char *)s);
	return (NULL);
}
