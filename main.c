/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvoicu <flvoicu@student.42madrid.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:56:05 by flvoicu           #+#    #+#             */
/*   Updated: 2024/04/08 19:22:27 by flvoicu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[], char **env)
{
	t_pipe	pp;
	int		status;

	if (ac == 1)
		return (0);
	if (pipe(pp.fd[1]) == -1)
	{
		perror("Pipe creation failed");
		exit (1);
	}
	pp.pid = malloc((ac - 1) * sizeof(pid_t));
	status = manage_args(pp, av, ac, env);
	free(pp.pid);
	exit (WEXITSTATUS(status));
}
