/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:32:42 by hyungdki          #+#    #+#             */
/*   Updated: 2022/11/21 16:32:44 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdlib.h>

char			*ft_strdup(char *src);
static size_t	ft_strlen(const char *s);
static char		*ft_strcpy(char *restrict dst, const char *restrict src);

char	*ft_strdup(char *src)
{
	size_t	src_length;
	char	*replica;

	src_length = ft_strlen(src);
	replica = (char *)malloc(sizeof(char) * (src_length + 1));
	if (replica == 0)
		return (0);
	ft_strcpy(replica, src);
	return (replica);
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

static char	*ft_strcpy(char *restrict dst, const char *restrict src)
{
	size_t	index;

	index = 0;
	while (src[index] != '\0')
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (dst);
}
