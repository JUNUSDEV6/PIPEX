/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:58:06 by yohanafi          #+#    #+#             */
/*   Updated: 2024/04/04 10:10:49 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_excv(char **env, char *cmd)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	if (!s_cmd)
		exit(EXIT_FAILURE);
	path = get_path(s_cmd[0], env, 0);
	if (!path)
	{
		ft_putstr_fd("ERROR: CMD :", 2);
		ft_putendl_fd(s_cmd[0], 2);
		ft_free_tab(s_cmd);
		exit(127);
	}
	if (execve(path, s_cmd, env) == -1)
	{
		ft_putstr_fd("ERROR: CMD :", 2);
		ft_putendl_fd(s_cmd[0], 2);
		ft_free_tab(s_cmd);
		exit(126);
	}
}

static void	child_parent_ex(char **argv, char **env, int *pipe_fd, bool flag)
{
	int	fd;

	fd = open_file(argv[1], argv[4], flag);
	if (fd == -1)
	{
		perror("file1 or file2");
		exit(0);
	}
	if (flag)
	{
		dup2(fd, 0);
		dup2(pipe_fd[1], 1);
		close(pipe_fd[0]);
		ft_excv(env, argv[2]);
	}
	else
	{
		dup2(fd, 1);
		dup2(pipe_fd[0], 0);
		close(pipe_fd[1]);
		ft_excv(env, argv[3]);
	}
}

static int	path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH", 4))
			return (EXIT_SUCCESS);
		i++;
	}
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv, char **env)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (path(env))
		exit(127);
	if (argc != 5)
		cmd_error();
	if (pipe(pipe_fd) == -1)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (!pid)
		child_parent_ex(argv, env, pipe_fd, true);
	child_parent_ex(argv, env, pipe_fd, false);
}
