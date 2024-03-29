/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohanafi <yohanafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:41:52 by yohanafi          #+#    #+#             */
/*   Updated: 2024/03/29 11:27:37 by yohanafi         ###   ########.fr       */
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
	if (bool == true)
		exit(EXIT_SUCCES);
	exit(EXIT_FAILURE);
}