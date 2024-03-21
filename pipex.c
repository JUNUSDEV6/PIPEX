/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:58:06 by yohanafi          #+#    #+#             */
/*   Updated: 2024/03/20 16:22:04 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char *env)
{
	t_pipex	*pipe;
	
	if ( 0 > open(argv[1], O_RDONLY) || 0 > open(argv[4]))
		return (-1);
	pipe->fd1 = open(argv[1], O_RDONLY);
	pipe->fd2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC)

	if (argc == 5)
	{
		init_pipex()
	}
	else
		perror(EM);
	return (0);
}