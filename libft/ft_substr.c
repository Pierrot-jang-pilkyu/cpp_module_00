#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*buf;
	char	*sub;

	i = (s_len = 0);
	while (s[s_len])
		s_len++;
	sub = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!sub)
		return (NULL);
	if (start >= s_len)
		return (sub);
	buf = sub;
	while (s[start + i] && i < len)
	{
		*buf++ = s[start + i];
		i++;
	}
	*buf = '\0';
	return (sub);
}
