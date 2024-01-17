/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youneshanafi <youneshanafi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:59:09 by youneshanaf       #+#    #+#             */
/*   Updated: 2024/01/17 18:36:29 by youneshanaf      ###   ########.fr       */
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
	analyse_output(argv[argc - 1], &pipex);
	//4: analyse cmd;
	analyse_cmd(argc, argv, &pipex);
	
}