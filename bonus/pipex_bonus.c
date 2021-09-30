/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrapefr <ggrapefr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 18:37:47 by ggrapefr          #+#    #+#             */
/*   Updated: 2021/09/30 19:14:42 by ggrapefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	here_doc(char *limiter)
{
	pid_t	pid1;
	char	*line;

	if (pipe(g_pipe_fd) < 0)
		error();
	pid1 = fork();
	if (pid1 == 0)
	{
		close(g_pipe_fd[0]);
		while (get_next_line(&line))
		{
			if (!ft_strncmp(line, limiter, ft_strlen(line))
				&& ft_strncmp(line, "", 1))
				exit(EXIT_SUCCESS);
			write(g_pipe_fd[1], line, ft_strlen(line));
			write(g_pipe_fd[1], "\n", 1);
			free(line);
		}
	}
	else
	{
		close(g_pipe_fd[1]);
		dup2(g_pipe_fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

int	which_case(int argc, char **argv)
{
	int		i;

	if (ft_strlen(argv[1]) == 8 && !ft_strncmp(argv[1], "here_doc", 8))
	{
		i = 3;
		g_outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
		if (g_outfile < 0 || argc < 6)
			error();
		here_doc(argv[2]);
	}
	else
	{
		i = 2;
		g_infile = open(argv[1], O_RDONLY, 0777);
		g_outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC,
				S_IWRITE | S_IREAD, 0777);
		if (g_outfile < 0 || g_infile < 0)
			error();
		dup2(g_infile, STDIN_FILENO);
	}
	return (i);
}

void	child_process(char *argv, char **envp)
{
	int	g_pipe_fd[2];
	int	pid1;

	if (pipe(g_pipe_fd) == -1)
		error();
	pid1 = fork();
	if (pid1 == -1)
		error();
	if (pid1 == 0)
	{
		close(g_pipe_fd[0]);
		dup2(g_pipe_fd[1], STDOUT_FILENO);
		execute(argv, envp);
	}
	else
	{
		close(g_pipe_fd[1]);
		dup2(g_pipe_fd[0], STDIN_FILENO);
		waitpid(pid1, NULL, 0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		i;

	if (argc >= 5)
	{
		i = which_case(argc, argv);
		while (i < argc - 2)
			child_process(argv[i++], envp);
		dup2(g_outfile, STDOUT_FILENO);
		execute(argv[argc - 2], envp);
		close(g_infile);
		close(g_outfile);
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_putstr_fd("Error: Wrong number of arguments\n", 2);
		exit(EXIT_FAILURE);
	}
}
