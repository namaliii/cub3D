/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:14:23 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/12 19:31:58 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Integer constant with only the 32 bit slot on. */
#define _32TH_ONE_BIT 32

/* Turn character interpretation of `c` into lowercase if it is alphabetical. */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c |= _32TH_ONE_BIT;
	return (c);
}
