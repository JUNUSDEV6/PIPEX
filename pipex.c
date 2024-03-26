/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:58:06 by yohanafi          #+#    #+#             */
/*   Updated: 2024/03/26 11:17:25 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
// 1. get the env
// 2. recup the path
// 3. split
// 4. acces the argv
// 5. exev


int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	int		i = 0;
	char	*full_paths;
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
	int pid = fork();
	if (!pid) {
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
			ft_strcat(full_paths, argv[1]);
			if (access(full_paths, X_OK) == 0)
			{
				//printf("yo\n");
				printf("command find : %s\n", full_paths);
				execve(full_paths, &argv[1], env);
				perror("ERROR");
				free(full_paths);
				exit(EXIT_FAILURE);
			}
			//printf("pas bonne commande");
			free(full_paths);
			i++;
		}
	}
	else if (pid) {
		waitpid()
		printf("Le child a fini.\n");
	}
	return(0);
}
