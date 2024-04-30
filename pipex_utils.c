/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:19:14 by yohanafi          #+#    #+#             */
/*   Updated: 2024/04/30 12:52:32 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *argv_in, char *argv_out, bool flag)
{
	int	rlt;

	if (flag == true)
	{
		rlt = open(argv_in, O_RDONLY, 0777);
	}
	else
	{
		rlt = open(argv_out, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	}
	return (rlt);
}

char	*ft_free_tab(char **tabs)
{
	size_t	i;

	i = 0;
	while (tabs[i])
	{
		free(tabs[i]);
		i++;
	}
	free(tabs);
	return (NULL);
}

char	*get_path(char *cmd, char **env, int i)
{
	char	**paths;
	char	*path_cmd;
	char	*full_paths;

	if (!access(cmd, X_OK))
		return (cmd);
	while (!ft_strnstr(env[i], "PATH", 4))
		i++;
	paths = ft_split(env[i] + 5, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		path_cmd = ft_strjoin(paths[i++], "/");
		full_paths = ft_strjoin(path_cmd, cmd);
		if (!path_cmd)
			free(path_cmd);
		if (!access(full_paths, X_OK))
			return (full_paths);
		if (full_paths)
			free(full_paths);
	}
	return (ft_free_tab(paths));
}
