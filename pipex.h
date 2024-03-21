/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:58:00 by yohanafi          #+#    #+#             */
/*   Updated: 2024/03/20 16:18:29 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <fcntl.h>

# define EM "ERROR INPUT\nTHE CORRECT INPUT:\n<./pipex files1 cmd1 cmd2 outfile>"

typedef struct	s_pipex
{
	int		fd1;
	int		fd2;
	char	*cmd;
}				t_pipex;

#endif