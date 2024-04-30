/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:13:40 by yohanafi          #+#    #+#             */
/*   Updated: 2024/04/30 10:50:29 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_HH
# define PIPEX_HH

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "get_next_line.h"

char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *find, const char *to_find, size_t len);
char	*ft_strjoin(char *s1, char *s2);
int		open_file(char *file, int in_out, char **argv, char **envp);
char	*get_path(char *cmd, char **envp);
int		ft_strncmp(const char *s1, char *s2, size_t n);
int		ft_strlen(char *str);
void	ft_putstr_fd(char *s, int fd);
char    *get_next_line(int fd);

#endif