#include "libft.h"

size_t	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*t1;
	unsigned char	*t2;

	if (n == 0)
		return (0);
	i = 0;
	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	while (t1[i] && t2[i] && t1[i] == t2[i] && i + 1 < n)
		i++;
	return (t1[i] - t2[i]);
}
