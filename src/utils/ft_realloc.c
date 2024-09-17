/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 00:05:11 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/17 00:05:22 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_realloc(void *ptr, size_t original_size, size_t new_size)
{
	void	*new_ptr;
	size_t	min_size;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (!ptr)
		return (new_ptr);
	min_size = original_size;
	if (new_size < original_size)
		min_size = new_size;
	if (min_size > 0)
		ft_memcpy(new_ptr, ptr, min_size);
	free(ptr);
	return (new_ptr);
}
