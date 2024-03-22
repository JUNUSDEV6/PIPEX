/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:58:00 by yohanafi          #+#    #+#             */
/*   Updated: 2024/03/22 12:30:16 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>


# define EM "ERROR INPUT\nTHE CORRECT INPUT:\n<./pipex files1 cmd1 cmd2 outfile>"

typedef struct	s_pipex
{
	int		pipe[2];
	char	**path;
	char	*cmd;
}				t_pipex;


char	**ft_split(char const *s, char c);
#endif