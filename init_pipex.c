/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youneshanafi <youneshanafi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:34:26 by youneshanaf       #+#    #+#             */
/*   Updated: 2024/01/13 13:45:47 by youneshanaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

init_pipex(int argc, char **argv, char **env, t_pipex *pipex)
{
	pipex->input_fd = 0;
	pipex->output_fd = 0;
	pipex->nbr_cmd = 0;
	pipex->is_error = 0;
	pipex->here_doc = 0;
	pipex->cmd_list = NULL;
}