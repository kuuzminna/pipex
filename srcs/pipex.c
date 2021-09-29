#include "../includes/pipex.h"

void	child_process(char **argv, char **envp, int *pipe_fd)
{
	int		infile;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
		error();
	dup2(pipe_fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(pipe_fd[0]);
	execute(argv[2], envp);
}

void	parent_process(char **argv, char **envp, int *pipe_fd)
{
	int		outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		error();
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(pipe_fd[1]);
	execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int	pipe_fd[2];
	int	pid1;

	if (argc == 5)
	{
		if (pipe(pipe_fd) == -1)
			error();
		pid1 = fork();
		if (pid1 == -1)
			error();
		if (pid1 == 0)
			child_process(argv, envp, pipe_fd);
		else
		{
			parent_process(argv, envp, pipe_fd);
		}
		close(pipe_fd[1]);
		close(pipe_fd[0]);
		waitpid(pid1, NULL, 0);
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_putstr_fd("\033[1:31mError: Bad arguments\n\e[0m", 2);
		ft_putstr_fd("Ex: ./pipex file1 cmd1 cmd2 file2\n", 1);
		exit(EXIT_FAILURE);
	}
}
