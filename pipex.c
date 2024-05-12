#include <pipex.h>


size_t	ft_strlendel(char *str, char del)
{
	size_t	size;

	size = 0;
	while (str[size] && str[size] != del)
	{
		size++;
	}
	return (size); }

size_t	ft_count_cmd(char *c)
{
	size_t	count;
	size_t	len;

	count = 0;
	while (c)
	{
		if (ft_isspace(*c))
			c++;
		len = ft_strlendel(c, ' ');
		if (c[0] == '\'')
			len = ft_strlendel(c + 1, '\'') + 2;
		if (len == 0)
			break ;
		count++;
		if (c[0] == '\'' && ft_strchr(c + 1, '\''))
			c = ft_strchr(c + 1, '\'') + 1;
		else
			c = ft_strchr(c + 1, ' ');
	}
	return (count);
}

char	**ft_parse_cmd(char *cmd, const char *path)
{
	char	*c;
	int		idx;
	size_t	len;
	char	**out;
	char	*full_cmd;

	c = cmd;
	idx = 0;
	out	= malloc(sizeof(char *) * (ft_count_cmd(cmd) + 1));
	while (c)
	{

		if (ft_isspace(*c))
			c++;
		len = ft_strlendel(c, ' ');
		if (c[0] == '\'')
			len = ft_strlendel(c + 1, '\'') + 2;
		if (len == 0)
			break ;
		out[idx] = malloc(sizeof(char) * len + 1);
		ft_bzero(out[idx], len + 1);
		ft_memcpy(out[idx], c, len);
		if (idx == 0)
		{
			full_cmd = ft_check_cmd(ft_strjoin("/", out[idx]), path);
			if (!full_cmd)
			{
				free(out[idx]);
				free(out);
				exit (0);
			}
			free(out[idx]);
			out[idx] = full_cmd; 
		}
		idx++;
		if (c[0] == '\'' && ft_strchr(c + 1, '\''))
			c = ft_strchr(c + 1, '\'') + 1;
		else
			c = ft_strchr(c + 1, ' ');
	}
	out[idx] = 0; return (out);
}

//void	ft_run_piped(int infd, int outfd, char **cmd)
//{
//	int		pid;
//	char	*full_cmd;
//
//	pid = fork();
//	if (pid == -1)
//	{
//		//free cmd
//		exit (0);
//	}
//	if (pid == 0)
//	{
//		full_cmd = ft_check_cmd(ft_strjoin("/", cmd[0]));
//		execve(full_cmd, cmd,
//				                    char *const _Nullable envp[]);
//	}
//	else
//	{
//	}
//	dup2(1, infd);
//}

int	main(int ac, char *av[], char *envp[])
{
	ft_assert(ac-- == 5, "Usage: ./pipex infile <cmd1> <cmd2> outfile");
	ft_assert(access(av[1], F_OK | R_OK) == 0, strerror(errno));
	char	*cmd_0 = av[2];
	char	*cmd_1 = av[3];
	const char	*path = ft_get_path(envp);
	char	**c1 = ft_parse_cmd(cmd_0, path);
	//char	**c2 = ft_parse_cmd(cmd_1);
	int idx = 0;
	while (c1[idx])
	{
		printf("%s\n", c1[idx]);
		free(c1[idx++]);
	}
	free(c1);
}
