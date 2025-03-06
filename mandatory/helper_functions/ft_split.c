/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oafidi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:24:48 by oafidi            #+#    #+#             */
/*   Updated: 2025/02/12 21:24:51 by oafidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_split(char **p, int n_words)
{
	int	i;

	i = 0;
	if (!p || !(*p))
		return ;
	if (n_words == -1)
	{
		while (p[i])
		{
			free(p[i]);
			i++;
		}
	}
	else
	{
		while (i < n_words)
		{
			free(p[i]);
			i++;
		}
	}
	free(p);
	p = NULL;
}

static int	count_words(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static int	fill(char **p, char *s, char c)
{
	char	*temp;
	int		i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		temp = s;
		while (*temp != c && *temp != '\0')
			temp++;
		if (temp > s)
		{
			p[i] = ft_substr(s, 0, temp - s);
			if (p[i] == NULL)
			{
				free_split(p, i);
				return (1);
			}
			s = temp;
			i++;
		}
	}
	p[i] = NULL;
	return (0);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		count;
	char	**new;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	new = (char **)malloc(sizeof(char *) * (count + 1));
	if (!new)
		return (NULL);
	i = fill(new, s, c);
	if (i == 1)
		return (NULL);
	return (new);
}
