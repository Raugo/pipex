/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <josuna-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:46:53 by josuna-t          #+#    #+#             */
/*   Updated: 2022/02/09 16:54:03 by josuna-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	freedimarray(char **array)
{
	int	index;

	index = 0;
	while (array[index] != 0)
		free(array[index++]);
	free(array);
}

char	*checkfile(char **parg, char *env)
{
	char		*tmpdir[2];
	int			index;
	int			fd;
	char		**pdirs;

	pdirs = ft_split(&env[5], ':');
	index = 0;
	tmpdir[1] = ft_strjoin(parg[0], "");
	fd = access(tmpdir[1], F_OK);
	while (pdirs[index] != 0 && fd < 0)
	{
		free(tmpdir[1]);
		tmpdir[0] = ft_strjoin(pdirs[index++], "/");
		tmpdir[1] = ft_strjoin(tmpdir[0], parg[0]);
		free(tmpdir[0]);
		fd = access(tmpdir[1], F_OK);
	}
	index = 0;
	freedimarray(pdirs);
	if (fd >= 0)
		return (tmpdir[1]);
	else
		free(tmpdir[1]);
	return (0);
}

int	pipein(t_pipe vars, char *path, char *env)
{
	int		fd;
	char	*tmpdir;

	fd = open(path, O_RDONLY, 0444);
	if (fd < 0)
	{
		printf("Error: %d\n", errno);
		perror("open");
		return (0);
	}
	dup2(fd, 0);
	close (fd);
	tmpdir = checkfile(vars.parg[0], env);
	if (tmpdir == 0)
		return (1);
	if (access(tmpdir, 0111) == -1)
		return (2);
	close(vars.pipefd[0]);
	dup2(vars.pipefd[1], 1);
	close(vars.pipefd[1]);
	execve(tmpdir, vars.parg[0], NULL);
	return (0);
}

int	pipeout(t_pipe vars, char *path, char *env)
{
	int		fd;
	char	*tmpdir;

	wait(0);
	fd = open(path, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd < 0)
	{
		perror(path);
		return (0);
	}
	tmpdir = checkfile(vars.parg[1], env);
	close(vars.pipefd[1]);
	dup2(vars.pipefd[0], 0);
	dup2(fd, 1);
	close(fd);
	execve(tmpdir, vars.parg[1], NULL);
	return (0);
}
