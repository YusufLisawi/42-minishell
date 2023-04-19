/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:35:29 by htalhaou          #+#    #+#             */
/*   Updated: 2023/04/18 18:43:39 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redirect_output(char *file)
{
	int	fd;

	fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd < 0)
	{
		check_file(file);
		return (-1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

int	redirect_input(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		check_file(file);
		return (-1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

int	check_file(char *file)
{
	if (access(file, F_OK) == -1)
	{
		console(1, file, ": No such file or directory");
		return (1);
	}
	else if (access(file, R_OK) == -1)
	{
		console(1, file, ": Permission denied");
		return (1);
	}
	else if (access(file, X_OK) == 0)
	{
		console(1, file, ": Is a directory");
		return (1);
	}
	return (0);
}

int	append(char *file)
{
	int fd;

	fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd < 0)
	{
		check_file(file);
		return (-1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

int	handle_redirection(t_rd *rd)
{
	while (rd)
	{
		if (rd->type == RD_OUT)
		{
			if (redirect_output(rd->file))
				return (1);
		}
		else if (rd->type == RD_IN)
		{
			if (redirect_input(rd->file))
				return (1);
		}
		else if (rd->type == RD_AOUT)
		{
			if (append(rd->file))
				return (1);
		}
		rd = rd->next;
	}
	return (0);
}