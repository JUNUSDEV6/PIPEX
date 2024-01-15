/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youneshanafi <youneshanafi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:20:39 by youneshanaf       #+#    #+#             */
/*   Updated: 2024/01/15 14:29:58 by youneshanaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.c"

void	analyse_output(char *path, t_pipex *pipex)
{
	if (pipex->here_doc)
		pipex->output_fd = open(path, O_CREAT | O_WRONLY | O_APPEND, 0000644);
	else
		pipex->output_fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	if (pipex->output_fd < 0)
		//error;
}