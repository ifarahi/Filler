/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifarahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 23:04:55 by ifarahi           #+#    #+#             */
/*   Updated: 2019/09/28 23:04:56 by ifarahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	str = malloc(sizeof(char) * size + 1);
	if (str == 0)
		return (NULL);
	else
		ft_bzero(str, size + 1);
	str[size] = '\0';
	return (str);
}
