#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*start;

	start = s;
	while (*s)
		s++;
	while (s >= start)
	{
		if (*s == c)
			return ((char *)s);
		s--;
	}
	return (NULL);
}
