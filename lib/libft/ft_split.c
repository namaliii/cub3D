/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:58:51 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/19 15:45:42 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define SUCCESS 0
#define FAILURE -1

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
static int	split_separate(char **strings, char *init_str, char sep)
{
	size_t	w;
	size_t	i;
	size_t	wlen;

	i = 0;
	w = 0;
	while (init_str[i])
	{
		if (init_str[i] != sep)
		{
			wlen = 0;
			while (init_str[i + wlen] != '\0' && init_str[i + wlen] != sep)
				++wlen;
			strings[w] = (char *) malloc(sizeof(**strings) * (wlen + 1));
			if (strings[w] == NULL)
				return (FAILURE);
			strings[w] = s_strncpy(strings[w], &(init_str[i]), wlen);
			strings[w++][wlen] = '\0';
			i += wlen;
		}
		if (init_str[i] != '\0')
			++i;
	}
	strings[w] = NULL;
	return (SUCCESS);
}

/* 
   Current character is not a separator, we are currently in a word.
   And next character is either a separator or at the end of the string.
*/
static int	is_end_of_a_word(char *s, size_t i, char separator)
{
	return (s[i] != separator && (s[i + 1] == '\0' || s[i + 1] == separator));
}

/* 
   Split the string `str` from characters encountered in `charset`.
   Return the null-terminated array of separated strings.
   Return NULL upon any errors.
   Return NULL if `str` is NULL.
*/
char	**ft_split(char const *str, char separator)
{
	char	**strings;
	char	*p_str;
	size_t	word_count;
	size_t	i;

	if (str == NULL)
		return (NULL);
	p_str = (char *) str;
	word_count = 0;
	i = 0;
	while (str[i])
	{
		if (is_end_of_a_word(p_str, i, separator))
			++word_count;
		++i;
	}
	strings = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (strings == NULL)
		return (NULL);
	if (split_separate(strings, p_str, separator) == FAILURE)
	{
		free_all(strings, word_count);
		return (NULL);
	}
	return (strings);
}
