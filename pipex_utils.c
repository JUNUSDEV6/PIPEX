/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:19:14 by yohanafi          #+#    #+#             */
/*   Updated: 2024/03/31 19:02:40 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *argv_in, char *argv_out, bool flag)
{
	int	rlt;

	if (flag)
		rlt = open(argv_in, O_RDONLY | 0777);
	else
		rlt = open(argv_out, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	return (rlt);
}