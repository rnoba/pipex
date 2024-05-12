#ifndef PIPEX_H
# define PIPEX_H
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <libft.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

void		ft_assert(int x, const char *error_msg);
void		ft_free_matrix(char **m);
const char	*ft_get_path(char *env[]);
char	*ft_check_cmd(char *cmd, const char *path);
#endif
