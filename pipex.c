/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:58:06 by yohanafi          #+#    #+#             */
/*   Updated: 2024/03/22 12:33:10 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
// 1. get the env
// 2. recup the path
// 3. split
// 4. acces the argv
// 5. exev

int	ft_strncmp(const char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	int		i = 0;
	while (*env)
	{
		if (!ft_strncmp(*env, "PATH", 4))
		{
			pipex.path = ft_split(*env + 5, ':');
			break;
		}
		env++;
	}
	while (pipex.path[i])
		printf("%s\n",pipex.path[i++]);
	/*
	pipex.cmd = *ft_split(pipex.path, ':');
	printf("%s",pipex.cmd);*/
	return(0);
}