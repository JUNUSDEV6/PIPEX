/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:58:06 by yohanafi          #+#    #+#             */
/*   Updated: 2024/03/31 18:07:48 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//variable fd 
//function open -> open

static void	child_Parent_ex(char **argv, char **env, int pipe_fd, bool flag)
{
	int	fd;

	if (flag == true)
		fd = open_file(argv[2], flag);
	if (!flag)
		fd = open_file(argv[4], flag);
	if (fd == -1)
	{
		ft_putstr_fd(argv[2], 2);
		
	}

}

static int	path(char **env)
{
	while (*env)
	{
		if (ft_strnstr(env, "PATH", 4))
			exit(EXIT_SUCCES);
		env++;
	}
	exit(EXIT_FAILURE);
}

//check the way for env
//--error msg
// protect the pipe
// make de fork > pid and protect(-1)
int	main(int argc, char **argv, char **env)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (!path(env))
		exit(127);
	if (argc != 5)
		cmd_error();
	if (pipe(pipe_fd) == -1)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (!pid)
		child_Parent_ex(argv, env, pipe_fd, true);
	child_Parent_ex(argv, env, pipe_fd, false);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	int		i = 0;
	char	*full_paths;
	char	**cmd = ft_split(argv[1], ' ');
	while (*env)
	{
		if (!ft_strncmp(*env, "PATH", 4))
		{
			pipex.path = ft_split(*env + 5, ':');
			break;
		}
		env++;
	}
	if (!pipex.path)
	{
		printf("Aucun chemin trouvé dans la variable PATH.\n");
		return (1);
	}
	while (pipex.path[i])
	{
		full_paths = malloc(ft_strlen(pipex.path[i]) + ft_strlen(argv[1]) + 2);
		if (!full_paths)
		{
			perror("ERROR MALLOC");
			exit(EXIT_FAILURE);
		}
		//printf("%s\n", pipex.path[i]);
		ft_strcpy(full_paths, pipex.path[i]);
		ft_strcat(full_paths, "/");
		ft_strcat(full_paths, cmd[0]);
		if (access(full_paths, X_OK) == 0)
		{
			//printf("yo\n");
			printf("command find : %s\n", full_paths);
			execve(full_paths, cmd, env);
			perror("ERROR");
			free(full_paths);
			exit(EXIT_FAILURE);
		}
		//printf("pas bonne commande");
		free(full_paths);
		i++;
	}
	return(0);
}
