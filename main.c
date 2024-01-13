/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youneshanafi <youneshanafi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:59:09 by youneshanaf       #+#    #+#             */
/*   Updated: 2024/01/13 13:47:32 by youneshanaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, *argv, char **env)
{
	t_pipex	pipex;


	//1: initialise la struc du pipex;
	init_pipex(argc, argv, env, &pipex);
	//2: analyse l'imput;
	analyse_input(argv[1], &pipex);
	//3: analyse output;
	//4: analyse cmd;
}