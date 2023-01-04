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

static char	**do_split(char const *s, char c, char **result);
static char	*ft_strndup(char const *src, int size);
static void	init_value(int *index, int *flag, int *count);

char	**ft_split(char const *s, char c)
{
	int		index;
	int		flag;
	int		split_count;
	char	**result;

	init_value(&index, &flag, &split_count);
	while (s[++index] != '\0')
	{
		if (s[index] != c)
		{
			flag = 1;
		}	
		else if (flag == 1)
		{
			split_count++;
				flag = 0;
		}
	}
	if (index != 0 && s[index - 1] != c)
		split_count++;
	result = (char **)malloc(sizeof(char *) * (split_count + 1));
	if (result == 0)
		return (0);
	return ((do_split(s, c, result)) - split_count);
}

static char	**do_split(char const *s, char c, char **result)
{
	int	index;
	int	flag;
	int	count;

	init_value(&index, &flag, &count);
	while (s[++index] != '\0')
	{
		if (s[index] != c)
		{
			flag = 1;
			count++;
		}
		else if (flag == 1)
		{
			*result++ = ft_strndup(&s[index - count], count);
			flag = 0;
			count = 0;
		}
	}
	if (index != 0 && s[index - 1] != c)
		*result++ = ft_strndup(&s[index - count], count);
	*result = 0;
	return (result);
}

static char	*ft_strndup(char const *src, int size)
{
	int		src_length;
	char	*replica;
	int		index;

	src_length = 0;
	while (src[src_length] != '\0')
	{
		src_length++;
	}
	if (src_length >= size)
		replica = (char *)malloc(sizeof(char) * (size + 1));
	else
		replica = (char *)malloc(sizeof(char) * (src_length + 1));
	if (replica == 0)
		return (0);
	index = 0;
	while (src[index] != '\0' && index < size)
	{
		replica[index] = src[index];
		index++;
	}
	replica[index] = '\0';
	return (replica);
}

static void	init_value(int *index, int *flag, int *count)
{
	*index = -1;
	*flag = 0;
	*count = 0;
}
