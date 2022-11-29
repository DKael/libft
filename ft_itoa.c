/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:05:31 by hyungdki          #+#    #+#             */
/*   Updated: 2022/11/28 12:05:32 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_itoa(int n);
char	*case_zero();
char	*case_pos(int n, int digit);
char	*case_neg(int n, int digit);

char	*ft_itoa(int n)
{
	int		digit;
	int		temp_n;

	temp_n = n;
	digit = 0;
	while (temp_n != 0)
	{
		digit++;
		temp_n /= 10;
	}
	if (n == 0)
		return (case_zero());
	else if (n > 0)
		return (case_pos(n, digit));
	else
		return (case_neg(n, digit));
}

char	*case_zero()
{
	char	*result;

	result = (char *)malloc(sizeof(char) * 2);
	if (result == 0)
		return (0);
	result[0] = '0';
	result[1] = '\0';
	return (result);
}

char	*case_pos(int n, int digit)
{
	char	*result;

	result = (char *)malloc(sizeof(char) * (digit + 1));
	if (result == 0)
		return (0);
	result[digit--] = '\0';
	while(n != 0)
	{
		result[digit--] = (n % 10) + '0';
		n /= 10;
	}
	return (result);
}

char	*case_neg(int n, int digit)
{
	char	*result;

	result = (char *)malloc(sizeof(char) * (digit + 2));
	if (result == 0)
		return (0);
	result[0] = '-';
	result[digit + 1] = '\0';
	while(n != 0)
	{
		result[digit--] = (-1) * (n % 10) + '0';
		n /= 10;
	}
	return (result);
}