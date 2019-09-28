/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifarahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 23:05:11 by ifarahi           #+#    #+#             */
/*   Updated: 2019/09/28 23:05:14 by ifarahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t nlen;
	size_t hlen;
	size_t i;

	nlen = ft_strlen(needle);
	hlen = ft_strlen(haystack);
	i = 0;
	if (!nlen)
		return (char *)(haystack);
	while (hlen >= nlen && i + nlen <= len)
	{
		if (!ft_strncmp(haystack, needle, nlen))
			return (char *)(haystack);
		haystack++;
		hlen--;
		++i;
	}
	return (NULL);
}
