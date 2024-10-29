/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvoicu <flvoicu@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:34:04 by flvoicu           #+#    #+#             */
/*   Updated: 2024/05/29 18:07:39 by flvoicu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**get_path(char **env)
{
	int		i;
	int		r;
	char	**paths;

	i = 0;
	if (!env)
		return (0);
	paths = 0;
	while (env[i] != NULL && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	if (env[i] != NULL)
		paths = ft_split(env[i] + 5, ':');
	return (paths);
}

static char	*find_path(char *name, char **paths)
{
	int		i;
	char	*slash;
	char	*tmp;
	char	*path;

	i = 0;
	if (!paths)
		return (name);
	path = 0;
	while (paths[i] != NULL)
	{
		slash = ft_strjoin(paths[i], "/");
		tmp = ft_strjoin(slash, name);
		free(slash);
		if (access(tmp, X_OK) == 0)
			path = tmp;
		else
		{
			free (paths[i]);
			free (tmp);
		}
		i++;
	}
	free (paths);
	return (path);
}

char	*check_path(char **name, char **env)
{
	char	*path;
	char	*tmp;
	int		cnt;

	tmp = *name;
	cnt = ft_strchr(*name, '/');
	if (cnt)
	{
		path = tmp;
		*name = *name + cnt + 1;
	}
	else
		path = find_path(*name, get_path(env));
	return (path);
}
