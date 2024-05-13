#include "./libft.h"

size_t	ft_arblen(void *i)
{
	size_t	max_it;
	size_t	idx;
	char	**c;

	max_it = INT_MAX;
	c = i;
	idx = 0;
	while (c[idx] && idx < max_it)
		idx++;
	return (idx);
}
