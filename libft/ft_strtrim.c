/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifarahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 23:06:35 by ifarahi           #+#    #+#             */
/*   Updated: 2019/09/28 23:06:37 by ifarahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	s_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		start;
	int		lenght;
	int		end;

	if (s)
	{
		start = 0;
		end = ft_strlen(s);
		while (s_space(s[start]))
			start++;
		end--;
		while (s_space(s[end]))
			end--;
		lenght = end - start + 1;
		if (lenght <= 0)
			lenght = 1;
		if (!(str = ft_strsub(s, start, lenght)))
			return (NULL);
		if (lenght == 1)
			str[0] = '\0';
		return (str);
	}
	return (0);
}
