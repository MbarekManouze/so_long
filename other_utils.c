/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 12:10:25 by mmanouze          #+#    #+#             */
/*   Updated: 2022/04/02 12:32:49 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlcpy(char	*dst, const char	*src, size_t	len)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (!*dst && !*src)
		return (0);
	while (src[j])
		j++;
	if (!len)
		return (j);
	i = 0;
	while (i < len - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}

int	ft_strcmp(const char	*s1, const char	*s2)
{
	unsigned int	i;
	unsigned char	*str;
	unsigned char	*ssr;

	str = (unsigned char *)s1;
	ssr = (unsigned char *)s2;

	i = 0;
	while ((str[i] && ssr[i]) && str[i] == ssr[i])
		i++;
	return (str[i] - ssr[i]);
}

char    *ft_strchr_p(char *buffer)
{
	size_t	i;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i])
	{
		if (buffer[i] == '.')
			return (buffer + i);
		i++;
	}
	return (NULL);
}
