/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourti <ancourti@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:50:54 by ancourti          #+#    #+#             */
/*   Updated: 2026/01/16 03:51:46 by ancourti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
size_t				ft_strlen(const char *s);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *to, const void *from, size_t numBytes);
void				*ft_memmove(void *dest, const void *src, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
int					ft_toupper(int character);
int					ft_tolower(int character);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strdup(const char *s);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
int					ft_atoi(const char *str);
void				*ft_calloc(size_t n, size_t size);
char				*ft_strdup(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
int					ft_putchar_fd(char c, int fd);
int					ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
int					ft_putnbr_fd(int n, int fd);
int					ft_putnbr_u_fd(unsigned int n, int fd);
int					ft_putpointer(void *pointer, int fd);
int					ft_count_digits(unsigned long n, int base);

// @brief Bonus structure - Simple chained list.
// @param content The data contained in the node. `void *` allows you to
// store any type of data.
// @param next The address of the next node,
// or `NULL` if the current node is the last one.
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// @brief Allocates memory (using `malloc()`) and returns
// a new node.
//
// - The `content` member variable is
// initialized with the given parameter `content`.
//
// - The variable `next` is initialized to `NULL`.
// @param content The content to store in the new node.
// @return A pointer to the new node.
// @warning Subject does not specify the need to protect
// if `malloc()` fails !
t_list				*ft_lstnew(void *content);

// @brief Adds the node `new` at the beginning of the list.
// @param lst The address of a pointer to the first node of a list.
// @param new The address of a pointer to the node to be added.
// @return None.
void				ft_lstadd_front(t_list **lst, t_list *new);

// @brief Counts the number of nodes in the list.
// @param lst The beginning of the list.
// @return The length of the list.
int					ft_lstsize(t_list *lst);

// @brief Returns the last node of the list.
// @param lst The beginning of the list.
// @return Last node of the list.
t_list				*ft_lstlast(t_list *lst);

// @brief Adds the node `new` at the end of the list.
// @param lst The address of a pointer to the first node of a list.
// @param new The address of a pointer to the node to be added.
void				ft_lstadd_back(t_list **lst, t_list *new);

// @brief Takes a node as parameter and frees its content
// using the function `del`. Free the node itself but
// does NOT free the next node.
// @param lst The node to free.
// @param del The address of the function used to delete the content.
void				ft_lstdelone(t_list *lst, void (*del)(void *));

// @brief Deletes and frees the given node and all its successors,
// using the function `del` and `free()`.
// Finally, set the pointer to the list to `NULL`.
//
// Source code explaination :
//
// 1. Loop over the list.
//
// 2. Set `temp` to point to the next element of the list.
//
// 3. Use `ft_lstdelone()` on the current element.
//
// 4. Set the list pointer equal to `temp`, so that we have a
// pointer to the next element.
//
// 5. Finally, `free()` the list pointer and set it to `NULL`.
// @param lst The address of a pointer to a node.
// @param del The address of the function used to
// delete the content of the node.
void				ft_lstclear(t_list **lst, void (*del)(void *));

// @brief Iterates through the list `lst` and applies the
// function `f` to the content of each node.
// @param lst The address of a pointer to a node.
// @param f The address of the function to apply to each
// node’s content.
void				ft_lstiter(t_list *lst, void (*f)(void *));

// @brief This function works similarly as the `ft_lstiter()` function,
// but it creates a completely new list.
//
// `ft_lstmap()` iterates through the list `lst`, applies the
// function `f()` to each node’s content, and creates
// a new list resulting of the successive applications
// of the function `f()`.
//
// External functions : `malloc()`, `free()`.
//
// Principle :
//
// 1. Create a new list and initialize its content as `f()`
// of source's list content.
//
// 2. Go one element deeper in the source list.
//
// 3. Repeat until the end, add each new element to the back of the
// new list.
//
// 4. Check that the new list has the same number of elements
// as the source list :
//
// 5. If something is missing, a `malloc()` must have failed.
// In that case, `ft_lstclear()` function will be used with the
// `del()` function as parameter to clear everything from the first element.
// The new list will also be freed with `free()`,
// and its pointer set to `NULL`.
//
// 6. Else, return the new list's pointer.
//
// @param lst The address of a pointer to a node.
// @param f The address of the function applied to each node’s content.
// @param del The address of the function used to delete a
// node’s content if needed.
// @return (Pointer to the new list); or `NULL` if any allocation fails.
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

#endif
