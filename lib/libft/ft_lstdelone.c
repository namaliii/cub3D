/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:06:35 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/14 16:16:37 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
   Delete only the CONTENT of `node` using `del_content` function. 
   Free the memory of deleted CONTENT of `node`.
*/
void	ft_lstdelone(t_list *node, void (*del_content)(void *))
{
	del_content(node->content);
	free(node);
}
