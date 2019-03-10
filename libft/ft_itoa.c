/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:16:22 by cmckelvy          #+#    #+#             */
/*   Updated: 2019/02/19 16:07:56 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*result;
	int		sign;
	int		len;

	sign = 1;
	if (n < 0)
		sign = 2;
	len = ft_digits(n) + (sign - 1);
	if (sign == 2)
		sign -= 3;
	if (!(result = (char*)ft_strnew(len + 1)))
		return (NULL);
	if (n == 0)
		result[0] = '0';
	len--;
	while (n)
	{
		result[len] = (n % 10) * sign + '0';
		n /= 10;
		len--;
	}
	if (sign == -1)
		result[len] = '-';
	return (result);
}
