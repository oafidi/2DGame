/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oafidi <oafidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:23:30 by oafidi            #+#    #+#             */
/*   Updated: 2025/02/26 20:35:19 by oafidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*bloc;
	size_t	i;
	size_t	j;

	j = 0;
	i = (size_t)start;
	if (s == NULL)
		return (NULL);
	if (len == 0 || i >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	bloc = (char *)malloc(len + 1);
	if (bloc == NULL)
		return (NULL);
	while (s[i] && j < len)
	{
		bloc[j] = s[i];
		i++;
		j++;
	}
	bloc[j] = '\0';
	return (bloc);
}
