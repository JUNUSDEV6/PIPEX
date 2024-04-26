/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:50:53 by yohanafi          #+#    #+#             */
/*   Updated: 2024/04/26 15:38:54 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	exec(char *cmd, char **envp)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	if (!s_cmd)
		exit(EXIT_FAILURE);
	path = get_path(s_cmd, envp);
	if (!path)
		exit(EXIT_FAILURE);
}

void	here_txt(char **argv, int p_fd)
{
	char	*line;

	close(p_fd[0]);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			exit(EXIT_FAILURE);
		if (ft_strncmp(line, argv[2], ft_strlen(argv[2])))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		ft_putstr_fd(line, p_fd[1]);
		free(line);
	}
}

void	here_doc(char **argv)
{
	pid_t	pid;
	int		p_fd[2];
	
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

void	ft_pipe(char *cmd, char **envp)
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

int	main(int argc, char **argv, char *envp)
{
	int	i;
	int	fd_out;
	int	fd_in;

	if (!ft_strncmp(argv[2], "<<", 2))
	{
		if (argc < 3)
			exit(0);
		i = 3;
		fd_out = open_file(argv[1], 0, argc, envp);
		here_doc(argv);
	}
	while (i < argc - 2)
		ft_pipe(argv[i++], envp);
	dup2(fd_out, 1);
	//exec
}