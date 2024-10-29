/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvoicu <flvoicu@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:33:14 by flvoicu           #+#    #+#             */
/*   Updated: 2024/05/29 18:46:50 by flvoicu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	manage_end(char **c, char *f, t_pipe pp, char **env)
{
	int		file;
	char	*path;

	path = check_path(&c[0], env);
	file = open(f, O_WRONLY | O_CREAT | O_TRUNC,
			S_IRWXU | S_IRWXG | S_IRWXO);
	if (file == -1)
	{
		perror(ft_strjoin("Error opening file ", f));
		exit (1);
	}
	close (pp.fd[0][1]);
	dup2(file, STDOUT_FILENO);
	dup2(pp.fd[0][0], STDIN_FILENO);
	close (pp.fd[0][0]);
	close(pp.fd[1][0]);
	close(pp.fd[1][1]);
	execve(path, c, env);
	write(2, "Error, command not foud: Invalid argument\n", 42);
	exit(127);
}

static void	manage_st(char **c, char *f, t_pipe pp, char **env)
{
	int		file;
	char	*path;

	path = check_path(&c[0], env);
	file = open(f, O_RDONLY);
	if (file == -1)
	{
		perror(ft_strjoin("Error opening file ", f));
		exit (1);
	}
	close (pp.fd[1][0]);
	dup2(file, STDIN_FILENO);
	dup2(pp.fd[1][1], STDOUT_FILENO);
	close (pp.fd[1][1]);
	execve(path, c, env);
	write(2, "Error, command not foud: Invalid argument\n", 42);
	exit(127);
}

static void	manage_com(char **c, t_pipe pp, char **env)
{
	char	*path;

	path = check_path(&c[0], env);
	dup2(pp.fd[0][0], STDIN_FILENO);
	dup2(pp.fd[1][1], STDOUT_FILENO);
	close(pp.fd[0][0]);
	close(pp.fd[0][1]);
	close(pp.fd[1][0]);
	close(pp.fd[1][1]);
	execve(path, c, env);
	write(2, "Error, command not foud: Invalid argument\n", 42);
	exit(127);
}

static void	manage_pipe(t_pipe *pp, int i)
{
	if (i != 2)
	{
		close(pp->fd[0][0]);
		close(pp->fd[0][1]);
	}
	pp->fd[0][0] = pp->fd[1][0];
	pp->fd[0][1] = pp->fd[1][1];
	if (pipe(pp->fd[1]) == -1)
	{
		perror("Pipe creation failed");
		exit (1);
	}
}

int	manage_args(t_pipe pp, char **av, int ac, char **env)
{
	int		status;
	int		i;

	i = 2;
	while (i < ac - 1)
	{
		pp.pid[i] = fork();
		if (pp.pid[i] == 0)
		{
			if (i == 2)
				manage_st(ft_split(av[i], ' '), av[i - 1], pp, env);
			else if (i == ac - 2)
				manage_end(ft_split(av[i], ' '), av[i + 1], pp, env);
			else
				manage_com(ft_split(av[i], ' '), pp, env); 
		}
		manage_pipe(&pp, i++);
	}
	close(pp.fd[1][0]);
	close(pp.fd[1][1]);
	i = 2;
	while (i < ac - 1)
		waitpid(pp.pid[i++], &status, 0);
	return (status);
}
