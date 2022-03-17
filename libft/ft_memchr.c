#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	i = 0;
	tmp = (unsigned char *)s;
	while (tmp[i] && i < n)
	{
		if (tmp[i] == (unsigned char)c)
			return ((void *)(tmp + i));
		i++;
	}
	return (NULL);
}
