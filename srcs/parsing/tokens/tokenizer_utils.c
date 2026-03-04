/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandreo <aandreo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 07:08:47 by aandreo           #+#    #+#             */
/*   Updated: 2026/03/03 07:20:18 by aandreo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// needed -> skip spaces before tokens
int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*dest;
	size_t	i;

	len = 0;
	while (src[len])
		len++;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*newstring;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		newstring = malloc(sizeof(char));
		if (!newstring)
			return (NULL);
		newstring[0] = '\0';
		return (newstring);
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	newstring = malloc((len + 1) * sizeof(char));
	if (!newstring)
		return (NULL);
	while (s[start] && i < len)
		newstring[i++] = s[start++];
	newstring[i] = '\0';
	return (newstring);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
