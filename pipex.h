#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <libft.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>

# define HEREDOC_PATH "/tmp/rnoba-pipex-heredoc"

void		ft_free_matrix(char **m);

char		*ft_check_cmd(char *cmd, const char *path);

const char	*ft_get_path(char *env[]);
#endif
