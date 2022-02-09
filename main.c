/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <josuna-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:44:15 by josuna-t          #+#    #+#             */
/*   Updated: 2022/02/09 17:18:35 by josuna-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	freeall(t_pipe vars)
{
	int	index;

	index = 0;
	if (vars.cid1 < 0)
		perror("pipe");
	while (vars.parg[0][index] != 0)
		free(vars.parg[0][index++]);
	index = 0;
	while (vars.parg[1][index] != 0)
		free(vars.parg[1][index++]);
	free(vars.parg[0]);
	free(vars.parg[1]);
	close(vars.pipefd[0]);
	close(vars.pipefd[1]);
}

void	checkerror(char *parg, char **argv, int error)
{
	char	*errormsg;

	if (error == 127)
		errormsg = ft_strjoin(parg, ": No such file or directory");
	if (error == 126)
		errormsg = ft_strjoin(parg, ": permission denied");
	if (error == 1)
		errormsg = ft_strjoin(argv[1], ": No such file or directory");
	if (error == 2)
		errormsg = ft_strjoin(argv[4], ": No such file or directory");
	if (error > 0)
	{
		write(2, errormsg, ft_strlen(errormsg));
		write(2, "\n", 1);
		free(errormsg);
	}
}

int	checkfiles(t_pipe *vars, char **argv, char **env)
{
	int		fd;
	char	*tmpdir;

	vars->error = 0;
	vars->parg[0] = ft_split(argv[2], ' ');
	fd = open(argv[1], O_RDONLY, 0444);
	if (fd >= 0)
	{
		tmpdir = checkfile(&vars->parg[0][0], env[6]);
		if (access(tmpdir, 0111) == -1)
			vars->error = 126;
		if (tmpdir == 0)
			vars->error = 127;
		else
			free(tmpdir);
		checkerror(vars->parg[0][0], argv, vars->error);
		return (vars->error);
	}
	perror(argv[1]);
	vars->error = 1;
	return (vars->error);
}	

int	checkfiles2(t_pipe *vars, char **argv, char **env)
{
	int		fd;
	char	*tmpdir;

	vars->error = 0;
	vars->parg[1] = ft_split(argv[3], ' ');
	tmpdir = checkfile(&vars->parg[1][0], env[6]);
	if (access(tmpdir, 0111) == -1)
		vars->error = 126;
	if (tmpdir == 0)
		vars->error = 127;
	else
		free(tmpdir);
	fd = open(argv[4], O_RDWR | O_CREAT, 0666);
	if (vars->error > 0)
	{
		checkerror(vars->parg[1][0], argv, vars->error);
		return (vars->error);
	}
	if (fd < 0)
	{
		perror(argv[4]);
		vars->error = 1;
	}
	return (vars->error);
}	

int	main(int argc, char **argv, char **env)
{
	t_pipe	vars;

	if (argc == 5)
	{
		vars.cid1 = 1;
		if (pipe(vars.pipefd) == -1)
			perror("pipe");
		if (checkfiles(&vars, argv, env) == 0)
			vars.cid1 = fork();
		if (vars.cid1 == 0)
			vars.error = pipein(vars, argv[1], env[6]);
		else if (vars.cid1 > 0)
		{
			if (checkfiles2(&vars, argv, env) == 0)
				vars.cid1 = fork();
			if (vars.cid1 == 0)
				vars.error = pipeout(vars, argv[4], env[6]);
		}
		else
			perror("fork");
		freeall(vars);
		return (vars.error);
	}
	else
		write(2, "Numero de argumentos incorrecto.\n", 33);
}
