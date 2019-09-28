/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifarahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 10:53:51 by ifarahi           #+#    #+#             */
/*   Updated: 2018/10/22 11:42:12 by ifarahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*area;
	size_t	size;

	if (s1 && s2)
		size = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	else if (s1)
		size = ft_strlen((char*)s1);
	else if (s2)
		size = ft_strlen((char*)s2);
	else
		return (NULL);
	if (!(area = ft_memalloc(size)))
		return (NULL);
	if (s1)
		area = ft_strcpy(area, (char*)s1);
	else
		area = ft_strcpy(area, (char*)s2);
	if (s1 && s2)
		area = ft_strcat(area, (char*)s2);
	return (area);
}
