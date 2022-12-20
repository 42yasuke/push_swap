/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:09:21 by jralph            #+#    #+#             */
/*   Updated: 2022/11/13 10:09:23 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_cpy(char *res, char const *s, size_t start)
{
	size_t	i;

	i = start;
	while (*s)
	{
		res[i] = *s;
		s++;
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len;

	len = 1;
	if (*s1)
		len += ft_strlen(s1);
	if (*s2)
		len += ft_strlen(s2);
	res = malloc (sizeof(*s1) * len);
	if (!res)
		return (NULL);
	ft_cpy(res, s1, 0);
	ft_cpy(res, s2, ft_strlen(s1));
	res[len - 1] = 0;
	return (res);
}
