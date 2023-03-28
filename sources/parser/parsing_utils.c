/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:02:11 by yelaissa          #+#    #+#             */
/*   Updated: 2023/03/28 11:41:32 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*trim_single_quotes(char *input)
{
	char	*result;
	int		i;
	int		j;

	result = malloc(strlen(input));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (input[i])
	{
		if (input[i] == 39 && (i == 0 || input[i - 1] != '\\'))
			i++;
		else
			result[j++] = input[i++];
	}
	result[j] = '\0';
	return (result);
}

char	*trim_double_quotes(char *input)
{
	char	*result;
	int		i;
	int		j;

	result = malloc(strlen(input));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (input[i])
	{
		if (input[i] == '"' && (i == 0 || input[i - 1] != '\\'))
			i++;
		else
			result[j++] = input[i++];
	}
	result[j] = '\0';
	return (result);
}
