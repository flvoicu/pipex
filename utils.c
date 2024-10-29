/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvoicu <flvoicu@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:41:33 by flvoicu           #+#    #+#             */
/*   Updated: 2024/04/08 19:51:06 by flvoicu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(char *s, int c)
{
	int		i;
	int		a;
	char	*b;

	b = (char *)s;
	i = 0;
	a = i;
	while (c >= 256)
		c -= 256;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			a = i;
		i++;
	}
	if (s[i] == c)
		a = i;
	return (a);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	char	*tmp;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	a = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (a == NULL)
		return (a);
	tmp = a;
	while (*s1)
	{
		*tmp = *s1;
		tmp++;
		s1++;
	}
	while (*s2)
	{
		*tmp = *s2;
		tmp++;
		s2++;
	}
	*tmp = '\0';
	return (a);
}

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (s1[a] != '\0' && s2[b] != '\0' && n > 0)
	{
		if (s1[a] != s2[b])
			return ((unsigned char)s1[a] - (unsigned char)s2[b]);
		a++;
		b++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)s1[a] - (unsigned char)s2[b]);
}
