#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	while (len-- >= 0)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
