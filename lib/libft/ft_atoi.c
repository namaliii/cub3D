/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:38:59 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/18 15:52:51 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	s_isspace3(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v'
		|| c == '\f');
}

/* Parse an integer from a string and return it. */
int	ft_atoi(const char *str)
{
	int				sign;
	int				result;
	unsigned int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (s_isspace3(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		++i;
	}
	else if (str[i] == '+')
		++i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0') % 10;
		i++;
	}
	return (result * sign);
}
