/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youneshanafi <youneshanafi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:33:34 by youneshanaf       #+#    #+#             */
/*   Updated: 2024/01/16 18:00:38 by youneshanaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	add_scmd_to_lst(int i, t_cmd *scmd, t_pipex *pipex)
{
	if (i == 0)
		pipex->cmd_list = ft_lstnew(scmd);
	else 
		ft_lstadd_back(&pipex->cmd_list, ft_lstnew(scmd));
}

int	argv_to_cmd(int i, char *argv, t_pipex *pipex)
{
	char	*cmd;
	t_cmd	*scmd;

	scmd = ft_calloc(1, sizeof(t_cmd));
	if (!scmd)
		return (0);
	cmd = ft_strtrim(argv, " ");
	if (!cmd)
		return (0);
	scmd->arg_path = ft_split(cmd, " ");
	free(cmd);
	if (!scmd->argv_path)
		return (0);
	if (acces(scmd->argv_path[0], X_OK) != 0)
		if (!remplace_cmd_to_path(scmd, pipex))
			return (0);
	add_scmd_to_lst(i, scmd, pipex);
	return (1);
}

analyse_cmd(int argc, char **argv, t_pipex *pipex)
{
	int	i;
	int	j;

	i = 0;
	if (pipex->here_doc == 1)
	{
		pipex->nbr_cmd = argc - 4;
		j = 3;
	}
	else
	{
		pipex->nbr_cmd = argc - 3;
		j = 2;
	}
	while (i < nbr_cmd)
	{
		if (!argv_to_cmd(i, argv[j], pipex))
			//error
		i++;
		j++;
	}
}
