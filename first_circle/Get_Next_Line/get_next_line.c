/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habe <habe@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:19:31 by habe              #+#    #+#             */
/*   Updated: 2025/06/17 15:08:19 by habe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoin_and_free(char *str1, char *str2)
{
	char			*result;
	unsigned int	str1_len;
	unsigned int	str2_len;

	if (str2 == NULL)
		return (str1);
	if (str1 == NULL)
		str1_len = 0;
	else
		str1_len = ft_strlen(str1);
	str2_len = ft_strlen(str2);
	result = malloc(str1_len + str2_len + 1);
	if (result == NULL)
		return (NULL);
	result[0] = '\0';
	ft_strcpy(result, str1);
	ft_strcat(result, str2);
	free(str1);
	return (result);
}

static char	*extract_line(char *str)
{
	char	*result;
	size_t	i;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	result = malloc(i + 1);
	if (result == NULL)
		return (NULL);
	result[i] = '\0';
	while (i-- > 0)
		result[i] = str[i];
	return (result);
}

static char	*update_remainder(char *str)
{
	char	*result;
	size_t	i;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	result = malloc(ft_strlen(&str[i]) + 1);
	if (result == NULL)
		return (NULL);
	ft_strcpy(result, &str[i]);
	free(str);
	return (result);
}

static char	*handle_read_and_check(int fd, char *buf, char *remainder)
{
	ssize_t	bytes_read;

	while (ft_strchr(remainder, '\n') == NULL)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buf);
			free(remainder);
			remainder = NULL;
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buf[bytes_read] = '\0';
		remainder = ft_strjoin_and_free(remainder, buf);
	}
	free(buf);
	if (remainder == NULL || *remainder == '\0')
	{
		free(remainder);
		remainder = NULL;
		return (NULL);
	}
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	remainder = handle_read_and_check(fd, buf, remainder);
	if (remainder == NULL)
		return (NULL);
	line = extract_line(remainder);
	if (line == NULL)
	{
		free(remainder);
		remainder = NULL;
		return (NULL);
	}
	remainder = update_remainder(remainder);
	return (line);
}

//functions [ read, malloc, free ]
