/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:10:08 by hyungdki          #+#    #+#             */
/*   Updated: 2022/11/28 16:10:09 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len_s;
	unsigned int	index;
	char			*result;

	len_s = 0;
	while (s[len_s] != '\0')
		len_s++;
	result = (char *)malloc(sizeof(char) * (len_s + 1));
	if (result == 0)
		return (0);
	index = -1;
	while (s[++index] != '\0')
		result[index] = f(index, s[index]);
	result[index] = '\0';
	return (result);
}