/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:07:34 by hyungdki          #+#    #+#             */
/*   Updated: 2022/11/23 18:07:35 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stddef.h>

static size_t	ft_strlen(const char *s);

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_size;
	int		s2_size;
	int		index;
	char	*result;

	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (s1_size + s2_size + 1));
	if (result == 0)
		return (0);
	index = -1;
	while (++index < s1_size)
		result[index] = s1[index];
	index = -1;
	while (++index < s2_size)
		result[s1_size + index] = s2[index];
	result[s1_size + index] = '\0';
	return (result);
}

static size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index] != '\0')
	{
		index++;
	}
	return (index);
}
