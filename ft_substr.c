/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:25:48 by hyungdki          #+#    #+#             */
/*   Updated: 2022/11/23 15:25:50 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdlib.h>

static size_t	ft_strlen(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	idx;
	size_t	s_len;

	s_len = ft_strlen(s);
	if ((size_t)start < s_len && (size_t)start + len > s_len)
		result = (char *)malloc(sizeof(char) * (s_len - (size_t)start + 1));
	else if ((size_t)start < s_len && (size_t)start + len <= s_len)
		result = (char *)malloc(sizeof(char) * (len + 1));
	else
		result = (char *)malloc(sizeof(char) * 1);
	if (result == 0)
		return (0);
	idx = 0;
	if (s_len > (size_t)start)
	{
		while (idx < len && s[(size_t)start + idx] != '\0')
		{
			result[idx] = s[(size_t)start + idx];
			idx++;
		}
	}	
	result[idx] = '\0';
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
