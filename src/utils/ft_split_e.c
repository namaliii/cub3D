/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_e.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:20:08 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/13 11:20:10 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Copy at most `n` bytes from `src` string to `dest` string. */
static char	*s_strncpy(char *dest, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		++i;
	}
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}

static void	free_all(char **strings, size_t word_count)
{
	size_t	i;

	i = 0;
	while (i < word_count + 1)
	{
		free(strings[i]);
	}
	free(strings);
}

/*
   Separates the initial string `init_str` from separator characters `seps`.
   Stores the resultant array of strings in `strings`.
   Returns 0 if successful, -1 if malloc allocation fails.
 */
static int
	split_separate(char **strings, char *init_str, char sep, size_t w_idx)
{
	size_t	w;
	size_t	i;

	i = 0;
	w = 0;
	w_idx = 0;
	while (1)
	{
		if (i > 0 && init_str[i - 1] == sep)
			w_idx = i;
		if (init_str[i] == sep || init_str[i] == '\0')
		{
			strings[w] = (char *) malloc(sizeof(char) * (i - w_idx + 1));
			if (strings[w] == NULL)
				return (-1);
			strings[w] = s_strncpy(strings[w], &(init_str[w_idx]), i - w_idx);
			strings[w][i - w_idx] = '\0';
			++w;
			if (init_str[i] == '\0')
				break ;
		}
		++i;
	}
	strings[w] = NULL;
	return (0);
}

/* 
   Split the string `str` from `separator` characters.
   Return the null-terminated array of separated strings.
   Return NULL upon any errors.
   Return NULL if `str` is NULL.

   _e version: ".14" will return strings of "" and "14" instead of just "14".
*/
char	**ft_split_e(char const *str, char separator)
{
	char	**strings;
	char	*p_str;
	size_t	word_count;
	size_t	i;

	if (str == NULL)
		return (NULL);
	p_str = (char *) str;
	word_count = 1;
	i = 0;
	while (str[i])
	{
		if (p_str[i] == separator)
			++word_count;
		++i;
	}
	strings = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (strings == NULL)
		return (NULL);
	if (split_separate(strings, p_str, separator, 0) == -1)
	{
		free_all(strings, word_count);
		return (NULL);
	}
	return (strings);
}
