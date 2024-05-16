#include <pipex.h>

typedef struct s_command {
	char		**cmd_args;
	const char	*env[];
}	t_command;

/* 
 * 	This funtion is not safe, 
	only works in simple strings 
*/
char	**ft_strsparse(char *str, char delimit, char open, char close)
{
	char	*tok = str;
	char	*ref = str;
	char	**block = malloc(sizeof(char *));

	int	insideBlock = 0;
	int	idx = 0;
	while (*tok)
	{
		if (insideBlock)
		{
			if (*tok++ == close)
				insideBlock = 0;
			continue ;
		}
		if (*tok == open)
		{
			insideBlock = 1;
			tok++;
			continue ;
		}
		if (*tok == delimit)
		{
			*tok++ = '\0';
			block = ft_realloc(block, sizeof(char *) * idx, sizeof(char *) * (idx + 1));
			block[idx++] = ft_strdup(ref);
			ref = tok;
			continue ;
		}
		tok++;
	}
	block = ft_realloc(block, sizeof(char *) * idx, sizeof(char *) * (idx + 2));
	block[idx] = ft_strdup(ref);
	block[idx + 1] = NULL;
	free(str);
	return (block);
}

char	**ft_parse_cmd(char *cmd, const char *path)
{
	char **parsed = ft_strsparse(cmd, ' ', '\'', '\'');
	char *c = ft_check_cmd(ft_strjoin("/", parsed[0]), path);
	if (c)
	{
		free(parsed[0]);
		parsed[0] = c;
	}
	return (parsed);
}

void	ft_run_piped(int fd[2], char **cmd, char *env[])
{
	int	pid;

	pid = fork();
	if (pid == -1)
	{
		ft_free_matrix(cmd);
		exit(1);
	}
	if (pid == 0)
	{
		dup2(fd[0], 0);
		dup2(fd[1], 1);
		execve(cmd[0], cmd, env);
		ft_free_matrix(cmd);
		exit(1);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid, NULL, 0);
	ft_free_matrix(cmd);
}

int	main(int ac, char *av[], char *envp[])
{
	char	*infile;
	char	*outfile;
	int		piped[2];
	int		input[2];

	ft_assert(ac-- == 5, "Usage: ./pipex infile <cmd1> <cmd2> outfile");
	ft_assert(access(av[1], F_OK | R_OK) == 0, strerror(errno));
	infile = av[1];
	outfile = av[ac];
	pipe(piped);
	int	infd = open(infile, O_RDONLY);
	int	outfd = open(outfile, O_RDWR | O_TRUNC | O_CREAT, 0644);

	input[0] = infd;
	input[1] = piped[1];
	char **cmd_0 = ft_parse_cmd(ft_strdup(av[2]), ft_get_path(envp));
	ft_run_piped(input, cmd_0, envp); 

	input[0] = piped[0];
	input[1] = outfd;
	char **cmd_1 = ft_parse_cmd(ft_strdup(av[3]), ft_get_path(envp));
	ft_run_piped(input, cmd_1, envp); 
}
