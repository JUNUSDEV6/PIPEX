/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youneshanafi <youneshanafi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:37:54 by youneshanaf       #+#    #+#             */
/*   Updated: 2024/01/15 14:13:38 by youneshanaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	analyse_input(char *path, t_pipex *pipex)
{
	if (pipex->here_doc == 0)
	{
		pipex->input_fd = open(path, O_RDONLY);
		if (pipex->input_fd < 0)
		{
			//protection
		}
	}
}