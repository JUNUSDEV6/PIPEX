/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youneshanafi <youneshanafi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:33:45 by youneshanaf       #+#    #+#             */
/*   Updated: 2024/01/17 17:47:53 by youneshanaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <fcntl.h>
# include <string.h>

typedef struct	s_pipex {

	int		input_fd;
	int		output_fd;
	int		nbr_cmd;
	int		is_error;
	int		here_doc;
	int		doc_fd;
	char	**env;
	t_list	*cmd_list;
}			t_pipex;

typedef struct	s_cmd {
	char	**arg_path;
	int		pipe[2];
	int		pid;
}			t_cmd;

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*previous;
}				t_list;

