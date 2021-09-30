/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrapefr <ggrapefr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 18:37:13 by ggrapefr          #+#    #+#             */
/*   Updated: 2021/09/30 18:49:34 by ggrapefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"

int	g_infile;
int	g_outfile;
int	g_pipe_fd[2];

/* Mandatory part */
void	error(void);
char	*find_path(char *cmd, char **envp);
void	execute(char *argv, char **envp);
/* Bonus part */
int		get_next_line(char **line);

#endif