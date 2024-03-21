/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:58:06 by yohanafi          #+#    #+#             */
/*   Updated: 2024/03/21 14:07:35 by yohanafi         ###   ########.fr       */
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

	while (*env)
	{
		if (!ft_strncmp(*env, "PATH", 4))
			pipex.path = *env + 5;
		env++;
	}
	pipex.cmd = *ft_split(pipex.path, ':');
	printf("%c",pipex.cmd);
	return(0);
}