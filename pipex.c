#include <pipex.h>

size_t	ft_strlendel(char *str, char del)
{
	size_t	size;

	size = 0;
	while (str[size] && str[size] != del)
	{
		size++;
	}
	return (size);
}

typedef struct s_command {
	char		**cmd_args;
	const char	*env[];
}	t_command;


t_command	ft_parse_cmd(char *c, const char *path)
{
	t_command	cmd = {0};
	int			idx;
	int			c_idx;
	int			len;
	int			*consume;
	char		**tmp;
	char		**test;
	(void)path;

	tmp = ft_split(c, ' ');
	idx = 1;
	len = 0;
	consume = malloc(sizeof(int) * ft_arblen((void*)tmp));
	test = malloc(sizeof(char **) * ft_arblen((void*)tmp));
	(void)len;
	ft_bzero(consume, ft_arblen((void*)tmp) * sizeof(int));
	while (tmp[idx])
	{
		char *curr = tmp[idx - 1];
		char *next = tmp[idx];
		if (curr[0] == '\'' && next[ft_strlen(next)-1] == '\'')
		{
			consume[idx-1] = 1; 
			consume[idx] = 1; 
			len++;
			char *spc = ft_strjoin(" ", next);
			free(next);
			char *ac = ft_strjoin(curr, spc); 
			free(curr);
			free(spc);
			test[idx-len] = ac;
		}
		idx++;
	}
	c_idx = 0;
	int	fix = 0;
	int	real_idx;
	while (tmp[c_idx])
	{
		char *curr = tmp[c_idx];
		if (!consume[c_idx])
		{
			real_idx = c_idx - (fix / 2);
			if (real_idx == 0)
			{
				char *cmd = ft_check_cmd(ft_strjoin("/", curr), path);
				free(curr);
				test[real_idx] = cmd;
			}
			else
				test[real_idx] = curr;
			len++;
		}
		else
			fix++;
		c_idx++;
	}
	free(tmp);
	for(int i = 0; i < len; i ++)
	{
		printf("%s\n", test[i]);
	}
	return (cmd);
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
	printf("%d\n", pid);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid, NULL, 0);
}

int	main(int ac, char *av[], char *envp[])
{
	char	*infile;
	char	*outfile;
	ft_assert(ac-- == 5, "Usage: ./pipex infile <cmd1> <cmd2> outfile");
	ft_assert(access(av[1], F_OK | R_OK) == 0, strerror(errno));
	infile = av[1];
	infile = av[ac];
	(void)infile;
	(void)outfile;
	ft_parse_cmd(av[2], ft_get_path(envp));
}
