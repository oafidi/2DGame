/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oafidi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:24:26 by oafidi            #+#    #+#             */
/*   Updated: 2025/02/12 21:24:28 by oafidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strdup(char *s1)
{
	char	*bloc;
	size_t	i;

	i = 0;
	bloc = (char *)malloc(ft_strlen(s1) + 1);
	if (bloc == NULL)
		return (NULL);
	while (s1[i])
	{
		bloc[i] = s1[i];
		i++;
	}
	bloc[i] = '\0';
	return (bloc);
}
