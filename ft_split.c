/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:46:30 by hyungdki          #+#    #+#             */
/*   Updated: 2022/11/28 10:46:31 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static int		do_split(char ***result1, char *temp, int len);
static int		do_remove(char ***result2, int result_idx, char *temp);
static char		*ft_strdup(char *src);
static char		*ft_strcpy(char *dst, const char *src);

char	**ft_split(char const *s, char c)
{
	char	*temp;
	char	**result;
	int		idx;
	int		count;

	temp = ft_strdup((char *)s);
	if (temp == 0)
		return (0);
	idx = -1;
	count = 0;
	while (temp[++idx] != '\0')
	{
		if (temp[idx] != c && (temp[idx + 1] == c || temp[idx + 1] == '\0'))
			count++;
		if (temp[idx] == c)
			temp[idx] = '\0';
	}
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (result == 0)
	{
		free(temp);
		return (0);
	}
	do_split(&result, temp, idx);
	return (result);
}

static int	do_split(char ***result1, char *temp, int len)
{
	int		idx;
	int		result_idx;

	idx = 0;
	result_idx = 0;
	if (temp[idx] != '\0')
	{
		(*result1)[result_idx] = ft_strdup(temp);
		if ((*result1)[result_idx] == 0)
			return (do_remove(result1, result_idx, temp));
		result_idx++;
	}
	while (++idx < len)
	{
		if (temp[idx] != '\0' && temp[idx - 1] == '\0')
		{
			(*result1)[result_idx] = ft_strdup(&temp[idx]);
			if ((*result1)[result_idx] == 0)
				return (do_remove(result1, result_idx, temp));
			result_idx++;
		}
	}
	(*result1)[result_idx] = 0;
	free(temp);
	return (0);
}

static int	do_remove(char ***result2, int result_idx, char *temp)
{
	int	index;

	index = 0;
	while (index < result_idx)
	{
		free((*result2)[index]);
		index++;
	}
	free(*result2);
	(*result2) = 0;
	free(temp);
	return (0);
}

static char	*ft_strdup(char *src)
{
	int		src_length;
	char	*replica;

	src_length = 0;
	while (src[src_length] != '\0')
	{
		src_length++;
	}
	replica = (char *)malloc(sizeof(char) * (src_length + 1));
	if (replica == 0)
		return (0);
	return (ft_strcpy(replica, src));
}

static char	*ft_strcpy(char *dst, const char *src)
{
	int		index;

	index = 0;
	while (src[index] != '\0')
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (dst);
}
