/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youneshanafi <youneshanafi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:36:37 by youneshanaf       #+#    #+#             */
/*   Updated: 2024/01/17 17:46:07 by youneshanaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}	

static int	ft_checker(char const *str, char const *c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char ft_strcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src))
}

char	*strtrim(const char *s1, char const *set)
{
	char	*dst;
	size_t	size;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_checker(set, *s1))
		s1++;
	size = ft_strlen(s1);
	while (size != 0 && ft_checker(set, s1[size - 1]))
		size--;
	ft_strcpy(dst, (char *)s1, size + 1);
	return (dst);
}
