#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h> //for malloc, free, exit
# include <unistd.h> //for access, unlink, close, read, write, pipe, dup, dup2,execve (fork)
# include <string.h> //for strerror
# include <stdio.h> //for perror
# include <sys/wait.h> //for waitpid, wait
# include <fcntl.h> //for open
# include "../libft/libft.h"

/* Mandatory functions */
void	error(void);
char	*find_path(char *cmd, char **envp);
int		get_next_line(char **line);
void	execute(char *argv, char **envp);

#endif