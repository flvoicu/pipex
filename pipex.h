/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvoicu <flvoicu@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:03:28 by flvoicu           #+#    #+#             */
/*   Updated: 2024/04/09 17:49:43 by flvoicu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_pipe
{
	int			fd[2][2];
	pid_t		*pid;
}				t_pipe;

int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strchr(char *s, int c);
int		manage_args(t_pipe pp, char **av, int ac, char **env);
int		main(int ac, char *av[], char **env);
char	**ft_split(char const *s, char c);
char	*check_path(char **name, char **env);
size_t	ft_strlen(const char *s);

#endif
