#include <pipex.h>

void	ft_assert(int x, const char *error_msg)
{
	if (!x)
	{
		ft_putendl_fd((char *)error_msg, 2);
		exit(0);
	}
}

const char	*ft_get_path(char *env[])
{
	while (*env)
	{
		if (0 == ft_strncmp("PATH=", *env, 5))
			return (ft_strchr(*env, '=') + 1);
		env++;
	}
	return (NULL);
}

void	ft_free_matrix(char **m)
{
	size_t	idx;

	idx = 0;
	while (m[idx])
	{
		free(m[idx]);
		idx++;
	}
	free(m);
}

char	*ft_check_cmd(char *cmd, const char *path)
{
	char	**path_;
	char	**old_ptr;
	char	*full_cmd;

	path_ = ft_split(path, ':');
	ft_assert(path_ != NULL, "Error(split): (:()");
	old_ptr = path_;
	while (*path_)
	{
		full_cmd = ft_strjoin(*path_++, cmd);
		if (access(full_cmd, F_OK | X_OK) == 0)
		{
			free(cmd);
			ft_free_matrix(old_ptr);
			return (full_cmd);
		}
		free(full_cmd);
	}
	free(cmd);
	ft_free_matrix(old_ptr);
	return (NULL);
}
