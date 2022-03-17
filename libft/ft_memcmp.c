#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*t1;
	unsigned char	*t2;
	size_t			i;

	if (n == 0)
		return (0);
	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	i = 0;
	while (*t1 && *t2 && *t1 == *t2 && i + 1 < n)
	{
		t1++;
		t2++;
		i++;
	}
	return (*t1 - *t2);
}
