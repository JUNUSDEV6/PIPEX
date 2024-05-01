/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:50:53 by yohanafi          #+#    #+#             */
/*   Updated: 2024/05/01 15:51:04 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	exec(char *cmd, char **envp)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	if (!s_cmd)
		exit(EXIT_FAILURE);
	path = get_path(*s_cmd, envp);
	if (!path)
		exit(EXIT_FAILURE);
	if (execve(path, s_cmd, envp) == -1)
		exit(EXIT_FAILURE);
}

static void	here_txt(char **argv, int *p_fd)
{
	char	*line;

	//printf("6");
	close(p_fd[0]);
	while (1)
	{
		line = get_next_line(0);
		//printf("%s", line);
		if (!line)
			exit(EXIT_FAILURE);
		if (!ft_strncmp(line, argv[2], ft_strlen(argv[2])))
		{
			//printf("0\n");
			//printf("%s\n", line);
			free(line);
			exit(EXIT_SUCCESS);
		}
		ft_putstr_fd(line, p_fd[1]);
		free(line);
	}
}

static void	here_doc(char **argv)
{
	pid_t	pid;
	int		p_fd[2];
	//printf("4");
	if (pipe(p_fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (!pid)
		here_txt(argv, p_fd);
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], 0);
		wait(0);
	}
}

static void	ft_pipe(char *cmd, char **envp)
{
	pid_t	pid;
	int		p_fd[2];

	if (pipe(p_fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (!pid)
	{
		close(p_fd[0]);
		dup2(p_fd[1], 1);
		exec(cmd, envp);
	}
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], 0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	fd_out;
	int	fd_in;

	if (!ft_strncmp(argv[1], "heredoc", 7))
	{
		//printf("1");
		if (argc < 6)
			exit(0);
		i = 3;
		//printf("1");
		fd_out = open_file(argv[argc - 1], 2, argv, envp);
		//printf("3");
		here_doc(argv);
	}
	else
	{
		i = 1;
		fd_in = 1;
		fd_out = 1;
		dup2(fd_in, 0);
	}
	while (i < argc - 1)
		ft_pipe(argv[i++], envp);
	dup2(fd_out, 1);
	exec(argv[argc - 1], envp);
}
