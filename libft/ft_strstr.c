/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifarahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 23:06:04 by ifarahi           #+#    #+#             */
/*   Updated: 2019/09/28 23:06:06 by ifarahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	nlen;
	int hlen;

	nlen = ft_strlen(needle);
	hlen = ft_strlen(haystack);
	if (!nlen)
		return ((char *)haystack);
	while (hlen >= nlen)
	{
		if (!ft_strncmp(haystack, needle, nlen))
			return (char *)(haystack);
		haystack++;
		hlen--;
	}
	return (NULL);
}
