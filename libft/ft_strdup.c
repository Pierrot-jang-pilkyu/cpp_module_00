#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		s_len;
	char	*buf;
	char	*dst;

	s_len = 0;
	while (s1[s_len])
		s_len++;
	dst = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!dst)
		return (NULL);
	buf = dst;
	while (*s1)
		*buf++ = *s1++;
	*buf = '\0';
	return (dst);
}
