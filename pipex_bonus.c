#include <pipex.h>

typedef struct s_command {
	char		**cmd_args;
	const char	*env[];
}	t_command;

char	**ft_parse_cmd(char *cmd, const char *path)
{
	char	**parsed;
	char	*command;

	parsed = ft_strsparse(cmd, ' ', '\'', '\'');
	if (parsed[0][0] == '/' || (parsed[0][0] == '.' && parsed[1][0] == '/'))
	{
		if (access(parsed[0], F_OK | X_OK) == 0)
			return (parsed);
	}
	command = ft_check_cmd(ft_strjoin("/", parsed[0]), path);
	if (command)
	{
		free(parsed[0]);
		parsed[0] = command;
		return (parsed);
	}
	ft_free_matrix(parsed);
	ft_assert(0, strerror(errno));
	return (NULL);
}

int	ft_run_piped(int fd[2], char **cmd, char *env[])
{
	int	pid;
	int	status;

	pid = fork();
	if (pid == -1)
		return (0);
	if (pid == 0)
	{
		dup2(fd[0], 0);
		dup2(fd[1], 1);
		execve(cmd[0], cmd, env);
		return (0);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid, &status, 0);
	return (status);
}

int	ft_check_heredoc(char *input)
{
	if (0 == ft_strncmp(input, "here_doc", ft_max(ft_strlen(input), 8)))
		return (1);
	return (0);
}

void	ft_handle_heredoc(char *limiter)
{
	char	*line;
	int		fd;

	fd = open(HEREDOC_PATH, O_RDWR | O_APPEND | O_CREAT, 0644);
	ft_assert(fd != -1, "Error opening here_doc");
	while ((line = get_next_line(0)))
	{
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
			break ;
		write(fd, line, ft_strlen(line));
		free(line);
	}
	close(fd);
}

void	ft_run_side_cmd(char *str, char *envp[], int infd, int outfd)
{
	char	**cmd;
	int		input[2];

	input[0] = infd;
	input[1] = outfd;
	cmd = ft_parse_cmd(ft_strdup(str), ft_get_path(envp));
	ft_run_piped(input, cmd, envp);
	ft_free_matrix(cmd);
}

int	main(int ac, char *av[], char *envp[])
{
	int		piped[2];
	int		in_piped[2];
	int		infd;
	int 	idx;
	int		heredoc; 

	heredoc = ft_check_heredoc(av[1]);
	if (heredoc)
	{
		ft_assert(ac-- >= 6, "Usage: ./pipex here_doc LIMITER <cmd1> <cmd2> ... outfile");
		ft_handle_heredoc(av[2]);
		ft_assert(access(HEREDOC_PATH, F_OK | R_OK) == 0, strerror(errno));
		infd = open(HEREDOC_PATH, O_RDONLY);
		idx = 3;
	}
	else
	{
		ft_assert(ac-- >= 5, "Usage: ./pipex infile <cmd1> <cmd2> ... outfile");
		ft_assert(access(av[1], F_OK | R_OK) == 0, strerror(errno));
		infd = open(av[1], O_RDONLY);
		idx = 2;
	}
	pipe(piped);
	ft_run_side_cmd(av[idx++], envp, infd, piped[1]);
	while (idx < ac - 1)
	{
		//close(in_piped[0]);
		pipe(in_piped);
		ft_run_side_cmd(av[idx++], envp, piped[0], in_piped[1]);
		dup2(in_piped[0], piped[0]);
	}
	ft_run_side_cmd(av[ac - 1], envp, piped[0], 
		open(av[ac], O_RDWR | O_TRUNC | O_CREAT, 0644));
	unlink(HEREDOC_PATH);
	close(infd);
}
