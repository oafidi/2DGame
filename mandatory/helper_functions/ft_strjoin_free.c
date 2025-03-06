/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oafidi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:24:10 by oafidi            #+#    #+#             */
/*   Updated: 2025/02/12 21:24:13 by oafidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*s3;
	char	*s3_start;
	char	*s1_start;
	char	*s2_start;

	if (!s1 && s2)
		return (s2);
	s3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (free(s1), free(s2), NULL);
	s3_start = s3;
	s2_start = s2;
	s1_start = s1;
	while (*s1)
		*(s3++) = *(s1++);
	while (*s2)
		*(s3++) = *(s2++);
	*s3 = '\0';
	return (free(s1_start), free(s2_start), s3_start);
}
