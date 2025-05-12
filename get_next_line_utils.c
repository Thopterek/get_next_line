/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 08:27:06 by ndziadzi          #+#    #+#             */
/*   Updated: 2024/10/23 14:52:42 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	cc;
	size_t	loop_c;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		sub = malloc(1 * sizeof(char));
		if (sub == NULL)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	cc = ft_strlen(s) - (start);
	if (cc > len)
		cc = len;
	loop_c = 0;
	sub = malloc((cc + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	while (s[start] != '\0' && loop_c < len)
		sub[loop_c++] = s[start++];
	sub[loop_c] = '\0';
	return (sub);
}

size_t	ft_strlen(const char	*s)
{
	size_t	n;

	n = 0;
	while (s[n] != '\0')
		n++;
	return (n);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	char	*first;
	char	*sec;
	size_t	cc;

	first = (char *)s1;
	sec = (char *)s2;
	cc = ft_strlen(first) + ft_strlen(sec);
	new = malloc((cc + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, first, ft_strlen(first) + 1);
	ft_strlcat(new, sec, cc + 1);
	return (new);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	cc;

	cc = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (cc < dstsize - 1 && src[cc] != '\0')
	{
		dst[cc] = src[cc];
		cc++;
	}
	if (dstsize != 0)
		dst[cc] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	cc;
	size_t	dl;
	size_t	slen;

	cc = 0;
	dl = ft_strlen(dst);
	slen = ft_strlen(src);
	if (dstsize == 0)
		return (slen);
	if (dstsize <= dl)
		return (dstsize + slen);
	while ((cc < dstsize - dl - 1) && src[cc] != '\0')
	{
		dst[dl + cc] = src[cc];
		cc++;
	}
	dst[dl + cc] = '\0';
	return (dl + slen);
}
