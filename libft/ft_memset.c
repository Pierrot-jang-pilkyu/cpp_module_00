#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char		*tmp;
	size_t		i;

	tmp = (char *)b;
	i = 0;
	while (tmp[i] && i < len)
		tmp[i++] = (unsigned char)c;
	return ((void *)tmp);
}
