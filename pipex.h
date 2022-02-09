/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <josuna-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:52:11 by josuna-t          #+#    #+#             */
/*   Updated: 2022/02/09 17:19:51 by josuna-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include<unistd.h>
# include<stdio.h>
# include "./libft/libft.h"
# include <fcntl.h>
# include <errno.h>

typedef struct s_pipe
{
	int		cid1;
	char	**parg[2];
	int		pipefd[2];
	int		error;
}	t_pipe;

int		pipein(t_pipe vars, char *path, char *env);
int		pipeout(t_pipe vars, char *path, char *env);
char	*checkfile(char **parg, char *env);
void	freedimarray(char **array);
#endif