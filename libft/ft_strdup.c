/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifarahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 23:00:23 by ifarahi           #+#    #+#             */
/*   Updated: 2019/09/28 23:00:25 by ifarahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		index;
	int		len;

	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	if (!(str = ft_strnew(len)))
		return (NULL);
	index = 0;
	while (s1[index] != '\0')
	{
		str[index] = s1[index];
		index++;
	}
	str[index] = '\0';
	return (str);
}
