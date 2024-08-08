/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:14:08 by tunsal            #+#    #+#             */
/*   Updated: 2023/10/14 18:06:12 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t elems_count, size_t elem_size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int nb);
void	*ft_memchr(const void *ptr, int value, size_t search_lim);
int		ft_memcmp(const void *s1, const void *s2, size_t cmp_lim);
void	*ft_memcpy(void	*dest, const void	*src,	size_t n);
void	*ft_memmove(void	*dest, const void	*src, size_t n);
void	*ft_memset(void *str, int val, size_t replace_lim);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *str, char separator);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *src);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dest, char *src, size_t dstsize);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(char *s1, char *s2, size_t cmp_lim);
char	*ft_strnstr(const char *haystack, const char *needle, size_t searchlim);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s, char *set);
char	*ft_substr(char const *s, unsigned int sub_start, size_t sub_len);
int		ft_tolower(int c);
int		ft_toupper(int c);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	ft_lstadd_back(t_list **head, t_list *new);
void	ft_lstadd_front(t_list **head, t_list *new_node);
void	ft_lstclear(t_list **head, void (*del_content)(void *));
void	ft_lstdelone(t_list *node, void (*del_content)(void *));
void	ft_lstiter(t_list *head, void (*f)(void *));
t_list	*ft_lstlast(t_list *head);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *head);

#endif