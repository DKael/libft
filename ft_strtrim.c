/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:38:14 by hyungdki          #+#    #+#             */
/*   Updated: 2022/11/23 19:38:15 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char			*ft_strtrim(char const *s1, char const *set);
static char		*do_trim(char const *s1, char const *set, char *result);
static int		ft_strlen_trim(char const *str);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		index_s1;
	int		index_set;
	int		rm_count;
	char	*result;

	index_set = -1;
	rm_count = 0;
	while (set[++index_set] != '\0')
	{
		index_s1 = -1;
		while (s1[++index_s1] != '\0')
		{
			if (s1[index_s1] == set[index_set])
				rm_count++;
		}
	}
	result = (char *)malloc(sizeof(char) * (ft_strlen_trim(s1) - rm_count + 1));
	if (result == 0)
		return (0);
	return (do_trim(s1, set, result));
}

static char	*do_trim(char const *s1, char const *set, char *result)
{
	int		index_s1;
	int		index_set;
	int		index_r;
	int		flag;

	index_r = 0;
	index_s1 = -1;
	while (s1[++index_s1] != '\0')
	{
		flag = 1;
		index_set = -1;
		while (set[++index_set] != '\0')
		{
			if (s1[index_s1] == set[index_set])
			{
				flag = 0;
				break ;
			}
		}
		if (flag == 1)
			result[index_r++] = s1[index_s1];
	}
	result[index_r] = '\0';
	return (result);
}

static int	ft_strlen_trim(char const *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}
