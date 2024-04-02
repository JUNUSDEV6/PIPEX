/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:58:00 by yohanafi          #+#    #+#             */
/*   Updated: 2024/04/02 12:31:15 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

# define EM "ERROR\nTHE CORRECT INPUT:\n<./pipex files1 cmd1 cmd2 outfile>"

/*****  PIPEX_UTILS  *****/
int		open_file(char *argv_in, char *argv_out, bool flag);
char	*ft_free_tab(char **tabs);
char	*get_path(char *cmd, char **env, int i);

/*****  STR_UTILS  *****/
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *find, const char *to_find, size_t len);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);

/*****  ERROR  *****/
void	cmd_error(void);
void	exit_error(bool boolean);

#endif