/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:19:29 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/12 19:34:24 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
   Integer constant with only the 32 bit slot off.
   Norm coding standard does not allow the cast here, but this only works if
   casted to an unsigned integer!
*/
#define _32TH_ZERO_BIT -33

/* Turn character interpretation of `c` into uppercase if it is alphabetical. */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c &= (unsigned char) _32TH_ZERO_BIT;
	return (c);
}
