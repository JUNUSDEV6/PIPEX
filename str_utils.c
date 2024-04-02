/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:18:30 by yohanafi          #+#    #+#             */
/*   Updated: 2024/04/02 12:06:42 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strnstr(const char *find, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!find && !len)
		return (0);
	if (to_find[0] == '\0' || to_find == find)
		return ((char *)find);
	while (find[i] != '\0')
	{
		j = 0;
		while (find[i + j] == to_find[j] && (i + j) < len)
		{
			if (find[i + j] == '\0' && to_find[j] == '\0')
				return ((char *)&find[i]);
			j++;
		}
		if (to_find[j] == '\0')
			return ((char *)(find + i));
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dst)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dst[i] = s2[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}
