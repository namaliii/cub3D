/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:27:22 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/16 19:27:57 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*safe_calloc(size_t elems_count, size_t elem_size)
{
	void	*result;

	result = ft_calloc(elems_count, elem_size);
	if (result == NULL)
		exit_error(ERR_MSG_ALLOC);
	return (result);
}
