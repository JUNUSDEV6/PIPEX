/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:41:52 by yohanafi          #+#    #+#             */
/*   Updated: 2024/04/02 12:22:08 by yohanafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_error(void)
{
	perror(EM);
	exit(EXIT_FAILURE);
}

void	exit_error(bool boolean)
{
	if (boolean == true)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}
